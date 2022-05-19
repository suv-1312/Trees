/*




Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree
and postorder is the postorder traversal of the same tree, construct and return the binary tree.


Example 1:
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]

Example 2:
Input: inorder = [-1], postorder = [-1]
Output: [-1]

*/


class Solution {
    
    private:
    TreeNode *helper(vector<int>& postorder, vector<int>& inorder,int inS, int inE, int postS, int postE)
    {
        
        if(inS>inE)
            return NULL;
        
        int rootData = postorder[postE];
        TreeNode *root = new TreeNode(rootData);
        
        int length = 0;
        for (int i = inS; inorder[i] != root->val; i++)
        {
          length++;
        }
        
        int lInS = inS;
        int lInE = inS + length -1;
        int rInS = lInE + 2;
        int rInE = inE;
            
        int lPostS = postS;
        int lPostE = postS + length - 1;
        int rPostS = lPostE + 1;
        int rPostE = postE-1;
            
        root -> left = helper(postorder,inorder,lInS,lInE,lPostS,lPostE);
        
        root -> right = helper(postorder,inorder,rInS,rInE,rPostS,rPostE);
        
        return root;
        
        
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    
        return helper(postorder,inorder,0,inorder.size()-1,0,postorder.size() - 1);
        
    }
};