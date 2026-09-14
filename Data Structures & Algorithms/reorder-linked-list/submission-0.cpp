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

    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* nex = curr->next;

        while(curr!=nullptr)
        {
            curr->next = prev;
            prev = curr;
            curr = nex;

            if(nex) nex = nex->next;
        }

        return prev;
    }

    void reorderList(ListNode* head) {

        if(!head->next) return;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast!=nullptr && fast->next!=nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* reversedhalf = reverse(slow->next);
        slow->next = nullptr;

        ListNode* curr = head;

        while(reversedhalf!=nullptr)
        {
            ListNode* temp = reversedhalf;

            reversedhalf = reversedhalf->next;

            temp->next = curr->next;
            curr->next = temp;

            curr = temp->next;
        }
        
    }
};
