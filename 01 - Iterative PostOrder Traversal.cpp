/*
Given the root of a binary tree, return the postorder traversal of its nodes' values.

Example 1:

Input: root = [1,null,2,3]
Output: [3,2,1]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]

*/

//--------------------USING TWO STACKS----------------------------


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
        stack<TreeNode*> st1,st2;
        vector<int> postorder;
        
         if(root)
             st1.push(root);
        
        while(!st1.empty())
        {
            TreeNode* curr = st1.top();
            st2.push(curr);
            st1.pop();
            
            if(curr -> left)
                st1.push(curr->left);
            
            if(curr -> right)
                st1.push(curr->right);
        }    
        
        while(!st2.empty())
        {
            postorder.push_back(st2.top() -> val);
            st2.pop();
        }
        
        return postorder;
    }
};


------------------------------------USING SINGLE STACK-------------------------------------


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
        stack<TreeNode*> st;
        TreeNode* curr = root;
        vector<int> post;
        
        while(curr!=NULL || !st.empty())
        {
           if(curr!=NULL)
           {
               st.push(curr);
               curr = curr->left;
           }
            else
            {
                TreeNode* temp = st.top()->right;
                if(temp == NULL)
                {
                    temp = st.top();
                    st.pop();
                    
                    post.push_back(temp -> val);
                    
                    while(!st.empty() && temp == st.top()->right)
                    {
                        temp = st.top();
                        st.pop();
                        post.push_back(temp -> val);
                    }
                    
                }
                else
                {
                    curr = temp;
                }
            }
        }
        return post;
    }
};