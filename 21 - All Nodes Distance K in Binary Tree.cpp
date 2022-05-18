/* 
Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.

 

Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
Example 2:

Input: root = [1], target = 1, k = 3
Output: []
*/





class Solution {
    private:
    void setParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent)
    {
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode* first = q.front();
            q.pop();
            
            if(first -> left)
            {
                parent[first-> left] = first;
                q.push(first-> left);
            }
            
            if(first -> right)
            {
                parent[first-> right] = first;
                q.push(first-> right);
            }
            
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        unordered_map<TreeNode*,TreeNode*> parent;
        setParents(root,parent);
        
        unordered_map<TreeNode*,bool> visited;
        
        queue<TreeNode*> q;
        q.push(target);
        visited[target] =true;
        int dist = 0;
        
        while(!q.empty())
        {
            int size = q.size();
            if(dist++ == k)
                break;
            
            for(int i = 0 ; i< size;i++)
            {
                  TreeNode* first = q.front();
                  q.pop();
                
                  if(first -> left && !visited[first -> left])
                  {
                      q.push(first -> left);
                      visited[first -> left] = true;
                  }
                
                  if(first -> right && !visited[first -> right])
                  {
                      q.push(first -> right);
                      visited[first -> right] = true;
                  }
                
                  if(parent[first] && !visited[parent[first]])
                  {
                      q.push(parent[first]);
                      visited[parent[first]] = true;
                  }
            }
        }
        
        vector<int> ans;
        
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;        
    }
};