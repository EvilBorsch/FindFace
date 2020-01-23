#include <iostream>
#include <map>
using namespace std;

class Node {
public:
    int key, value;
    Node *prev, *next;
    Node(int k, int v): key(k), value(v), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
    Node *front, *rear;

    bool isEmpty() {
        return rear == nullptr;
    }

public:
    DoublyLinkedList(): front(nullptr), rear(nullptr) {}

    Node* add_page_to_head(int key, int value);

    void move_page_to_head(Node *page);

    void remove_rear_page();
    Node* get_rear_page();
};

class LRUCache{
    int capacity, size;
    DoublyLinkedList *pageList;
    map<int, Node*> pageMap;

public:
    LRUCache(int capacity);

    int get(int key);

    void put(int key, int value);

    ~LRUCache();
};