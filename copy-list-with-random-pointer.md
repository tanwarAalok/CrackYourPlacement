```
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return head;
        }
        unordered_map<Node* ,Node*> map;
        Node* dummy=new Node(-1);
        Node* temp=head;
        Node* temp2=dummy;
        while(temp!=NULL){
            Node* copy=new Node(temp->val);
            map[temp]=copy;
            
            temp2->next=copy;
            temp2=copy;
            temp=temp->next; 
        }
        dummy=dummy->next;
        
        temp=dummy;
        temp2=head;
        while(temp!=NULL){
           temp->random=map[temp2->random];
            temp=temp->next;
            temp2=temp2->next;
        }
        return dummy;
    }
};
```
