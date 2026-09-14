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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if(list1==nullptr) return list2;
        if(list2==nullptr) return list1;
        
        ListNode* smallcurrent = list1->val<list2->val ? list1 : list2;
        ListNode* bigcurrent = list1->val >= list2->val ? list1 : list2;
        ListNode* head = smallcurrent;

        ListNode* smallnext = smallcurrent->next;

        while(bigcurrent!=nullptr)
        {
            while(smallnext!=nullptr && smallnext->val<bigcurrent->val)
            {
                smallcurrent = smallnext;
                smallnext = smallnext->next;
            }

            if(smallnext==nullptr)
            {
                smallcurrent->next = bigcurrent;
                bigcurrent = nullptr;
                return head;
            }

            ListNode* temp = bigcurrent;
            bigcurrent = bigcurrent->next;

            temp->next = smallnext;
            smallcurrent->next = temp;
            smallcurrent = smallcurrent->next;

            
        }
        

        return head;
    }
};
