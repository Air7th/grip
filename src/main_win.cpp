
#include <tchar.h>
#include <Windows.h>
#include <string>
#include <sstream>

#include <grip.hpp>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/msvc_sink.h>


#define UNUSED(x)


int APIENTRY _tWinMain(
	HINSTANCE UNUSED(hInstance),
	HINSTANCE UNUSED(hPrevInstance),
	LPTSTR    UNUSED(lpCmdLine),
	int       UNUSED(nCmdShow)
)
{
	using namespace std;

	auto sink = std::make_shared<spdlog::sinks::msvc_sink_mt>();
	auto log = spdlog::create("grip", sink);

	log->info("Hello! Grip! ... {} \n", grip::function());

	return 0;
}
