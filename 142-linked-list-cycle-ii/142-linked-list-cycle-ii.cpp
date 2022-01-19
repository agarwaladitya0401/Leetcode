/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *s, *f;
        
        if(head == NULL){
            return NULL;
        }
        
        if(head->next == head){
            return head;
        }
        
        
        if(head->next == NULL){
            return NULL;
        }
        
        s = head->next;
        f = head->next->next;
        
        while(s!=f){
            
            if(s==NULL || f==NULL){
                return NULL;
            }
            
            s = s->next;
            
            if(f->next == NULL)
                return NULL;
            
            f = f->next->next;
        }
        
        if(s==NULL){
            return NULL;
        }
        
        ListNode* same =NULL;
        
        ListNode* temp = head;
        
        while(temp != s){
            temp = temp->next;
            s = s->next;
        }
        
        return temp;
    }
    
};