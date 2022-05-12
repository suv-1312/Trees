/*

Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

 

Example 1:


Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
Example 2:

Input: root = [1,2]
Output: 1

*/

//-------------------------------------O(N^2)-----------------------------------------------

class Solution {
    private:
    
    int height(TreeNode *root)
    {
        if(root == NULL)
            return 0;
        
        return max(height(root -> left),height(root -> right))+1;
    }
    
    void helper(TreeNode* root,int &maxi)
    {
        if(root == NULL)
            return ;
        
        int lh = height(root -> left);
        int rh = height(root -> right);
        
        maxi = max(lh+rh,maxi);
        
        helper(root->left,maxi);
        helper(root->right,maxi);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(root == NULL)
            return 0;
        
        int maxi = INT_MIN;
        helper(root,maxi);
        return maxi;
        
    }
};


//---------------------------------------O(N)------------------------------------------------



class Solution {
    private:
    
    int helper(TreeNode *root,int &maxi)
    {
        if(root == NULL)
            return 0;
        
        int lh = helper(root -> left,maxi);
        int rh = helper(root -> right,maxi);
        
        //Don't need to compute height again and again
        maxi = max(lh+rh,maxi);
        
        return max(lh,rh)+1;
    }
    
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(root == NULL)
            return 0;
        
        int maxi = INT_MIN;
        helper(root,maxi);
        return maxi;
        
    }
};