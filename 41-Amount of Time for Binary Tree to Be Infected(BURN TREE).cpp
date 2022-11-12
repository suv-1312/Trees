PROBLEM:
----------------------------------------------------------------------------------------

You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.

Each minute, a node becomes infected if:

The node is currently uninfected.
The node is adjacent to an infected node.
Return the number of minutes needed for the entire tree to be infected.

Input: root = [1,5,3,null,4,10,6,9,2], start = 3
Output: 4
Explanation: The following nodes are infected during:
- Minute 0: Node 3
- Minute 1: Nodes 1, 10 and 6
- Minute 2: Node 5
- Minute 3: Node 4
- Minute 4: Nodes 9 and 2
It takes 4 minutes for the whole tree to be infected so we return 4.

-----------------------------------------------------------------------------------------

SOLUTION:

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
    TreeNode* assignParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &mp,int data)
    {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* target = NULL;
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            
            if(curr -> val == data)
            target = curr;

            if(curr->left)
            {
                mp[curr->left] = curr;
                q.push(curr->left);
            }

            if(curr->right)
            {
                mp[curr->right] = curr;
                q.push(curr->right);
            }
        }
        return target;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
       
        if(root == NULL || root ->left == root->right)
        return 0;

        unordered_map<TreeNode*,TreeNode*> mp;
        TreeNode* target = assignParent(root,mp, start);

        int time = 0;
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> q;

        q.push(target);
        visited[target] = true;
        while(!q.empty())
        {
            int numNodes = q.size();
            bool isNewInfected = false;

            for(int i =0;i<numNodes;i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                
                if(curr -> left && !visited[curr->left])
                {
                    isNewInfected = true;
                    visited[curr->left]=true;
                    q.push(curr->left);
                }

                if(curr -> right && !visited[curr->right])
                {
                    isNewInfected = true;
                    visited[curr->right] = true;
                    q.push(curr->right);
                }

                if(mp[curr] && !visited[mp[curr]])
                {
                    isNewInfected = true;
                    visited[mp[curr]] = true;
                    q.push(mp[curr]);
                }
            }
            if(isNewInfected)
            time++;
        }
        return time;
    }
};