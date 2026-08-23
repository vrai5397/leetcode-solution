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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // solving this question using priority_queue
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,
        greater<pair<int,ListNode*>>> pq;
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL)
            pq.push({lists[i]->val,lists[i]});
        }
          // we have to make dummy
          ListNode* dummy=new ListNode(-1);
          ListNode* temp=dummy;
          while(!pq.empty()){
             // pq is not empty
             auto x=pq.top();
             pq.pop();
             // coonect in dummy
             temp->next=x.second;
             temp=temp->next;
             if(x.second->next!=NULL)
             pq.push({x.second->next->val,x.second->next});
          }
          return dummy->next;
    }
};