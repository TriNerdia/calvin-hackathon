#include "AppCheckTests.h"
#include <iostream>
#include <curl/curl.h>

bool AppCheckTests::http_get_string(std::string url, std::string needle)
{
	bool result = false;
	std::string readBuffer;
	CURLcode response;

	CURL* curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, AppCheckTests::write_data);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
		response = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}

	if (CURLE_OK == response) {
		if (std::string::npos != readBuffer.find(needle)) {
			result = true;
		}
	}

	return result;
}

bool AppCheckTests::check_port(std::string domain, long port)
{
	bool result = false;
	std::string url = "telnet://" + domain;
	CURLcode response;

	CURL* curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_PROTOCOLS, CURLPROTO_TELNET);
		curl_easy_setopt(curl, CURLOPT_PORT, port);
		//curl_easy_setopt(curl, CURLOPT_TIMEOUT, 1L);
		//curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 1L);
		
		response = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}

	if (CURLE_OK == response) {
		result = true;
	}

	return result;
}

size_t AppCheckTests::write_data(void* contents, size_t size, size_t nmemb, void* userp)
{
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}
