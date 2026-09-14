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

private:

    ListNode* popfront(ListNode* head)
    {
        if(!head) return head;
        
        ListNode* target = head;
        head = head->next;

        target->next = nullptr;
        delete target;

        return head;
    }

    ListNode* pushback(ListNode* rear, int n)
    {   
        ListNode* newnode = new ListNode(n);
        if(!rear)
        {
            return newnode;
        }


        rear->next = newnode;
        return newnode;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* head = nullptr;
        ListNode* rear = nullptr;

        int cin = 0;

        while(l1!=nullptr || l2!=nullptr)
        {
            int num1 = l1 ? l1->val : 0;
            int num2 = l2 ? l2->val : 0;

            int sum = (num1 + num2 + cin)%10;
            int cout = (num1 + num2 + cin)/10;

            cin = cout;

            l1 = popfront(l1);
            l2 = popfront(l2);

            if(!head)
            {
                head = pushback(rear,sum);
                rear = head;
            }

            else rear = pushback(rear,sum);
        }

        if(cin) rear = pushback(rear,cin);
        return head;
        
    }
};
