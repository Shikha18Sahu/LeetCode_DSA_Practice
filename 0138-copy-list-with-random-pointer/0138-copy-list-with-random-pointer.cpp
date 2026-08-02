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
        //1. copied node next to the real node
        if(head== NULL) return head; 
        Node* temp = head; 
      
        while(temp){
           Node* copyNode = new Node(temp->val); 
           copyNode->next = temp->next; 
           temp->next = copyNode; 
           temp = copyNode->next; 
        }

        // random pointer
        temp = head; 
        while(temp){
          if(temp->random){
           temp->next->random = temp->random->next;
        }
        temp= temp->next->next; 
        }
      
       // separate both ll
       Node *dummy = new Node(0); 
       Node *temptail = dummy; 
       temp = head; 
       while(temp){
        Node* tempnode = temp->next; 
        temptail->next = tempnode; 
        temptail = tempnode; 
        temp->next = tempnode->next; 
        temp = temp->next; 
       }
       return dummy->next; 
    }
};