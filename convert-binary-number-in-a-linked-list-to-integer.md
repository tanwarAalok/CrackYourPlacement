```
class Solution {
public:
    int f(ListNode* head){
        ListNode* curr = head;
        int cnt = 0;
        while(curr){
            cnt++;
            curr = curr->next;
        }
        return cnt;
    }

    int getDecimalValue(ListNode* head) {
        int bits = f(head);
        int base = bits - 1;

        int ans = 0;
        ListNode* curr = head;

        while(curr){
            int dec = pow(2, base);
            ans += (curr->val * dec);
            curr = curr->next;
            base--;
        }

        return ans;
    }
};
```
