```
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return NULL;
        while(head && head->val == val) head = head->next;

        ListNode* curr = head, *prev = NULL;
        while(curr){
            if(curr->val == val){
                prev->next = curr->next;
            }
            else prev = curr;
            curr = curr->next;
        }

        return head;
    }
};
```
