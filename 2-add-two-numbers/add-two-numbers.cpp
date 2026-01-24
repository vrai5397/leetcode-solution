
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        int carry=0;
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        while(temp1!=NULL||temp2!=NULL){
           int sum=carry;
           if(temp1) sum+=temp1->val;
           if(temp2) sum+=temp2->val;
           carry=sum/10;
           ListNode* newNode=new ListNode(sum%10);
           temp->next=newNode;
           temp=temp->next;

           if(temp1) temp1=temp1->next;
           if(temp2) temp2=temp2->next;

   }
if(carry){
    ListNode* h=new ListNode(carry);
    temp->next=h;
}
dummy=dummy->next;
return dummy;

    }
};