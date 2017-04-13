#pragma once


#include <common/inline.hpp>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>
#include <cstdint>


namespace grip {


class Fiber
{
public:
    typedef void(*Callback)(void*);
    struct Job
    {
        Callback function;
        void*    parameter;
    };

    class FiberCallback
    {
    public:
        GRIP_INLINE FiberCallback(Fiber* pOwner)
            : m_IsRunning(false)
            , m_IsTerminated(false)
            , m_pOwnerFiber(pOwner)
            , m_pThread(nullptr)
        {
            m_pThread = new std::thread([=]() { ThreadLoop(this); });
        }

        GRIP_INLINE ~FiberCallback()
        {
            m_IsTerminated = true;
            m_pThread->join();
            delete m_pThread;
        }

        GRIP_INLINE void Execute()
        {
            if (m_IsRunning)
            {
                Job* pJob = m_pOwnerFiber->GetJob();
                while (pJob)
                {
                    pJob->function(pJob->parameter);
                    pJob = m_pOwnerFiber->GetJob();
                }
                m_IsRunning = false;
            }
        }

        GRIP_INLINE void BeStart() { m_IsRunning = true; }

        GRIP_INLINE bool IsBusy() const { return m_IsRunning; }
        
        GRIP_INLINE bool IsTerminated() const { return m_IsTerminated; }

    private:
        GRIP_INLINE static void ThreadLoop(FiberCallback* pFiber)
        {
            constexpr auto msec2 = std::chrono::milliseconds(2);
            while (!pFiber->IsTerminated())
            {
                std::this_thread::sleep_for(msec2);
                pFiber->Execute();
            }
        }

    private:
        bool         m_IsRunning;
        bool         m_IsTerminated;
        Fiber*       m_pOwnerFiber;
        std::thread* m_pThread;
    };

public:
    GRIP_INLINE Fiber(std::uint32_t threadCount, std::uint32_t jobCapacity)
        : m_Mutex()
        , m_pJobArray(nullptr)
        , m_apFiber(nullptr)
        , m_ThreadCount(threadCount)
        , m_JobPointer(0)
        , m_JobCapacity(jobCapacity)
    {
        m_pJobArray = new std::vector<Job>(m_JobCapacity);
        m_apFiber = new FiberCallback*[m_ThreadCount];
        for (std::uint32_t i = 0; i < m_ThreadCount; ++i)
        {
            m_apFiber[i] = new FiberCallback(this);
        }
    }

    GRIP_INLINE ~Fiber()
    {
        for (std::uint32_t i = 0; i < m_ThreadCount; ++i)
        {
            delete m_apFiber[i];
        }
        delete[] m_apFiber;
        delete m_pJobArray;
    }

    GRIP_INLINE void Execute()
    {
        for (std::uint32_t i = 0; i < m_ThreadCount; ++i)
        {
            m_apFiber[i]->BeStart();
        }

        constexpr auto msec2 = std::chrono::milliseconds(2);
        
        bool isBusy = true;
        while (isBusy)
        {
            std::this_thread::sleep_for(msec2);
            isBusy = false;
            for (std::uint32_t i = 0; i < m_ThreadCount; ++i)
            {
                isBusy = isBusy || m_apFiber[i]->IsBusy();
            }
        }

        m_pJobArray->clear();
        m_JobPointer = 0;
    }

    GRIP_INLINE void AddJob(const Job& job)
    {
        m_pJobArray->push_back(job);
    }


private:
    GRIP_INLINE Job* GetJob()
    {
        std::lock_guard<std::recursive_mutex> lock(m_Mutex);

        Job* pJob = nullptr;
        if (m_JobPointer < m_pJobArray->size())
        {
            pJob = &(*m_pJobArray)[m_JobPointer++];
        }
        return pJob;
    }

private:
    std::recursive_mutex m_Mutex;
    std::vector<Job>*    m_pJobArray;
    FiberCallback**      m_apFiber;
    std::uint32_t        m_ThreadCount;
    std::uint32_t        m_JobPointer;
    std::uint32_t        m_JobCapacity;
};


}

