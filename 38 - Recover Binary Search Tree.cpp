/*

You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

 

Example 1:


Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
Example 2:


Input: root = [3,1,4,null,null,2]
Output: [2,1,4,null,null,3]
Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.

*/

//-----------------------------------------BRUTE FORCE-----------------------------------------------------


class Solution {
    void fill(TreeNode* root,vector<int> &in)
    {
        if(root == NULL)
            return;
        
        fill(root -> left,in);
        fill(root -> right,in);
        
        in.push_back(root -> val);
    }
    
    void findAns(TreeNode* root,vector<int> &in,int &i)
    {
        if(root == NULL)
            return;
        
        findAns(root ->left,in,i);
        
        if(root -> val != in[i])
        {
            root -> val = in[i];
        }   
        i++;
        findAns(root ->right,in,i);
    }
public:
    void recoverTree(TreeNode* root) {
        vector<int> in;
        fill(root,in);
        
        sort(in.begin(),in.end());
        
        int idx = 0;
        findAns(root,in,idx);
    }
};

//------------------------------------------------BETTER------------------------------------


class Solution {
public:
    TreeNode *prev=NULL,*first=NULL,*second=NULL;
    void recoverTree(TreeNode* root) {
        
        prev=new TreeNode(INT_MIN);
        inorder(root);
        
        swap(first->val,second->val);
        
       
    }
    void inorder(TreeNode* root){
        if(root == NULL)
            return ;
        
        inorder(root->left);
        if(first == NULL && root->val < prev->val)
			first = prev;
       
        if(first != NULL && root->val < prev->val)
			second = root;
		prev = root;

		inorder(root->right);
        
        
    }
};