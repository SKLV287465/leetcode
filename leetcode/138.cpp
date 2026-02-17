#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        vector<pair<Node*, Node*>> mappings;

        auto ptr = head;
        int i = 0;
        while (ptr->next) {
            mappings.push_back({ptr, new Node(ptr->val)});
            ++i;
        }

        for (auto j = 0; j < i; ++ j) {

            Node *random = ;
            mappings[j].second->next = ;
            mappings[j].second->random =
        }

        // o(n) space is easy

        // create a mapping from old node addrs to new node addrs, easy,
        // 2 passes, one for the second one.
        // could create an vector/array of nodes, to see which numbered one i need to get. 
        

        // i actually need to have some kind of mapping of random to index.
    }
};