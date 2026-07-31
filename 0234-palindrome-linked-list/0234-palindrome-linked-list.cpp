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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true; 
        ListNode* temp = head; 
        ListNode* slow = head; 
        ListNode* fast = head; 
        // middle 
        while(fast->next && fast->next->next){
            slow = slow->next; 
            fast = fast->next->next; 
        }
        // reverse second part
        ListNode* prev = NULL;
        ListNode* curr = slow->next; 
        ListNode* nextNode = NULL; 
        while(curr){
            nextNode = curr->next; 
            curr->next = prev; 
            prev = curr; 
            curr= nextNode; 
        }
        while(prev){
            if(temp->val != prev->val) return false;
            temp = temp->next; 
            prev =prev->next; 
        }
        return true; 
    }
};