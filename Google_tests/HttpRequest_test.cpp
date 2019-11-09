//
// Created by Dmitry Boldin on 08/11/2019.
//

#include "gtest/gtest.h"
#include <iostream>
#include "../HttpRequest.cpp"




class HttpRequestTest : public ::testing::Test
{
protected:
    void SetUp() {
        http_request = new HttpRequest;
        std::string http_data = "GET /?var1=1&var2=string&var3=0.1 HTTP/1.1\n"
                                "Host: 127.0.0.1:5000\n"
                                "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\n"
                                "Upgrade-Insecure-Requests: 1\n"
                                "Cookie: csrftoken=PiJBMxa1zfWGOVgn92kjZ3zcLJOSywXPqEx2scDBp7kQk93AGZoDYt411YhCMQhM; sessionid=852x1dw8igpg6c29ctitnek1irxcd5ya\n"
                                "User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_14_6) AppleWebKit/605.1.15 (KHTML, like Gecko) Version/12.1.2 Safari/605.1.15\n"
                                "Accept-Language: en-us\n"
                                "Accept-Encoding: gzip, deflate\n"
                                "Connection: keep-alive";
    }
    void TearDown()
    {
        delete http_request;
    }
    HttpRequest *http_request;
    std::string request_data;
};

TEST_F(HttpRequestTest, test1)
{
    http_request->add_data(request_data);

    std::map<std::string, std::string> get_data = http_request->GET();

    for(auto & it : get_data) {
        std::string key = it.first;
        std::string val;
        int n;

        if(key == "var1") {
            val = get_data.at(key);
            n = val.length();
            char val_char[n+1];
            strcpy(val_char, val.c_str());
            char expected_value[] = {'1', '\0'};
            ASSERT_STREQ(expected_value, val_char) << key;
        } else if(key == "var2") {
            val = get_data.at(key);
            n = val.length();
            char val_char[n+1];
            strcpy(val_char, val.c_str());
            char expected_value[] = {'s', 't', 'r', 'i', 'n', 'g', '\0'};
            ASSERT_STREQ(expected_value, val_char) << key;
        } else if(key == "var3") {
            val = get_data.at(key);
            n = val.length();
            char val_char[n+1];
            strcpy(val_char, val.c_str());
            char expected_value[] = {'0', '.', '1', '\0'};
            ASSERT_STREQ(expected_value, val_char) << key;
        } else FAIL() << key;
    }
}
