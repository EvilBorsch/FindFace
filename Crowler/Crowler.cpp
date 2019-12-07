#include "Crowler.h"
#include <iostream>
#include <utility>


std::atomic<bool> thread_must_end(false);


void addToBd(const std::vector<double> &vec, const std::string &url) {} //Функция из библиотеки александра





Crowler::Crowler(std::shared_ptr<AbstractAPI> m_api, std::shared_ptr<AbstractIdListGeneratorStrategy> m_lg) {
    api = std::move(m_api);
    lg = std::move(m_lg);
};


void Crowler::startCrowl() {
    t = new std::thread(std::bind(&Crowler::crowl, this));

}

void Crowler::stopCrowl() {
    thread_must_end.store(true);

}


const std::vector<double> &vectorize(const std::string &url) { //Функция из библиотеки Димы
    return {};
}

void Crowler::crowl() {

    while (true) {

        std::vector<url> id_list = lg->generate();
        for (const auto &id: id_list) {
            std::vector<url> photoUrls = api->getPhotoUrlsById(id);
            for (auto &data: photoUrls) {
                addToBd(vectorize(data.toStr()), data.toStr());
                std::cout<< data.toStr() << std::endl;
            }
        }
        lg->save();
        if (thread_must_end.load()) break;

    }

}

