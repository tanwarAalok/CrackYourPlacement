```
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        
        while(curr){
            if(prev && prev->val == curr->val){
                prev->next = curr->next;
            }
            else prev = curr;
            curr = curr->next;
        }

        return head;
    }
};
```
