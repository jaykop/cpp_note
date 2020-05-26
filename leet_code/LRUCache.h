#pragma once
#include <unordered_map>
#include <deque>

using namespace std; 
//class LRUCache {
//public:
//    LRUCache(int capacity) : _capacity(capacity) {}
//
//    int get(int key) {
//        auto it = cache.find(key);
//        if (it == cache.end()) return -1;
//        touch(it);
//        return it->second.first;
//    }
//
//    void put(int key, int value) {
//        auto it = cache.find(key);
//        if (it != cache.end()) touch(it);
//        else {
//            if (cache.size() == _capacity) {
//                cache.erase(used.back());
//                used.pop_back();
//            }
//            used.push_front(key);
//        }
//        cache[key] = { value, used.begin() };
//    }
//
//private:
//    typedef list<int> LI;
//    typedef pair<int, LI::iterator> PII;
//    typedef unordered_map<int, PII> HIPII;
//
//    void touch(HIPII::iterator it) {
//        int key = it->first;
//        used.erase(it->second.second);
//        used.push_front(key);
//        it->second.second = used.begin();
//    }
//
//    HIPII cache;
//    LI used;
//    int _capacity;
//};

class LRUCache {
public:

    LRUCache(int capacity) : size(capacity) {}

    int get(int key) {

        auto found = table.find(key);
        if (found == table.end()) return -1;

        order.erase(table[key].second);
        order.push_front(key);
        Pair p = { table[key].first, order.begin() };
        table[key] = p;
        return table[key].first;
    }

    void put(int key, int value) {

        // add as usual
        if (order.size() < size)
        {
            auto found = table.find(key);

            // found such key, erase the existing iterator(key)
            if (found != table.end())
                order.erase(table[key].second);
            
            order.push_front(key);
            Pair p = { value, order.begin() };
            table[key] = p;
        }

        else
        {
            auto found = table.find(key);

            // found such key, erase the existing iterator(key)
            if (found != table.end())
                order.erase(table[key].second);

            else
            {
                table.erase(order.back());
                order.pop_back();
            }

            order.push_front(key);
            Pair p = { value, order.begin() };
            table[key] = p;
        }
    }

private:
    list<int> order;
    using Pair = pair<int, list<int>::iterator>;
    unordered_map<int, Pair> table; // key, (value, iterator)
    int size;

};