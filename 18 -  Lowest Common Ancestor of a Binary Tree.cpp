/*

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

 

Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
Example 3:

Input: root = [1,2], p = 1, q = 2
Output: 1

*/

//------------------------------------------------APPROACH---------------------------------------------

Method 1 (By Storing root to n1 and root to n2 paths): 
Following is a simple O(n) algorithm to find LCA of n1 and n2. 
1) Find a path from the root to n1 and store it in a vector or array. 
2) Find a path from the root to n2 and store it in another vector or array. 
3) Traverse both paths till the values in arrays are the same. Return the common element just before the mismatch. 



Method 2 (Using Single Traversal) 
Method 1 finds LCA in O(n) time but requires three tree traversals plus extra spaces for path arrays. If we assume that 
the keys n1 and n2 are present in Binary Tree, we can find LCA using a single traversal of Binary Tree and without extra 
storage for path arrays. 
The idea is to traverse the tree starting from the root. If any of the given keys (n1 and n2) matches with the root, 
then the root is LCA (assuming that both keys are present). If the root doesn’t match with any of the keys, we recur for 
the left and right subtree. The node which has one key present in its left subtree and the other key present in the right 
subtree is the LCA. If both keys lie in the left subtree,then the left subtree has LCA also, otherwise, LCA lies in the right 
subtree.

//---------------------------------------------------------------------------------------------------------


  
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root == NULL || root == p || root == q)
            return root;
        
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        
        if(left == NULL)
            return right;
        else if(right == NULL)
            return left;
        else
            return root;
        
    }
};