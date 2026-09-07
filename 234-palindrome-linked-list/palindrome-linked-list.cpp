
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // find middle
        // reverse the linked list
        // compare from middle
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL&& fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
    ListNode* prev=NULL;
    ListNode* curr=slow;
    while(curr!=NULL){
        ListNode* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    ListNode* left=head;
    ListNode* right=prev;
    while(right!=NULL){
        if(left->val!=right->val)
        return false;
        right=right->next;
        left=left->next;
    }
        return true;
    }
};