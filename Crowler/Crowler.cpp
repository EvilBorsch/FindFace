#include "Crowler.h"
#include <iostream>
#include <unistd.h>


Container Crowler::get_container_from_urls(const std::vector<url> &urls) {
    return {};
}


Crowler::Crowler(AbstractAPI *m_api, AbstractIdListGeneratorStrategy *m_lg, int *m_fd) {
    api = m_api;
    lg = m_lg;
    fd = m_fd;
}

void add(Container cont) {

}

void Crowler::startCrowl() {

    int *buf = new int[1];
    read(fd[0], buf, sizeof(buf));
    while (buf[0] != stop_state) {
        read(fd[0], buf, sizeof(buf));
        id_list = lg->generate();
        for (const auto &id: id_list) {
            std::vector<url> photo_urls = api->getPhotoUrlsById(id);
            Container cont = get_container_from_urls(photo_urls);
            add(cont);
        }
    }

}

void Crowler::stopCrowlAndSaveIdList() {

    int *testbuf = new int[1];
    testbuf[0] = stop_state;
    write(fd[1], testbuf, sizeof(testbuf));

}





