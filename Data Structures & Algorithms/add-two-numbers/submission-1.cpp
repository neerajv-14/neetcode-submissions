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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==nullptr && l2==nullptr)return nullptr;
        ListNode* head = nullptr, *tail = nullptr;
        int carry=0;
        while(l1!=nullptr || l2!=nullptr){
            int val1 = 0,val2 =0;
            if(l1!=nullptr)val1= l1->val;
            if(l2!=nullptr)val2= l2->val;
            int val = val1 + val2 + carry;

            if(val>9){
                carry = 1;
                val = val % 10;
            }
            else{
                carry=0;
            }

            ListNode* newNode = new ListNode(val);
            if(head==nullptr){
                head = newNode;
                tail = newNode;
            }
            else{
                tail->next = newNode;
                tail = newNode;
            }

            if(l1!=nullptr)l1 = l1->next;
            if(l2!=nullptr)l2 = l2->next;
        }

        if(carry){
            ListNode* newNode = new ListNode(carry);
            tail->next = newNode;
            tail= newNode;
        }
        tail->next =nullptr;
        return head;

       
    }
};
