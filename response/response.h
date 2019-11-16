#include <map>


class response {
private:
    std::map<std::string, std::string> mp;
public:
    void parse(const std::string &st) {}

    std::string get_body() {
        return {};
    }
};
