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
    ListNode* reverseList(ListNode* head) {

        if(head==nullptr) return head;

        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* nex = current->next;

        while(current!=nullptr)
        {
            current->next = prev;
            prev = current;
            current = nex;
            if(nex) nex = nex->next;
        }

        return prev;
        
    }
};
