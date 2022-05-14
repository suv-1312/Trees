/*

Approach: Boundary traversal in an anti-clockwise direction can be described as a traversal consisting of three parts:

Part 1: Left Boundary of the tree (excluding the leaf nodes).
Part 2: All the leaf nodes travelled in the left to right direction.
Part 3: Right Boundary of the tree (excluding the leaf nodes), traversed in the reverse direction.

*/


class Solution {

    void getLeaf(Node* root,vector<int> &ans)
    {
        if(root == NULL)
        return;
        
        getLeaf(root -> left,ans);
        if(root -> left == root -> right)
        ans.push_back(root -> data);
        getLeaf(root -> right,ans);
    }
    
public:
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> ans;
        
        //IF THERE IS NO ROOT
        if(root == NULL)
        return ans;
        
        //IF ONLY ROOT IS PRESENT
        if(root -> left == root -> right)
        {
        ans.push_back(root->data);
        return ans;
        }
        
        //---------------------------------
        //PUSHING THE ROOT FIRST IN ANS
        ans.push_back(root -> data);
        
        //STEP 1 : GETTING LEFT BOUNDARY EXCLUDING LEAF NODES
        Node *curr = root->left;
        while(curr !=NULL && curr ->left != curr->right)
        {
            ans.push_back(curr->data);
            
            if(curr -> left)
            curr = curr -> left;
            
            else if(curr->right)
            curr = curr -> right;
            
        }
        
        //STEP 2 : GETTING LEAF NODES(DO INORDER TRAVERSAL)
        getLeaf(root,ans);
        
        
        //STEP 3 : GETTING RIGHT BOUNDARY IN REVERSE ORDER EXCLUDING LEAF NODES     
         stack<int> st;         
         curr = root -> right;
        while(curr !=NULL && curr ->left != curr->right)
        {
            st.push(curr->data);
            
            if(curr -> right)
            curr = curr -> right;
            
            else if(curr->left)
            curr = curr -> left;
            
        }
        
        //REVERSING PART
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        
        //RETURN ANS
        return ans;
    }
};

