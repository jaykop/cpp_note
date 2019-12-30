class Solution {
public:
    
    vector<int> convert(const string& s){
        
        // size of the s
        int size = int(s.size());
        // converted to number
        vector<int> output;
        // number table to record the appearance of word
        map<char, int> table;
        // id 
        int unique_number = 0;
        for (int i = 0 ; i < size; i++) {
            char c = s[i];
            if (table.find(c) == table.end()) // never appeared before,
                table[c] = unique_number++; // add an id
            output.push_back(table[c]); // add the id to the vector
        }
        
        return output;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string> output; // actual output
        auto target = convert(pattern); // coverted id vector of given pattern
        
        // iterate thru the words
        for (const auto w : words) {
            
            // if found the same pattern as the target,
            if (target == convert(w))
                output.push_back(w); // add to the output vector
        }
        
        return output;
    }
};