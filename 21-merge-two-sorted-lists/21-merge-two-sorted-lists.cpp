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
        
        ListNode* head = NULL;
        ListNode* tail = NULL;
        
        
        while(list1 and list2){
            
            if(head==NULL){
                if(list1->val <= list2->val){
                    head = tail = list1;
                    list1 = list1->next;
                }else{
                    head = tail = list2;
                    list2 = list2->next;
                }
            }
            else{
                if(list1->val <= list2->val){
                    tail->next = list1;
                    tail = tail->next;
                    list1 = list1->next;
                }else{
                    tail->next = list2;
                    tail = tail->next;
                    list2 = list2->next;
                }
            }
        }
        
        while(list1){
            if(head==NULL){
                head = tail = list1;
                list1 = list1->next;
                continue;
             }
             tail->next = list1;
             tail = tail->next;
             list1 = list1->next;   
        }
        
        while(list2){
            if(head==NULL){
                head = tail = list2;
                list2 = list2->next;
                continue;
             }
             tail->next = list2;
             tail = tail->next;
             list2 = list2->next;   
        }
        
        return head;
        
    }
};