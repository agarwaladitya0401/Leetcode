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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int a = 0, b=0;
        
        ListNode *c = headA, *d = headB;
        
        while(headA){
            a++;
            headA = headA->next;
        }
        
        while(headB){
            b++;
            headB = headB->next;
        }
        
        int e = max(a,b) - min(a,b);
        
        if(a>b){
            while(e){
                c=c->next;
                e--;
            }
        }
        else{
            
            while(e){
                d=d->next;
                e--;
            }
        }
        
        while(c!=d){
            c=c->next;
            d=d->next;
        }
        
        return c;
    }
};