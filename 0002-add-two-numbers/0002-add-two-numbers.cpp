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
        ListNode* first = l1; 
        ListNode* second = l2; 
        ListNode* dummy = new ListNode(-1); 
        ListNode* curr = dummy; 

        int carry = 0; 
        while(first != NULL || second != NULL || carry != 0){
            int sum = carry; 
            if(first != NULL){
                sum += first->val; 
                first = first->next; 
            }
            if(second != NULL){
                sum += second->val; 
                second = second->next; 
            }

           carry = sum/10; 
           int last_digit = sum%10; 
           curr->next = new ListNode(last_digit); 
           curr= curr->next; 

        }
        return dummy->next ; 
    }
};