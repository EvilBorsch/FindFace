#include <vector>
#include <string>
#include <iostream>
#pragma once

using std::vector,std::string;
class Abstract_id_list_generator_strategy{
private:

public:
    virtual vector<string> generate()=0;
    virtual ~Abstract_id_list_generator_strategy()= default;

    vector<string> load_urls_from_disk(string path) {
        return vector<string>();
    };
};