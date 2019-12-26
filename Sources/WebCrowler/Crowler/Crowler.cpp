#pragma once
#include "Crowler.h"
#include <iostream>
#include <utility>
#include <sstream>
#include "DataBase/Base/BaseComporator.h"
#include "DataBase/Base/BaseMetrificator.h"
#include "PythonMagic.h"




Crowler::Crowler(std::shared_ptr <AbstractAPI> m_api, std::shared_ptr <AbstractIdListGeneratorStrategy> m_lg,
                 DB *m_db) {
    api = std::move(m_api);
    lg = std::move(m_lg);
    db = m_db;
}


void Crowler::startCrowl() {
    t = new std::thread(std::bind(&Crowler::crowl, this));

}

void Crowler::stopCrowl() {
    thread_must_end = true;
    t->join();
}

void Crowler::crowl() {
    int i = 0;
    while (true) {
        std::vector <url> id_list = lg->generate();
        for (auto &id: id_list) {
            std::vector <url> photoUrls = api->getPhotoUrlsById(id);
            for (auto &data: photoUrls) {

                for(auto &vec : getFacesVector(data.toStr())){
                    BaseComporator cmp = BaseComporator();
                    BaseMetrificator mth = BaseMetrificator();

                    db->add(vec, id.toStr(),&cmp);
                }

                std::cout << data.toStr() <<" ____ "<<id.toStr()<< std::endl;
            }
        }

        lg->save();
        if (thread_must_end) break;

    }

}


std::vector<std::vector<double>> Crowler::getFacesVector(std::string link) {
    char buffer[128];
    std::string cmd = "python3 python_magic.py " + link;
    std::string result = "";
    FILE* pipe = popen(cmd.c_str(), "r");
    if (!pipe) throw std::runtime_error("popen() failed!");
    try {
        while (fgets(buffer, sizeof buffer, pipe) != NULL) {
            result += buffer;
        }
    } catch (...) {
        pclose(pipe);
        throw;
    }
    pclose(pipe);
    std::stringstream output(result);
    int n;
    output >> n;
    //std::cout << n;
    std::vector<std::vector<double>> faces;
    std::vector<double> tmp_vector;
    std::string num;
    while(output >> num) {
        if(num[0] == '[') {
            tmp_vector.clear();
            num.erase(num.begin());
        } else if(num.back() == ']'){
            num.pop_back();
            if(!num.empty()) {
                //std::cout << num;
                tmp_vector.push_back(std::stod(num));
            }
            faces.push_back(tmp_vector);
            continue;
        }
        if(!num.empty()) {
           // std::cout << num;
            tmp_vector.push_back(std::stod(num));
        }
    }
    return faces;
}
