//
// Created by Dmitry Boldin on 08/11/2019.
//

#include "gtest/gtest.h"
#include <iostream>
#include "../HttpResponse.cpp"


class HttpResponseTest : public ::testing::Test {
protected:
    void SetUp() {
        std::string response_data = R"({"status": "ok"})";
        http_response = new HttpResponse(response_data);
    }
    void TearDown() {
        delete http_response;
    }
    HttpResponse *http_response;
    std::string request_data;
};

TEST_F(HttpResponseTest, serialize_ok) {
    std::string serialized_response = http_response->serialize();
    std::string expected_response = "Request URL: https://some_site.ru/find\n"
                                    "Request Method: GET\n"
                                    "Status Code: 200 OK\n"
                                    "Remote Address: 80.93.182.49:443\n"
                                    "Referrer Policy: no-referrer-when-downgrade"
                                    "Allow: GET, HEAD, OPTIONS\n"
                                    "Connection: keep-alive\n"
                                    "Content-Encoding: gzip\n"
                                    "Content-Type: text/html; charset=utf-8\n"
                                    "Date: Fri, 08 Nov 2019 21:34:57 GMT\n"
                                    "Server: FindFace\n"
                                    "Transfer-Encoding: chunked\n"
                                    "Vary: Accept, Cookie\n"
                                    "X-Frame-Options: SAMEORIGIN";
    ASSERT_EQ(expected_response, serialized_response);
}

class HttpResponseBaseTest : public ::testing::Test {
protected:
    void SetUp() {
        http_response = new HttpResponseBase(200);
    }
    void TearDown() {
        delete http_response;
    }
    HttpResponseBase *http_response;
};

TEST_F(HttpResponseBaseTest, can_edit_headers) {
    http_response->_set_header("Server", "FindFace");

    std::map<std::string, std::string>::const_iterator pos = http_response->headers.find("Server");

    if (pos != http_response->headers.end())
        FAIL();
    SUCCEED();
}
