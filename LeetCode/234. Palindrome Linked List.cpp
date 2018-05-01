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
    bool isPalindrome(ListNode* head) {
        if(head==NULL) return true;
        struct ListNode* temp1=head;
        int a[100000],index=0;
        while(temp1!=NULL){
            a[index++]=temp1->val;
            temp1=temp1->next;
        }
        int back=index-1;
        for(int i=0;i<=back;i++,back--){
            if(a[i]!=a[back]) return false;
        }
        return true;
    }
};
