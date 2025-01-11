#include <bits/stdc++.h>
using namespace std;

//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head; // This will move one step at a time
        ListNode *fast = head; // This will move two steps at a time

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;       // Move slow one step
            fast = fast->next->next; // Move fast two steps
        }
        return slow; // When fast reaches the end, slow will be at the middle
    }
};