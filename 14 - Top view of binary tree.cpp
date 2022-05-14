/*

Problem Statement
You are given a Binary Tree of integers. You are supposed to return the top view of the given binary tree. The Top view of the binary tree is the set of nodes that are visible when we see the tree from the top.
Example:
For the given binary tree:

The top view of the tree will be {10, 4, 2, 1, 3, 6}.
Input Format:
The first line contains an integer 'T' which denotes the number of test cases. 

The first line of each test case contains elements of the tree in the level order form. The line consists of values of nodes separated by a single space. In case a node is null, we take -1 in its place.
Example:
The input for the tree depicted in the below image would be:

1 2 3 4 -1 5 6 -1 7 -1 -1 -1 -1 -1 -1

*/


/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
	vector<int> ans;
	if(root == NULL)
		return ans;
	
	//MAP WILL STORE PAIRS IN FORM OF {LEVEL,VALUE OF FIRST NODE AT THAT LEVEL}
	map<int,int> mp;
	
	//QUEUE CONTAINS PAIR OF {NODE,LEVEL}
	queue<pair<TreeNode<int>*,int>> q;
	
	q.push({root,0});
	while(!q.empty())
	{
		auto it = q.front();
		q.pop();
		
		TreeNode<int> *node = it.first;
		int line = it.second;
		
		//STORE ONLY FIRST NODE CORRESPONDING TO GIVEN LEVEL
		if(mp.find(line) == mp.end())
			mp[line] = node->val;
		
		//INSERT LEFT CHILD IF PRESENT
		if(node -> left)
			q.push({node -> left,line-1});
		
		//INSERT RIGHT CHILD IF PRESENT
		if(node -> right)
			q.push({node -> right,line+1});
	}

	for(auto it:mp)
	{
		ans.push_back(it.second);
	}
	return ans;
}