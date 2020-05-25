#pragma once
#include <list>
#include <map>
using namespace std;

class LRUCache {
public:
    list<int> order;
    list<int>::iterator tail;
    map<int, int> table;
    int size;

    void update_tail()
    {
        auto new_tail = prev(tail);
        table.erase(*tail);
        order.erase(tail);
        new_tail = tail;
    }

    LRUCache(int capacity)
    {
        size = capacity;
    }

    int get(int key) {

        update_tail();

        auto found = table.find(key);
        if (found == table.end()) return -1;
        return found->second;
    }

    void put(int key, int value) {

        if (order.size() < size) {
            if (order.empty())
                tail = order.insert( order.begin(), key );
            else
                order.insert(order.begin(), key);
            table[key] = value;
        }
        else
        {
            update_tail();
            order.insert(order.begin(), key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */