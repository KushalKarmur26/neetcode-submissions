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

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* temp = head;
        int size = 0;

        while(temp!=nullptr)
        {
            size++;
            temp = temp->next;

        }

        if(size==n)
        {
            ListNode* target = head;
            head = head->next;

            target->next = nullptr;
            delete target;
            return head;
        }

        int movements = size - n - 1;

        temp = head;

        while(movements>0)
        {
            temp = temp->next;
            movements--;
        }

        ListNode* target = temp->next;
        ListNode* nex = target->next;

        temp->next = nex;
        target->next = nullptr;
        delete target;

        return head;
        
    }
};
