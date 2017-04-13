
#include <grip.hpp>

#include <spdlog/spdlog.h>



int main(int argc, char** argv)
{
#ifdef SPDLOG_ENABLE_SYSLOG 
    std::string ident = "spdlog-example";
    auto syslog_logger = spd::syslog_logger("syslog", ident, LOG_PID);
    syslog_logger->warn("This is warning that will end up in syslog..");
#endif

	return 0;
}
