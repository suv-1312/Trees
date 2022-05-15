/*
Given a binary tree, write a function to get the maximum width of the given tree. Width of a tree is maximum of widths of all levels. 

Let us consider the below example tree.  

         1
        /  \
       2    3
     /  \     \
    4    5     8 
              /  \
             6    7
For the above tree, 
width of level 1 is 1, 
width of level 2 is 2, 
width of level 3 is 3 
width of level 4 is 2. 
So the maximum width of the tree is 3

*/



class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        
        if(root == NULL)
            return 0;
        
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int width = 0;
        
        while(!q.empty())
        {
            int size = q.size();
            int mini = q.front().second;
            int first,last;
            
            for(int i =0;i<size;i++)
            {
                int idx = q.front().second - mini;
                TreeNode* node = q.front().first;
                q.pop();
                
                if(i == 0)
                    first = idx;
                
                if(i == size-1)
                    last = idx;
                
                if(node -> left)
                    q.push({node -> left , 2LL * idx+1});
                    
                if(node -> right)
                    q.push({node -> right , 2LL * idx+2});
            }
            width = max(width,last - first + 1);
        }
        return width;
    }
};