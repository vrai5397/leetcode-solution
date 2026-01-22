
class Solution {
public:
// we use recursion to solve this problem
ListNode* reverse_ll(ListNode*head){
    // base case
    if(head==NULL||head->next==NULL)
    return head;
    ListNode* front=reverse_ll(head->next);
    head->next->next=head;
    head->next=NULL;
    return front;
}
    ListNode* reverseList(ListNode* head) {
        return reverse_ll(head);
    }
};