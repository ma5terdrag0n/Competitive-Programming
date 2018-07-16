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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l2)return l1;
        if(!l1)return l2;
        ListNode *head, *app;
        head = app = NULL;
        while(l1 != NULL and l2 != NULL){
            if(l1->val < l2->val){
                if(!head){
                    head = app = l1;
                }
                else{
                    app->next = l1;
                    app = app->next;
                }    
                l1 = l1->next;
            
            }else{
                if(!head){
                    head = app = l2;
                }else{
                    app->next = l2;
                    app = app->next;
                }
                l2 = l2->next;
            }
        }
        
        while(l1 != NULL){
            app->next = l1;
            l1 = l1->next;
            app = app->next;
        }
        
        while(l2 != NULL){
            app->next = l2;
            l2 = l2->next;
            app = app->next;
        }
        return head;
    }
};
