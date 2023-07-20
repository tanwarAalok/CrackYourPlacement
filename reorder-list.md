```
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return;

        ListNode* secondlast = head;
        while(secondlast->next->next) secondlast = secondlast->next;

        secondlast->next->next = head->next;
        head->next = secondlast->next;

        secondlast->next = NULL;

        reorderList(head->next->next);
    }
};
```
