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
    ListNode* newHead = NULL;
    int sz =0;
    Solution(ListNode* head) {
        newHead = head;
        
        ListNode* temp = head;
        
        while(temp){
            sz++;
            temp = temp->next;
        }
    }
    
    int getRandom() {
        
        int t = rand()%sz;
        
        ListNode* temp = newHead;
        
        for(int i=1;i<=t;i++){
            temp = temp->next;   
        }

        return temp->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */