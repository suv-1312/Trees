/*

Given the root of a binary tree, return the preorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [1,2,3]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]

*/


class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        
        stack<TreeNode*> st;
        vector<int> pre;
        
        if(root)
        st.push(root);
        
        while(!st.empty())
        {
            TreeNode* curr = st.top();
            pre.push_back(curr -> val);
            st.pop();
            
            if(curr->right)
                st.push(curr -> right);
            
             if(curr->left)
                st.push(curr -> left);
        }
        return pre;
    }
};