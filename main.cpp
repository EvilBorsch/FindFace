#include <iostream>
#include "Server.h"
#include "LRU.h"
#include "HttpRequest.cpp"

int main() {
    std::string a;
    a = "GET /?var1=1&var2=string HTTP/1.1\n"
        "Host: 127.0.0.1:5000\n"
        "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\n"
        "Upgrade-Insecure-Requests: 1\n"
        "Cookie: csrftoken=PiJBMxa1zfWGOVgn92kjZ3zcLJOSywXPqEx2scDBp7kQk93AGZoDYt411YhCMQhM; sessionid=852x1dw8igpg6c29ctitnek1irxcd5ya\n"
        "User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_14_6) AppleWebKit/605.1.15 (KHTML, like Gecko) Version/12.1.2 Safari/605.1.15\n"
        "Accept-Language: en-us\n"
        "Accept-Encoding: gzip, deflate\n"
        "Connection: keep-alive";
    HttpRequest h;
    h.add_data(a);
    std::map<std::string, std::string> get_data = h.GET();
    std::map<std::string, std::string>::const_iterator pos = get_data.find("var3");

    for(auto & it : get_data) {
        std::cout << it.first << " ";
    }
    std::cout << std::endl;
    if (pos == get_data.end()) {
        std::cout << "ERROR!";
    } else {
        std::string value = pos->second;
        std::cout << value;
    }
    return 0;
}