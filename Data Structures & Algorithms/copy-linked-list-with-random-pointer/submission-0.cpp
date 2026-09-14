/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> m;
    
        Node* curr = head,*newHead=nullptr;

        while(curr!=nullptr){
            Node* node,*random,*next;
            if(m.find(curr)==m.end()){
                node = new Node(curr->val);
                m[curr] = node;
            }

            node = m[curr];
            
            if(curr->next==nullptr){
                node->next = nullptr;
            }
            else{
                if(m.find(curr->next)==m.end()){
                    next = new Node(curr->next->val);
                    m[curr->next] = next;
                }
                next = m[curr->next];

                node->next = next;
                
            }

            if(curr->random==nullptr){
                node->random = nullptr;
            }
            else{
                if(m.find(curr->random)==m.end()){
                    random = new Node(curr->random->val);
                    m[curr->random] = random;
                }
                random = m[curr->random];

                node->random = random;
                
            }

            if(curr==head)newHead = node;

            curr = curr->next;
        }

        return newHead;
    }
};
