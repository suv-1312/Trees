/*

Problem Statement
You have been given a Binary Tree of 'N' nodes, where the nodes have integer values. Your task is to find the ln-Order, Pre-Order, and Post-Order traversals of the given binary tree.
For Example :
For the given binary tree:

The Inorder traversal will be [5, 3, 2, 1, 7, 4, 6].
The Preorder traversal will be [1, 3, 5, 2, 4, 7, 6].
The Postorder traversal will be [5, 2, 3, 7, 6, 4, 1].


*/


/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/
#include<bits/stdc++.h>
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
	
	vector<int> in,pre,post;
	vector<vector<int>> ans;
	
	if(root == NULL)
		return ans;
	
	stack<pair<BinaryTreeNode<int>*,int>> st;
	st.push({root,1});
	
	while(!st.empty())
	{
		auto it = st.top();
		st.pop();
		
		if(it.second == 1)
		{
			pre.push_back(it.first -> data);
			it.second++;
			st.push(it);
			
			if(it.first -> left!=NULL)
				st.push({it.first -> left,1});
		}
		
		else if(it.second == 2)
		{
			in.push_back({it.first -> data});
			it.second++;
			st.push(it);
			
			if(it.first -> right!=NULL)
				st.push({it.first -> right,1});
		}
		else
		{
			post.push_back(it.first -> data);
		}
	}
	ans.push_back(in);
	ans.push_back(pre);
	ans.push_back(post);
}