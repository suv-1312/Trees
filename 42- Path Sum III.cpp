PROBLEM: PATH SUM III
--------------------------------
Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).

 

Example 1:


Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
Output: 3
Explanation: The paths that sum to 8 are shown.
Example 2:

Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: 3

----------------------------------

// SIMILAR TO COUNT SUBARRAYS WITH GIVEN SUM

class Solution {
    void solve(TreeNode* root,int target,unordered_map<long,int> &mp,int &count,long long sum)
    {
        if(root == NULL)
        return;
        
        sum+=root->val;

        if(sum == target)
        count++;

        if(mp.find(sum-target)!=mp.end())
        count+=mp[sum-target];

        mp[sum]++;
        solve(root->left,target,mp,count,sum);
        solve(root->right,target,mp,count,sum);
        mp[sum]--;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        
        unordered_map<long,int> mp;
        int count =0;
        solve(root,targetSum,mp,count,0);
        return count;
    }
};