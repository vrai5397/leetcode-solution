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
    ListNode* middleNode(ListNode* head) {
        // brute force 
        int length=0;
        ListNode* temp=head;
        while(temp){
            length++;
            temp=temp->next;
        }
        int mid=length/2+1;
        ListNode* temp1=head;
        int cnt=0;
      while(temp1){
         cnt++;
         if(cnt==mid){
          break;
         }
         temp1=temp1->next;
      }
      return temp1;
    }
};