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
    bool solve(ListNode* slowNode, ListNode* fastNode){
        if(fastNode==nullptr || fastNode->next==nullptr)return false;
        if(slowNode==fastNode)return true;

        return solve(slowNode->next, fastNode->next->next);
    }
    bool hasCycle(ListNode* head) {
        if(head==nullptr || head->next==nullptr)return false;
        ListNode* slowNode = head->next, *fastNode = head->next->next;
        return solve(slowNode, fastNode);
    }
};
