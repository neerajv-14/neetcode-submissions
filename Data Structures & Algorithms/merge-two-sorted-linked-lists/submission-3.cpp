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
        ListNode* head = nullptr, *tail = nullptr;
        if(list1==nullptr && list2==nullptr)return head;
        while(list1!=nullptr || list2!=nullptr){
            if(list1==nullptr){
                if(head==nullptr){
                    head = list2;                
                }
                else{
                    tail->next = list2; 
                }
                tail = list2;
                list2=list2->next;
            }
            else if(list2==nullptr){
                if(head==nullptr){
                    head = list1;
                }
                else{
                    tail->next = list1;
                }
                tail = list1;
                list1=list1->next;
            }
            else if(list1->val<=list2->val){
                if(head==nullptr){
                    head = list1;
                }
                else{
                    tail->next = list1;
                }
                tail = list1;
                list1=list1->next;
            }
            else{
                if(head==nullptr){
                    head = list2;                
                }
                else{
                    tail->next = list2; 
                }
                tail = list2;
                list2=list2->next;
            }
            //cout << head->val << " "<< tail->val<< endl;
        }
        tail->next = nullptr;
        return head;
    }
};
