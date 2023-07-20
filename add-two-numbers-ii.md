### By reversing
```
class Solution {
public:
    ListNode* reverseList(ListNode* head){
        ListNode* prev = NULL, *curr = head, *nextNode;
        while(curr){
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    ListNode* add(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        ListNode* curr = ans;
        
        int carry = 0;

        while(l1 || l2 || carry){
            int sum = 0;
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }

            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }

            sum += carry;
            carry = sum / 10;
            ListNode* temp = new ListNode(sum%10);
            curr->next = temp;
            curr = temp;
        }

        return ans->next;
        
    }

    void print(ListNode* head){
        while(head){
            cout<<head->val<<" ";
            head = head->next;
        }
        cout<<endl;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l1_r = reverseList(l1);
        ListNode* l2_r = reverseList(l2);

        print(l1_r);
        print(l2_r);

        ListNode* ans = add(l1_r, l2_r);

        return reverseList(ans);
    }
};
```

### By using stack
```
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;

        while (l1 != nullptr) {
            s1.push(l1->val);
            l1 = l1->next;
        }

        while (l2 != nullptr) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        int totalSum = 0, carry = 0;
        ListNode* ans = new ListNode();
        while (!s1.empty() || !s2.empty()) {
            if (!s1.empty()) {
                totalSum += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                totalSum += s2.top();
                s2.pop();
            }

            ans->val = totalSum % 10;
            carry = totalSum / 10;
            ListNode* newNode = new ListNode(carry);
            newNode->next = ans;
            ans = newNode;
            totalSum = carry;
        }

        return carry == 0 ? ans->next : ans;
    }
};
```
