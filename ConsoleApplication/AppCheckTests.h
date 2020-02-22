#ifndef _APP_CHECK_TESTS_
#define _APP_CHECK_TESTS_

#include <string>

class AppCheckTests
{
public:
	static bool http_get_string(std::string url, std::string needle);
	static bool tcp_check_port(int port, std::string protocol);

private:
	AppCheckTests() {}

	static size_t write_data(void* ptr, size_t size, size_t nmemb, void* stream);
};

#endif