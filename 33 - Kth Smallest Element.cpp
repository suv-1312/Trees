/*

Given the root of a binary search tree, and an integer k, return the 
kth smallest value (1-indexed) of all the values of the nodes in the tree.


Example 1:
Input: root = [3,1,4,null,2], k = 1
Output: 1


Example 2:
Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3

*/

//------------------------------------EXTRA SPACE-------------------------------------------

class Solution {
    void inorder(TreeNode *root,vector<int> &temp)
    {
        if(root == NULL)
            return ;
        
        inorder(root->left,temp);
        temp.push_back(root-> val);
        inorder(root->right,temp);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        
        vector<int> temp;
        inorder(root,temp);
        return temp[k-1];
    }
};

//------------------------------------WITHOUT EXTRA SPACE---------------------------------------

node* kthsmallest(node* root,int &k)
{
	if(root==NULL)
	return NULL;
	
	node* left=kthsmallest(root->left,k);
	if(left!=NULL)
	return left;
	k--;
	if(k==0)
	return root;
	
	return kthsmallest(root->right,k);
}


