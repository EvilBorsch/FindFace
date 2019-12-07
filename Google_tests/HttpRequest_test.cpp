//
// Created by Dmitry Boldin on 08/11/2019.
//

#include "gtest/gtest.h"
#include <iostream>
#include "../HttpRequest/HttpRequest.cpp"


class HttpResponseTest : public ::testing::Test {
protected:
    void SetUp() {
        http_data = "GET /?var1=1&var2=string&var3=0.1 HTTP/1.1\n"
                                "Host: 127.0.0.1:5000\n"
                                "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\n"
                                "Upgrade-Insecure-Requests: 1\n"
                                "Cookie: csrftoken=PiJBMxa1zfWGOVgn92kjZ3zcLJOSywXPqEx2scDBp7kQk93AGZoDYt411YhCMQhM; sessionid=852x1dw8igpg6c29ctitnek1irxcd5ya\n"
                                "User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_14_6) AppleWebKit/605.1.15 (KHTML, like Gecko) Version/12.1.2 Safari/605.1.15\n"
                                "Accept-Language: en-us\n"
                                "Accept-Encoding: gzip, deflate\n"
                                "Connection: keep-alive";
    }
    std::string http_data;

    int var1 = 1;
    std::string var2 = "string";
    double var3 = 0.1;
};

TEST_F(HttpResponseTest, addHeadersTest) {
    HttpRequest request;

    request.addHeaders(http_data.c_str());

    std::map<std::string, any> get_data = request.GET();

    ASSERT_EQ(request.METHOD(), "GET");

    for(auto & it : get_data) {
        std::string key = it.first;

        if(key == "var1") {
            ASSERT_EQ(it.second.type, 'i') << key;
            ASSERT_EQ(it.second.i, var1) << key;
        } else if(key == "var2") {
            ASSERT_EQ(it.second.type, 's') << key;
            ASSERT_EQ(it.second.s, var2) << key;
        } else if(key == "var3") {
            ASSERT_EQ(it.second.type, 'd') << key;
            ASSERT_DOUBLE_EQ(it.second.d, var3) << key;
        } else FAIL() << key;
    }

}

TEST_F(HttpResponseTest, ParamsParserTest) {
    HttpParser parser;

    std::string args = "a=1&"
                       "abcd_very_long_name_of_a_variable___________=0.00001&"
                       "std_val="
                       "aaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbCCCCCCCCCC";
    parser.parseArgs(args, parser.get);
    for(auto & arg: parser.get) {
        std::string key = arg.first;

        if(key == "a") {
            ASSERT_EQ(arg.second.type, 'i') << key;
            ASSERT_EQ(arg.second.i, 1) << key;

        } else if(key == "abcd_very_long_name_of_a_variable___________") {
            ASSERT_EQ(arg.second.type, 'd') << key;
            ASSERT_DOUBLE_EQ(arg.second.d, 0.00001) << key;

        } else if(key == "std_val") {
            ASSERT_EQ(arg.second.type, 's') << key;
            ASSERT_EQ(arg.second.s,
                    "aaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbCCCCCCCCCC")
                    << key;

        } else FAIL() << key;
    }
}

TEST_F(HttpResponseTest, isNumberTest) {
    HttpParser parser;
//    String
    ASSERT_EQ(parser.isNumber("Это точно не число"), 0);
//    Double
    ASSERT_EQ(parser.isNumber("1.1"), 1);
    ASSERT_EQ(parser.isNumber(".0"), 2);
    ASSERT_EQ(parser.isNumber("0.01"), 1);
//    Integer
    ASSERT_EQ(parser.isNumber("1.0"), 2);
    ASSERT_EQ(parser.isNumber("1"), 2);

}
