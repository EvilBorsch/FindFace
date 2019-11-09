//
// Created by Dmitry Boldin on 08/11/2019.
//

#ifndef BACKEND_LRU_H
#define BACKEND_LRU_H


#include <utility>
#include <vector>
#include <map>

class Node {
public:
    std::string key;
    std::vector<std::string> val;
    Node *prev, *next;
    Node(std::string k, std::vector<std::string> v):
    key(std::move(k)), val(std::move(v)), prev(NULL), next(NULL) {}
};


class DoublyLinkedList{
public:
    void add_page_to_head(std::string key, std::vector<std::string>);
    void move_page_to_head(Node* page);
    Node* add_page_to_head(int key, int value);
    void remove_rear_page();
private:
    Node* front, rear;
};

class LRU {
public:
LRU(int capacity);
std::vector<std::string> get(std::string key);
void put(std::string key, std::vector<std::string> value);

private:
    int capacity, size;
    DoublyLinkedList *pageList;
    std::map<int, Node*> pageMap;
};


#endif //BACKEND_LRU_H
