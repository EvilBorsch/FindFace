//
// Created by Dmitry Boldin on 08/11/2019.
//

#ifndef BACKEND_HTTPREQUEST_H
#define BACKEND_HTTPREQUEST_H

#include <map>
#include <utility>
#include "iostream"

class NoValueFoundException : public std::exception {
public:
    explicit NoValueFoundException(std::string msg) : m_message(std::move(msg)) {}
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

struct Any{
    int i{};
    std::string s{};
    double d{};
    char type;
    explicit Any(int t): i(t), type('i'){};
    explicit Any(double t): d(t), type('d'){};
    explicit Any(std::string t): s(std::move(t)), type('s'){};
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
    void parseGetParams(const std::string& get_params);
    void parseRequest();

    void parseArgs(std::string const & query_string,
                   std::map<std::string, Any>& params_map);

    std::vector<std::string> split(const std::string& s, char delimiter);

    std::map<std::string, Any> get;
    std::map<std::string, Any> post;
    std::map<std::string, std::string> files;

    std::map<std::string, std::string> headers;

    std::string method;
    struct URL url;
    std::string content_type;

    static int isNumber(const std::string& s);
    bool noErrors = true;
};

class HttpRequest : private HttpParser{
private:
    int parseAllHeaders(std::vector<std::string> headers_vector,
                        int headers_size);

public:
    HttpRequest() = default;
    ~HttpRequest() = default;

    int addHeaders(const char*);

    Any GET_search(const std::string& key);

    std::map<std::string, Any> GET() { return get;};
    std::map<std::string, Any> POST() { return post;};
    std::map<std::string, std::string> FILES() { return files;};
    std::map<std::string, std::string> HEADERS() { return headers;};
    std::string METHOD() { return method;};

    struct URL URL() { return url;};

    std::string get_content_type() { return content_type;};
    static int isNumber(const std::string& s);

    bool noParsingErrors() { return noErrors; };
};


#endif //BACKEND_HTTPREQUEST_H
