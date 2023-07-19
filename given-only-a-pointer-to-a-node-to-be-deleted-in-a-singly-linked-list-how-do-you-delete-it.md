```
void deleteNode(Node* node)
{
    Node* prev;
    if (node == NULL)
        return;
    else {
        while (node->next != NULL) {
            node->data = node->next->data;
            prev = node;
            node = node->next;
        }
        prev->next = NULL;
    }
}
```
