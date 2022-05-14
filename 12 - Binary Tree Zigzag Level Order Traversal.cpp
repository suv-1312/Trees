
/*

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []

*/


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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(root == NULL)
            return ans;
        
        queue<TreeNode*> q;
        
        q.push(root);
        
        bool flag = true;
        while(!q.empty())
        {
            int n = q.size();
            
            vector<int> temp(n);
            
            for(int i =0;i<n;i++)
            {
                TreeNode* first = q.front();
                q.pop();
                
                int idx = (flag)?i:n-i-1;
                
                //Calculating the index where thr current element is to be pushed
                temp[idx] = first -> val;
                
                if(first -> left)
                    q.push(first->left);
                
                 if(first -> right)
                    q.push(first->right);
            }
            ans.push_back(temp);
            flag = !flag; 
        }
        return ans;
    }
};


