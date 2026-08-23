ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

    ListNode* dummy = new ListNode(-1);
    ListNode* temp = dummy;

    ListNode* temp1 = list1;
    ListNode* temp2 = list2;

    while(temp1 != NULL && temp2 != NULL) {

        if(temp1->val <= temp2->val) {
            temp->next = temp1;
            temp1 = temp1->next;
            temp = temp->next;
        }
        else {
            temp->next = temp2;
            temp2 = temp2->next;
            temp = temp->next;
        }
    }

    while(temp1 != NULL) {
        temp->next = temp1;
        temp1 = temp1->next;
        temp = temp->next;
    }

    while(temp2 != NULL) {
        temp->next = temp2;
        temp2 = temp2->next;
        temp = temp->next;
    }

    dummy = dummy->next;
    return dummy;
}  // ✅ close mergeTwoLists


class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {

          if(lists.size() == 0)
            return NULL;

        ListNode* ans = lists[0];

        for(int i = 1; i < lists.size(); i++) {
            ans = mergeTwoLists(ans, lists[i]);
        }

        return ans;
    }
};