//
// Created by Dmitry Boldin on 08/11/2019.
//

#ifndef BACKEND_HTTPREQUEST_H
#define BACKEND_HTTPREQUEST_H

#include <map>
#include <utility>
#include "iostream"

class NoValueFound : public std::exception {
public:
    explicit NoValueFound(std::string msg) : m_message(std::move(msg)) {}
    const char * what () const noexcept override {
        return m_message.c_str();
    }
private:
    std::string m_message;
};

struct URL{
    std::string raw;
    std::string protocol;
    std::string path;
    std::string query_string;
};

struct any{
    int i{};
    std::string s{};
    double d{};
    char type;
    explicit any(int t): i(t), type('i'){};
    explicit any(double t): d(t), type('d'){};
    explicit any(std::string t): s(std::move(t)), type('s'){};
    void* data() {
        if(type == 'i') return &i;
        if(type == 'd') return &d;
        if(type == 's') return &s;
        return nullptr;
    }
};

class HttpParser {
public:
    void parsePostParams();
    void parseGetParams();
    void parseRequest();

    void parseArgs(std::string const & query_string,
                   std::map<std::string, any>& params_map);

    std::vector<std::string> split(const std::string& s, char delimiter);

    std::map<std::string, any> get;
    std::map<std::string, any> post;
    std::map<std::string, std::string> files;

    std::map<std::string, std::string> headers;

    std::string method;
    struct URL url;
    std::string content_type;

    static int isNumber(const std::string& s);
};

class HttpRequest : private HttpParser{
public:
    HttpRequest() = default;
    ~HttpRequest() = default;

    int addHeaders(const char*);

    any GET_search(const std::string& key);

    std::map<std::string, any> GET() { return get;};
    std::map<std::string, any> POST() { return post;};
    std::map<std::string, std::string> FILES() { return files;};
    std::map<std::string, std::string> HEADERS() { return headers;};
    std::string METHOD() { return method;};

    struct URL URL() { return url;};

    std::string get_content_type() { return content_type;};
    static int isNumber(const std::string& s);
};


#endif //BACKEND_HTTPREQUEST_H
