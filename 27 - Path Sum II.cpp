/*

Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of
the node values in the path equals targetSum. Each path should be returned as a list of the node values,
not node references.
A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no
children.

Example 1:
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22


Example 2:
Input: root = [1,2,3], targetSum = 5
Output: []


Example 3:
Input: root = [1,2], targetSum = 0
Output: []

*/


class Solution {
private:
	bool isLeaf(TreeNode *root)
	{
		if (root == NULL)
			return true;

		return (root ->left == NULL && root -> right == NULL);
	}
	void getAns(TreeNode* root, int targetSum, vector<vector<int>> &ans, vector<int> &temp)
	{
		if (root == NULL)
		{
			return;
		}

		if (isLeaf(root))
		{
			if (targetSum == root ->val)
			{
				temp.push_back(root-> val);
				ans.push_back(temp);
				temp.pop_back();
				return;
			}
			else
				return;
		}


		temp.push_back(root-> val);
		getAns(root->left, targetSum - (root -> val), ans, temp);

		getAns(root->right, targetSum - (root -> val), ans, temp);
		temp.pop_back();
	}
public:
	vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

		vector<vector<int>> ans;
		vector<int> temp;

		if (root == NULL)
			return ans;

		if (root-> left == NULL && root -> right == NULL && root -> val == targetSum)
		{
			ans.push_back({root -> val});
			return ans;
		}

		getAns(root, targetSum, ans, temp);
		return ans;

	}
};