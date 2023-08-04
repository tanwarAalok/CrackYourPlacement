```
bool f(Node* root, int mini, int maxi){
    if(!root) return false;
    if(mini == maxi) return true;
    
    if(f(root->left, mini, root->data - 1)) return true;
    if(f(root->right, root->data + 1, maxi)) return true;
    
    return false;
}

bool isDeadEnd(Node *root)
{
    return f(root, 1, INT_MAX);
}
```
