#include <fstream>
#include "Facebook_id_list_generator_strategy.h"


std::vector<url> FacebookIdListGeneratorStrategy::generate() {
    url mUrl;
    std::vector<url> vec;
    for (size_t i = currentId + 1; i < currentId + 1 + size; i++) {

        mUrl.facebookStyleId(std::to_string(i));
        vec.push_back(mUrl);

    }

    return vec;

}

size_t FacebookIdListGeneratorStrategy::getCurrentID() {
    std::ifstream fin(path);
    fin >> currentId;
    return currentId;

}

void FacebookIdListGeneratorStrategy::save() {
    std::ofstream fout(path);
    currentId += size;
    fout << currentId;
}

