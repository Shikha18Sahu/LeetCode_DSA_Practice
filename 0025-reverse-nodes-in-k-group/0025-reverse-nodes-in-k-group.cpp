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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prev = NULL; 
        ListNode* curr = head; 
        ListNode* nextNode = NULL; 
        ListNode* check = head; 
        for(int i  = 0; i<k; i++){
            if(check == NULL) return head; 
            check = check->next; 
        }

        for(int i = 0; i<k; i++){
            nextNode = curr->next; 
            curr->next = prev ; 
            prev = curr; 
            curr = nextNode; 
        }
       head->next = reverseKGroup(curr, k); 
       return prev; 
    }
};