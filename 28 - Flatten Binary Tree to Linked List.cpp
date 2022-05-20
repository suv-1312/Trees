/*

Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list 
and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
 

Example 1:


Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [0]
Output: [0]

*/


//------------------------------------FIRST-------------------------------------------------


class Solution {
    private:
    
    void getPreOrder(TreeNode* root,vector<int> &pre)
    {
        if(root == NULL)
            return;
        
        pre.push_back(root -> val);
        getPreOrder(root -> left,pre);
        getPreOrder(root -> right,pre);
    }
public:
    void flatten(TreeNode* root) {
        
        if(root == NULL)
            return;
        vector<int> pre;
        
        getPreOrder(root,pre);
        
        TreeNode* temp = root;
        
        root = new TreeNode(root -> val);
        root -> left = NULL;
        for(int i =1; i< pre.size();i++)
        {      
           TreeNode *node = new TreeNode(pre[i]);
           temp -> right = node;
            temp -> left = NULL;
            temp = temp -> right;
        }
        
    }
};


//------------------------------------SECOND-------------------------------------------------

class Solution {
    TreeNode* prev = NULL;
public:
    void flatten(TreeNode* root) {
        
        if(root == NULL)
            return ;
        
        flatten(root -> right);
        flatten(root -> left);
        
        root -> right = prev;
        root -> left = NULL;
        
        prev = root;
        
    }
};


//------------------------------------THIRD-------------------------------------------------


class Solution {
public:
    void flatten(TreeNode* root) {
       
        if(root == NULL)
            return;
        
        stack<TreeNode*> st;
        st.push(root);
        
        while(!st.empty())
        {
            TreeNode* curr = st.top();
            st.pop();
            
            if(curr -> right)
                st.push(curr -> right);
            
            if(curr -> left)
                st.push(curr -> left);
            
            if(!st.empty())
                curr -> right = st.top();
            
            curr -> left = NULL;
        }
    }
};

//------------------------------------MORRIS-------------------------------------------------


class Solution {
    TreeNode* prev = NULL;
public:
    void flatten(TreeNode* root) {
        
        if(root == NULL)
            return;
        
        TreeNode* curr = root;
        while(curr!=NULL)
        {
            if(curr -> left != NULL)
            {
                 prev = curr -> left;
                 while(prev -> right)
                 {
                     prev = prev -> right;
                 }
                
                prev -> right = curr -> right;
                curr -> right = curr -> left;
                curr -> left = NULL;
            }
            curr = curr -> right;
        }
    }
};