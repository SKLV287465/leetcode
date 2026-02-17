#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        int count = 0;
        ListNode* start = head;
        ListNode* mid = head;
        ListNode* end = head;
        while (end->next) {
            end = end->next;
            ++count;
        }
        
        int midi = count / 2;
        if (count % 2) {
            // not divisible by 2
            ++count;
        }
        for (auto i = 0; i < midi; ++i) {
            mid = mid->next;
        }
        auto midend = mid;
        auto midendend = midend;
        while (mid->next) {
            mid = mid->next;
            midend
            
        }
        


        // find middle,
        // reverse the second half
        // merge the two halves.
        // done
    }
};