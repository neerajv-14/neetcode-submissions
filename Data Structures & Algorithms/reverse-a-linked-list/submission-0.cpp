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
    void solve(ListNode* curr, ListNode*& reverseHead){
        
        if(curr->next==nullptr){
            reverseHead = curr;
            return;
        }
        solve(curr->next, reverseHead);
       
        ListNode* nextNode = curr->next;
        nextNode->next = curr;
        
        return;
    }
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr)return head;
        ListNode* reverseHead;

        solve(head, reverseHead);
        
        head->next = nullptr;
        
        return reverseHead;
    }
};
