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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head,*x;
        head=l1;
        int carry=0;
        while(l1!=NULL && l2!=NULL){
            int y=l1->val;
            l1->val=(l1->val+l2->val+carry)%10;
            carry = (y+l2->val+carry)/10;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1 != NULL){
            int y=l1->val;
            l1->val=(l1->val+carry)%10;
            carry = (y+carry)/10;
            l1=l1->next;
        }
        ListNode *temp = head;
        while(temp->next!=NULL)temp=temp->next;
        while(l2!=NULL){
            int y=l2->val;
            l2->val=(l2->val+carry)%10;
            carry = (y+carry)/10;
            ListNode * newNode = new ListNode(l2->val);
            temp->next=newNode;
            temp=temp->next;
            l2=l2->next;
        }
        if(carry){
            ListNode * newNode = new ListNode(carry);
            temp->next=newNode;
        }
        return head;
    }
};
