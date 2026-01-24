
class Solution {
public:
   ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        while(temp1!=NULL&& temp2!=NULL){
            if(temp1->val<=temp2->val){
                temp->next=temp1;
                temp1=temp1->next;
               
            }
            else{
                temp->next=temp2;
                temp2=temp2->next;
               
            }
             temp=temp->next;
        }
        if(temp1){
            temp->next=temp1;
            temp1=temp1->next;
                temp=temp->next;
        }
         if(temp2){
            temp->next=temp2;
            temp2=temp2->next;
                temp=temp->next;
        }
        return dummy->next;
    }

      ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL&& fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
    return slow;
    }

    ListNode* merge_sort(ListNode* head){
        // base case
       if(head==NULL||head->next==NULL)
       return head;
        ListNode* middle=middleNode(head);
        ListNode* right=middle->next;
        middle->next=NULL;
        ListNode* left=head;
        left=merge_sort(left);
        right=merge_sort(right);

        return mergeTwoLists(left,right);
    }
    ListNode* sortList(ListNode* head) {
        return merge_sort(head);
    }
};