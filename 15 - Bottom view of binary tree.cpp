/*

Given a binary tree, print the bottom view from left to right.
A node is included in bottom view if it can be seen when we look at the tree from bottom.

                      20
                    /    \
                  8       22
                /   \        \
              5      3       25
                    /   \      
                  10    14

For the above tree, the bottom view is 5 10 3 14 25.
If there are multiple bottom-most nodes for a horizontal distance from root, then print the later one in level traversal. For example, in the below diagram, 3 and 4 are both the bottommost nodes at horizontal distance 0, we need to print 4.

                      20
                    /    \
                  8       22
                /   \     /   \
              5      3 4     25
                     /    \      
                 10       14

For the above tree the output should be 5 10 4 14 25.
 

Example 1:

Input:
       1
     /   \
    3     2
Output: 3 1 2
Explanation:
First case represents a tree with 3 nodes
and 2 edges where root is 1, left child of
1 is 3 and right child of 1 is 2.

Thus nodes of the binary tree will be
printed as such 3 1 2.
Example 2:

Input:
         10
       /    \
      20    30
     /  \
    40   60
Output: 40 20 60 30

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