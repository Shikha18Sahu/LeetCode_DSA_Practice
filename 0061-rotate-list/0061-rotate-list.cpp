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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k==0) return head; 
       // 1. size of ListNode
       ListNode *temp =head; 
       int n =1; 
       while(temp->next){
        temp = temp->next; 
        n++; 
       }
       k = k%n; 
       if(k==0) return head; 
       
       temp->next = head; 
       ListNode* curr = head; 
       int res = n-k; 
       for(int i = 1; i<res; i++){
         curr=curr->next; 
       }
        ListNode* newhead = curr->next; 
        curr->next = NULL; 
        return newhead; 
    }
};