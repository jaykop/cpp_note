#pragma once
#include <string>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    bool is_number(const std::string& s) {
        return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
    }

    void recursive(TreeNode* t, string& S, string line, int depth)
    {
        int pos = S.find(line);
        int end = string::npos;
        while (pos != end)
        {
            if ((!pos || S[pos - 1] != '-' )&& S[pos + depth] != '-')
            {
                if (t->left && t->right)
                    break;

                int len = 1;
                while (pos + depth + len <= S.length() && S[pos + depth + len] != '-')
                    len++;

                string number = S.substr(pos + depth, len);
                int n = 0;
                
                if (is_number(number)) {

                    n = stoi(number);
                    if (!t->left)
                    {
                        int offset = 0;
                        while (pos + depth - offset - 1 >= 0 && S[pos + depth - offset - 1] == '-')
                            offset++;

                        S = S.erase(pos + depth - offset, len + offset);
                        t->left = new TreeNode(n);
                        int sibling = S.find(line);
                        int child = S.find(line + "-");
                        if (sibling == -1 || child <= sibling)
                            recursive(t->left, S, line + "-", depth + 1);
                    }
                }

                pos = S.find(line, pos);
                if (S.empty() || pos != 0)
                    break;

                len = 1;
                while (pos + depth + len <= S.length() && S[pos + depth + len] != '-')
                    len++;
                
                number = S.substr(pos + depth, len);
                if (is_number(number)) {

                    n = stoi(number);
                    if (!t->right)
                    {
                        int offset = 0;
                        while (pos + depth - offset - 1 >= 0 && S[pos + depth - offset - 1] == '-')
                            offset++;

                        S = S.erase(pos + depth - offset, len + offset);
                        t->right = new TreeNode(n);
                        int sibling = S.find(line);
                        int child = S.find(line + "-");
                        if (sibling == -1 || child <= sibling)
                            recursive(t->right, S, line + "-", depth + 1);
                    }
                }
                else
                    break;
            }

            pos = S.find(line, pos + 1);
        }
    }

    TreeNode* recoverFromPreorder(string S) {

        string line("-");
        int pos = S.find(line);
        if (pos == string::npos)
            return new TreeNode(stoi(S));
        
        else
        {
            TreeNode* root = new TreeNode(stoi(S.substr(0, pos)));
            string cut = S.substr(pos, S.length());
            recursive(root, cut, line, 1);
            return root;
        }
    }
};