/*
Problem Statement
You have been given a binary tree of integers. You are supposed to find the left view of the binary tree. The left view of a binary tree is the set of all nodes that are visible when
 the binary tree is viewed from the left side.
*/


/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/


//----------------------------------------ITERATIVE----------------------------------------


vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
	vector<int> ans;
	
	if(root == NULL)
		return ans;
	
	queue<TreeNode<int>*> q;
	
	q.push(root);
	
	while(!q.empty())
	{
		int n = q.size();
		for(int i = 0 ; i<n ; i++)
		{
			TreeNode<int> * first = q.front();
			q.pop();
			
			if(i == 0)
				ans.push_back(first -> data);
			
			if(first -> left)
				q.push(first -> left);
			
			if(first -> right)
				q.push(first -> right);
		}
	}
	return ans;
}



//----------------------------------------RECURSIVE----------------------------------------



void getLeftView(TreeNode<int>* root,int level, vector<int> &ans)
{
      if(root == NULL){
		  return;
	  }
	
	 if(level == ans.size())
		 ans.push_back(root -> data);
	 
	  getLeftView(root->left,level+1,ans);
	  getLeftView(root->right,level+1,ans);
}

vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
	vector<int> ans;
	getLeftView(root,0,ans);
	return ans;
}
