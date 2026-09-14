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
        ListNode* front = head;

        for(int i=0;i<n;i++) front = front->next;

        if(front==nullptr)
        {
            ListNode* target = head;
            head = head->next;

            target->next = nullptr;
            delete target;
            
            return head;
        }

        while(front->next!=nullptr)
        {
            temp = temp->next;
            front = front->next;
        }

        ListNode* target = temp->next;
        ListNode* nex = target->next;

        temp->next = nex;
        target->next = nullptr;
        delete target;

        return head;

    }
};
