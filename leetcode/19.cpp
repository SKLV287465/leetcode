#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // just iterate through and count
        // go to size - nth - 1 thing and remove the size - nth node.
        // think of the case where nth is the first one.


        // fast and slow ptr is when slow ptr is lagging n behind fast ptr.

        auto fast = head;
        auto slow = head;
        auto slowprev = head;
        auto distance = 0;
        while (fast->next) {
            if (distance >= n - 1) {
                slowprev = slow;
                slow = slow->next;
            }
            fast = fast->next;
            ++distance;
        }
        if (slow == head) {
            head = head->next;
            delete slow;
            return head;
        }

        slowprev->next = slow->next;
        delete slow;
        return head; 
    }
};