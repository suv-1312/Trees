/*
MORRIS INORDER TRAVERSAL
*/


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
    vector<int> inorder;
    if(root == NULL)
    return inorder;

    TreeNode* curr = root;
    while(curr!=NULL)
    {
        if(curr->left == NULL)
        {
             inorder.push_back(curr -> val);
             curr = curr -> right;
        }
        else
        {
            TreeNode* prev = curr->left;
            while(prev -> right!=NULL && prev ->right!=curr)
                prev = prev -> right;
            
            if(prev -> right == NULL)
            {
                prev -> right = curr;
                curr = curr -> left;
            }
            else
            {
                prev -> right = NULL;
                inorder.push_back(curr -> val);
                curr = curr -> right;
            }
        }
    }
        return inorder;
    }
};