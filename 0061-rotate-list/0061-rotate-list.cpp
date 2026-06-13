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
        ListNode *temp= head;
        ListNode *prev= NULL;
        int count= 0;
       
        
        while(temp){
            count++;
            temp=temp->next;
        }
         if (head==NULL){
           return head;
        }
         k= k%count;
        if( head->next==NULL||k==0)
        return head;
        count= count-k;
        temp= head;
       
        while(count--){
            prev= temp;
            temp= temp->next;
           
        }
        prev->next= NULL;
        ListNode *tail= temp;
        while(tail->next){
            tail= tail->next;
        }
        tail->next= head;
        head= temp;
       return head;
    }
};