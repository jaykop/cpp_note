#pragma once
#include <list>
#include <map>
#include <deque>

using namespace std; 
class LRUCache {
public:

    deque<int> order;
    map<int, int> table;
    int size;

    LRUCache(int capacity) {
        size = capacity;
    }

    int get(int key) {

        auto found = table.find(key);

        // no such key
        if (found == table.end()) return -1;

        int to_front_val = found->second;

        if (order.size() > 1)
        {
            // update the order
            for (auto it = order.begin(); it != order.end(); it++)
            {
                if (*it == key)
                {
                    order.erase(it);
                    break;
                }
            }
            order.push_front(key);
        }

        // found valid value
        return to_front_val;
    }

    void put(int key, int value) {

        // add as usual
        if (order.size() < size)
        {
            // search existing key
            auto found = table.find(key);

            if (found != table.end())
            {
                for (auto it = order.begin(); it != order.end(); it++)
                {
                    if (*it == key)
                    {
                        order.erase(it);
                        break;
                    }
                }
            }
            order.push_front(key);
        }

        else
        {
            // search existing key
            auto found = table.find(key);

            // no such key
            if (found == table.end())
            {
                table.erase(order.back()); // remove the key
                order.pop_back(); // remove the last element
            }

            else
            {
                for (auto it = order.begin(); it != order.end(); it++)
                {
                    if (*it == key)
                    {
                        order.erase(it);
                        break;
                    }
                }
            }
            order.push_front(key);
        }
        table[key] = value;

        //if (table.size() != order.size())
        //{
        //    std::cout << "key: " << key;
        //    std::cout << "value: " << value;
        //}
    }
};