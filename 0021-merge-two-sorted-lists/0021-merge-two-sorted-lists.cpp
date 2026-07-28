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
      
       ListNode* first = list1;
       ListNode* second = list2; 

       ListNode* dummy = new ListNode(-1); 
       ListNode* temp3 = dummy; 
       while(first && second){
        if(first->val <= second->val){
            temp3->next = first; 
            first= first->next; 
        }
        else{
            temp3->next = second; 
            second= second->next; 
        }
        temp3 = temp3->next; 
       }
      if(first) temp3->next =first; 
      if(second) temp3->next = second; 
return dummy->next; 
    }
};