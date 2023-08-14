```
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
    ListNode* partition(ListNode* head, int x) {
        if(!head) return head;

        ListNode* left = new ListNode(-1), *right = new ListNode(-1);

        ListNode* rightHead = right, *leftHead = left;

        ListNode* curr = head;

        while(curr){
            if(curr->val < x){
                left->next = curr;
                left = left->next;
                curr = curr->next;
                left->next = NULL;
            }
            else {
                right->next = curr;
                right = right->next;
                curr = curr->next;
                right->next = NULL;
            }
        }

        left->next = rightHead->next;

        return leftHead->next;
    }
};
```
