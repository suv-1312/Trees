/*

Given the root of a binary tree, return the same tree where every subtree (of the given tree) not containing a 1 has been removed.

A subtree of a node node is node plus every node that is a descendant of node.

 

Example 1:


Input: root = [1,null,0,0,1]
Output: [1,null,0,null,1]
Explanation: 
Only the red nodes satisfy the property "every subtree not containing a 1".


Example 2:
Input: root = [1,0,1,0,0,0,1]
Output: [1,null,1,null,1]


Example 3:
Input: root = [1,1,0,1,1,0,1,0]
Output: [1,1,0,1,1,null,1]

*/


class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        
        if(root == NULL)
            return NULL;
        
        TreeNode* l = pruneTree(root->left);
        TreeNode* r = pruneTree(root->right);
        
        if(root -> val == 0 && l  == NULL && r == NULL)
        {
            delete root;
            return NULL;
        }
        else
        {
        root->left = l;
        root -> right = r;
        return root;
        }
        
        
    }
};

//----------------------------------------------------------------------

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        
        if(root == NULL)
            return NULL;
        
        root -> left = pruneTree(root->left);
        root -> right = pruneTree(root->right);
        
        if(root -> val == 0 && root->left == root -> right)
            return NULL;
        
        return root;        
    }
};