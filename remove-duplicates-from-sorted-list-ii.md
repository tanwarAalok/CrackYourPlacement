```
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;

        map<int,int> map;

        ListNode* tail = head;

        while(tail){
            map[tail->val]++;
            tail = tail->next;
        }

        ListNode* temp = new ListNode(-1);
        tail = temp;

        for(auto m : map){
            if(m.second == 1){
                ListNode* curr = new ListNode(m.first);
                tail->next = curr;
                tail = tail->next;
            }
        }

        return temp->next;
    }
};
```
