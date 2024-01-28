#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int val)
    {
        this->val = val;
        next = NULL;
    }
};

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
class Solution
{
public:
    ListNode *f(ListNode *head)
    {
        if (head == NULL)
            return NULL;

        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *nextp;

        while (curr != NULL)
        {
            nextp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextp;
        }

        return prev;
    }

    int pairSum(ListNode *head)
    {

        if (head == NULL)
            return 0;

        int ans = 0;
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = NULL;

        while (fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = NULL;
        slow = f(slow);
        fast = head;

        while (slow && fast)
        {
            ans = max(ans, slow->val + fast->val);
            slow = slow->next;
            fast = fast->next;
        }

        return ans;
    }
};