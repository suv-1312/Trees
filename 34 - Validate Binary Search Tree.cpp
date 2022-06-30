/*

Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:
Input: root = [2,1,3]
Output: true


Example 2:
Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.

*/



class Solution {
    bool checkBST(TreeNode* root,long long int min = LLONG_MIN,long long int max = LLONG_MAX)
    {
        if(root == NULL)
            return true;
        
        if(root -> val <=min || root -> val >= max)
            return false;
        
        bool l = checkBST(root -> left,min,root -> val);
        bool r = checkBST(root -> right,root -> val,max);
        
        return l&&r;
        
    }
public:
    bool isValidBST(TreeNode* root) {
        return checkBST(root);
    }
};