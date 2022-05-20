/*

Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

 
Example 1:

Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:

Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.

*/



class Solution {
public:
    TreeNode* helper(vector<int> arr,int start,int end)
    {
        if(start>end)
            return NULL;
        
        int mid = start +(end -start)/2;
        TreeNode* root = new TreeNode(arr[mid]);
        
        root -> left = helper(arr,start,mid-1);
        root -> right = helper(arr,mid+1,end);
        
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        return helper(nums,0,nums.size()-1);
    }
};