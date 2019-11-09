#include "Crowler.h"
#include <iostream>
#include <unistd.h>

#define stop_state 2


Container Crowler::get_container_from_urls(const vector<string> &urls) {
    return Container();
}


Crowler::Crowler(AbstractAPI *m_api, Abstract_id_list_generator_strategy *m_lg, int *m_fd) {
    api = m_api;
    lg = m_lg;
    fd = m_fd;
}

void add(Container cont) {

}

void Crowler::start_crowl() {

    int *buf = new int[1];
    read(fd[0], buf, sizeof(buf));
    while (buf[0] != stop_state) {
        read(fd[0], buf, sizeof(buf));
        id_list = lg->generate();
        for (const auto &id: id_list) {
            vector<string> photo_urls = api->get_photo_urls_by_id(id);
            Container cont = get_container_from_urls(photo_urls);
            add(cont);
        }
    }

}

void Crowler::stop_crowl_and_save_id_list() {

    int *testbuf = new int[1];
    testbuf[0] = stop_state;
    write(fd[1], testbuf, sizeof(testbuf));

}





