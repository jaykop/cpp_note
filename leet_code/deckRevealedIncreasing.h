#pragma once
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {

        int size = int(deck.size());

        // sort the deck
        sort(deck.begin(), deck.end(), std::greater<int>());
        vector<int> new_deck(size, 0);
        for (int i = 0; i < size; i++) {
            new_deck[size - i - 1] = deck[i]; // push front
            if (size - i - 2 < 0) break;
            new_deck[size - i - 2] = new_deck[size - 1]; // move forawrd
            for (int j = size - 2; j >= 0; j--) {
                new_deck[j+1] = new_deck[j];
            }
        }
        return new_deck;
    }
};

// think about the fx
// pop_front()
// move_end();
// pop_front()
// move_end();
// ...
// =>
// move_head()
// push_front()
// move_head()
// push_front()
// ...