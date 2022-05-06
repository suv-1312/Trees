/*

Given the root of a binary tree, return the inorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [1,3,2]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]

*/

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        stack<TreeNode *> st;
        vector<int> in;
        
        TreeNode* curr = root;
        
        while(true)
        {
            if(curr != NULL)
            {
                st.push(curr);
                curr = curr-> left;
            }
            else
            {
                if(st.size() == 0)
                    break;
                
                curr = st.top();
                st.pop();
                in.push_back(curr->val);
                curr = curr -> right;
            }
        }
        return in;
    }
};