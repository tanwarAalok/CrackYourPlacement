```
class Solution {
public:

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* it = dummy;
        ListNode* pre_it = NULL;

        for(int i = 0; i<left; i++){
            pre_it = it;
            it = it->next;
        }

        ListNode* itR = it;
        ListNode* pre_R = pre_it;

        for(int i = left; i<=right; i++){
            ListNode* forward = itR->next;
            itR->next = pre_R;
            pre_R = itR;
            itR = forward;
        }

        pre_it->next = pre_R;
        it->next = itR;

        return dummy->next;
    }
};
```
