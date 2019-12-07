#include "NetService.h"
#include <curl/curl.h>


static size_t write_data(char *ptr, size_t size, size_t nmemb, std::string *data) {
    if (data) {
        data->append(ptr, size * nmemb);
        return size * nmemb;
    } else
        return 0;
}


response NetService::request(url mUrl) {
    CURL *curl_handle;
    curl_handle = curl_easy_init();
    std::string strUrl = mUrl.toStr();
    std::string content = "";
    if (curl_handle) {
        curl_easy_setopt(curl_handle, CURLOPT_URL,
                         strUrl.c_str());

        curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, &content);

        CURLcode res = curl_easy_perform(curl_handle);
        if (res != CURLE_OK) {
            throw "No internet connection";
        }

        curl_easy_cleanup(curl_handle);
    }
    return response(content);
}
