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
        int len = 0;
        ListNode* curr = head;

        while(curr!=nullptr){
            len++;
            curr = curr->next;
        }

        if(n==len){
            ListNode* newHead = head->next;
            head->next =  nullptr;
            delete(head);
            return newHead;
        }

        int ptr = 0, nThFromStart = len - n + 1;

        curr = head;

        while(curr!=nullptr){
            ptr++;
            if(ptr==nThFromStart-1)break;
            curr = curr->next;
        }

        ListNode* nextNode = curr->next->next, *deletedNode = curr->next;
        curr->next = nextNode;
        delete(deletedNode);

        return head;
    }
};
