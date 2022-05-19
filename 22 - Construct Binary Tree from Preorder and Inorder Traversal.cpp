/*

Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree
and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 
Example 1:
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]

Example 2:
Input: preorder = [-1], inorder = [-1]
Output: [-1]

*/


class Solution {
public:
    TreeNode *helper(vector<int>& preorder, vector<int>& inorder,int inS, int inE, int preS, int preE)
    {
        if(inS>inE)
            return NULL;
        
        int rootData = preorder[preS];
        TreeNode *root = new TreeNode(rootData);
        
        int rootIndex = -1;
        for(int i = inS ; i<= inE ; i++)
        {
            if(inorder[i] == rootData)
                rootIndex = i;
        }
        
        int lInS = inS;
        int lInE = rootIndex -1;
        int rInS = rootIndex+1;
        int rInE = inE;
            
        int lPreS = preS+1;
        int lPreE = lInE - lInS + lPreS;
        int rPreS = lPreE + 1;
        int rPreE = preE;
        
        root -> left = helper(preorder,inorder,lInS,lInE,lPreS,lPreE);
        
        root -> right = helper(preorder,inorder,rInS,rInE,rPreS,rPreE);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        return helper(preorder,inorder,0,inorder.size()-1,0,preorder.size() - 1);
    }
};