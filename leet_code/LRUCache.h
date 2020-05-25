#pragma once
#include <list>
#include <map>
using namespace std;
class LRUCache {
public:

    list<int> order;
    map<int, int> table;
    list<int>::iterator tail;
    int size;

    void update_tail(int key)
    {
        if (order.size() > 1)
        {
            for (auto it = order.begin(); it != order.end(); it++)
            {
                if (*it == key)
                {
                    if (it == tail)
                    {
                        auto new_tail = prev(tail);
                        table.erase(*tail);
                        order.erase(tail);
                        tail = new_tail;
                    }
                    else
                    {
                        order.erase(it);
                    }
                    break;
                }
            }
        }
    }

    LRUCache(int capacity) {
        size = capacity;
    }

    int get(int key) {

        auto found = table.find(key);
        if (found == table.end())
            return -1;

        update_tail(key);

        // cycle to the front
        order.insert(order.begin(), key);
        return found->second;
    }

    void put(int key, int value) {

        if (order.empty())
            tail = order.insert(order.begin(), key);
        else
        {
            if (order.size() < size)
            {
                update_tail(key);
                order.insert(order.begin(), key);
            }
        }

        table[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */