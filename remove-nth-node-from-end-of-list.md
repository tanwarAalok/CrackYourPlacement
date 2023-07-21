```
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* temp = head, *curr = head;
        
        for(int i = 0; i<n; i++){
            curr = curr->next;
        }
        
        if(!curr) return head->next;
        
        while(curr->next){
            curr = curr->next;
            temp = temp->next;
        }
        
        temp->next = temp->next->next;
        
        return head;
        
    }
};
```
