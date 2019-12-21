#include "Vk_id_list_generator_strategy.h"
#include <fstream>

std::vector<url> VkIdListGeneratorStrategy::generate() {

    url mUrl;
    std::vector<url> vec;
    for (size_t i = currentId + 1; i < currentId + 1 + size; i++) {

        mUrl.vkStyleId(std::to_string(i));
        vec.push_back(mUrl);

    }

    return vec;
}

size_t VkIdListGeneratorStrategy::getCurrentId() {
    std::ifstream fin(path);
    fin >> currentId;
    return currentId;
}

void VkIdListGeneratorStrategy::save() { //TODO этот метод должен взаимодействовать с БД (использовать метод Александра)
    std::ofstream fout(path);
    currentId += size;
    fout << currentId;


}









