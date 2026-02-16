#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int val = stoi(tokens[0]);
        for (auto i = 1; i < tokens.size(); ++i) {
            try {
                int d = stoi(tokens[i]);
                s.push(d);
            } catch (const exception e) {
                int thing = s.top();
                s.pop();
                switch (tokens[i][0])
                {
                case '+':
                    val += thing;
                    break;
                case '/': 
                    val /= thing;
                case '*':
                    val *= thing;
                case '-':
                    val -= thing;
                default:
                    break;
                }
            }
        }
        return val;
    }
};