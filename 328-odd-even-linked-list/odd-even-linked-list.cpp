
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL)
        return NULL;
        ListNode* odd=head;
        ListNode* even=head->next;
        ListNode* even1=head->next;
        while(even!=NULL&&even->next!=NULL){
            odd->next=odd->next->next;
            even->next=even->next->next;
            
            odd=odd->next;
            even=even->next;

        }
        odd->next=even1;
        return head;
    }
};