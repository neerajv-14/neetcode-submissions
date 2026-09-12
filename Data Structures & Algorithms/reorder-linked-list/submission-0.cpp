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
    ListNode* reverseList(ListNode* head){
        if(head==nullptr || head->next==nullptr)return head;

        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
    void reorderList(ListNode* head) {
        if(head==nullptr || head->next==nullptr)return ;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* reverseHead = reverseList(slow->next);
        slow->next = nullptr;
       
        ListNode* l1 = head, *l2 =reverseHead, *ansHead = nullptr, *ansTail = nullptr;
        
        while(l1!=nullptr && l2!=nullptr){
            if(ansHead==nullptr){
                ansHead = l1;
                ansTail = l1;
                l1 = l1->next;
                ansTail->next = l2;
                ansTail = l2;
                l2 = l2->next;
            }
            else{
                ansTail->next = l1;
                ansTail = l1;
                l1 = l1->next;
                ansTail->next = l2;
                ansTail = l2;
                l2 = l2->next;
            }
        }

        if(l1!=nullptr){
            ansTail->next = l1;
            ansTail= l1;
        }

        ansTail->next = nullptr;
        return;
    }
};
