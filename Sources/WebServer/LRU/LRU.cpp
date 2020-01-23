//
// Created by Dmitry Boldin on 08/11/2019.
//

#include "LRU.h"

Node *DoublyLinkedList::add_page_to_head(int key, int value) {
    Node *page = new Node(key, value);
    if(!front && !rear) {
        front = rear = page;
    }
    else {
        page->next = front;
        front->prev = page;
        front = page;
    }
    return page;
}

void DoublyLinkedList::move_page_to_head(Node *page)  {
    if(page==front) {
        return;
    }
    if(page == rear) {
        rear = rear->prev;
        rear->next = nullptr;
    }
    else {
        page->prev->next = page->next;
        page->next->prev = page->prev;
    }

    page->next = front;
    page->prev = nullptr;
    front->prev = page;
    front = page;
}

void DoublyLinkedList::remove_rear_page() {
    if(isEmpty()) {
        return;
    }
    if(front == rear) {
        delete rear;
        front = rear = nullptr;
    }
    else {
        Node *temp = rear;
        rear = rear->prev;
        rear->next = nullptr;
        delete temp;
    }
}

Node *DoublyLinkedList::get_rear_page() {
    return rear;
}

LRUCache::LRUCache(int capacity) {
    this->capacity = capacity;
    size = 0;
    pageList = new DoublyLinkedList();
    pageMap = map<int, Node*>();
}

int LRUCache::get(int key) {
    if(pageMap.find(key) == pageMap.end()) {
        return -1;
    }
    int val = pageMap[key]->value;

    // move the page to front
    pageList->move_page_to_head(pageMap[key]);
    return val;
}

void LRUCache::put(int key, int value) {
    if(pageMap.find(key)!=pageMap.end()) {
        // if key already present, update value and move page to head
        pageMap[key]->value = value;
        pageList->move_page_to_head(pageMap[key]);
        return;
    }

    if(size == capacity) {
        // remove rear page
        int k = pageList->get_rear_page()->key;
        pageMap.erase(k);
        pageList->remove_rear_page();
        size--;
    }

    // add new page to head to Queue
    Node *page = pageList->add_page_to_head(key, value);
    size++;
    pageMap[key] = page;
}

LRUCache::~LRUCache() {
    map<int, Node*>::iterator i1;
    for(i1=pageMap.begin();i1!=pageMap.end();i1++) {
        delete i1->second;
    }
    delete pageList;
}


