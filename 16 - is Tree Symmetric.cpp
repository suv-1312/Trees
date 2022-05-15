/*

Given a binary tree, check whether it is a mirror of itself.

For example, this binary tree is symmetric: 

     1
   /   \
  2     2
 / \   / \
3   4 4   3

But the following is not:
    1
   / \
  2   2
   \   \
   3    3

*/


class Solution {
    private:
    bool check(TreeNode* left,TreeNode* right)
    {
        if(left == NULL || right == NULL)
            return left == right;
        
        if(left->val != right-> val)
            return false;
        
        bool a = check(left->left,right->right);
        bool b = check(left->right,right->left);
        
        return a && b;
    }
public:
    bool isSymmetric(TreeNode* root) {
        
        return root == NULL || check(root->left,root -> right);
    }
};