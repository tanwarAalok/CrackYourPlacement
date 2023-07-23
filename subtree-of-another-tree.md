```
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;

        if(isIdentical(root, subRoot)) return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool isIdentical(TreeNode* n1, TreeNode* n2){
        if(!n1 || !n2) return !n1 && !n2;
        return n1->val == n2->val && isIdentical(n1->left, n2->left) && isIdentical(n1->right, n2->right);
    }
};
```
