#include "Crowler.h"
#include <iostream>
#include <unistd.h>


Container Crowler::getContainerFromUrls(const std::vector<url> &urls) {
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
    while (buf[0] != stopState) {
        read(fd[0], buf, sizeof(buf));
        id_list = lg->generate();
        for (const auto &id: id_list) {
            std::vector<url> photoUrls = api->getPhotoUrlsById(id);
            Container cont = getContainerFromUrls(photoUrls);
            add(cont);
        }
    }

}

void Crowler::stopCrowlAndSaveIdList() {

    int *testbuf = new int[1];
    testbuf[0] = stopState;
    write(fd[1], testbuf, sizeof(testbuf));

}





