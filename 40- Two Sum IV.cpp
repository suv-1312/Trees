/*

Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the BST such that their sum is equal to the given target.

 

Example 1:


Input: root = [5,3,6,2,4,null,7], k = 9
Output: true
Example 2:


Input: root = [5,3,6,2,4,null,7], k = 28
Output: false

*/

//----------------------------------------BRUTE FORCE---------------------------------------


class Solution {
    private:
    void fill(TreeNode* root,vector<int> &inorder)
    {
        if(root == NULL)
            return;
        
        fill(root->left,inorder);
        inorder.push_back(root->val);
        fill(root->right,inorder);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        fill(root,inorder);
        
        int i = 0,j = inorder.size()-1;
    
    while(i<j)
    {
        if(inorder[i] + inorder[j] == k)
            return true;
        
        else if(inorder[i] + inorder[j]>k)
            j--;
        else
            i++;
    }
    return false;
    }
};

//-------------------------------------BETTER-----------------------------------------------

class BSTIterator {
    private:
    stack<TreeNode*> st;
    bool reverse = true;
        
    void insert(TreeNode* root)
    {
        while(root)
        {
            st.push(root);
            
            if(!reverse)
            root = root -> left;
            
            else
            root = root -> right;
        }
    }
    public:
    
    BSTIterator(TreeNode* root,bool isReverse) {
        reverse = isReverse;
         insert(root);
    }
    
    int next() {
        
        TreeNode* top = st.top();
        st.pop();
        
        if(!reverse)
        insert(top -> right);
        else
        insert(top -> left);
        
        return top -> val;
    }
    
    bool hasNext() {
         
        return !st.empty();
    }
};

class Solution {

public:
    bool findTarget(TreeNode* root, int k) {
       
        if(root == NULL)
            return false;
        
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        
        int i = l.next();
        int j = r.next();
        
        while(i<j)
        {
            if(i+j == k)
                return true;
            else if(i+j<k)
                i = l.next();
            else
                j = r.next();
        }
        return false;
    }
};