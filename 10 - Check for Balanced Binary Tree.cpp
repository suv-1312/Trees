/*

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: true
Example 2:


Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:

Input: root = []
Output: true

*/

//--------------------------------------------O(n^2)-----------------------------------------


class Solution {
    int height(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        
        return max(height(root -> left),height(root -> right))+1;
    }
public:
    bool isBalanced(TreeNode* root) {
        
        if(root == NULL)
            return true;
        
        int l = height(root -> left);
        int r = height(root -> right);
        
        return (abs(l-r)<=1) && isBalanced(root->left) && isBalanced(root -> right);
    }
};


//-------------------------------------


/*
Height of Binary tree in O(n)..

int height(TreeNode* root)
{
     if(root == NULL)
          return 0;
     
     int lh = height(root ->left);
     int rh = height(root ->right);
     
     return max(lh,rh)+1;
}

*/


class Solution {
private:
	int height(TreeNode* root)
	{
		if (root == NULL)
			return 0;

		int lh = height(root ->left);
		if (lh == -1)
			return -1;

		int rh = height(root ->right);
		if (rh == -1)
			return -1;

		if (abs(lh - rh) > 1)
			return -1;

		return max(lh, rh) + 1;
	}
public:
	bool isBalanced(TreeNode* root) {

		if (root == NULL)
			return true;

		if (height(root) == -1)
			return false;

		return true;
	}
};

