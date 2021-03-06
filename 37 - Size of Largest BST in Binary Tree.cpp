/*

Problem Statement
You are given a binary tree with 'N' nodes. Your task is to return the size of the largest subtree of the binary tree which is also a BST.
A binary search tree (BST) is a binary tree data structure which has the following properties.
• The left subtree of a node contains only nodes with data less than the node’s data.
• The right subtree of a node contains only nodes with data greater than the node’s data.
• Both the left and right subtrees must also be binary search trees.
Input Format:
The first line contains an Integer 'T' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of input contains the elements of the tree in the level order form separated by a single space.

If any node does not have a left or right child, take -1 in its place. Refer to the example below.

Example:

Elements are in the level order form. The input consists of values of nodes separated by a single space in a single line. In case a node is null, we take -1 in its place.

For example, the input for the tree depicted in the below image would be :

1
2 3
4 -1 5 6
-1 7 -1 -1 -1 -1
-1 -1

Explanation :
Level 1 :
The root node of the tree is 1

Level 2 :
Left child of 1 = 2
Right child of 1 = 3

Level 3 :
Left child of 2 = 4
Right child of 2 = null (-1)
Left child of 3 = 5
Right child of 3 = 6

Level 4 :
Left child of 4 = null (-1)
Right child of 4 = 7
Left child of 5 = null (-1)
Right child of 5 = null (-1)
Left child of 6 = null (-1)
Right child of 6 = null (-1)

Level 5 :
Left child of 7 = null (-1)
Right child of 7 = null (-1)

The first not-null node (of the previous level) is treated as the parent of the first two nodes of the current level. The second not-null node (of the previous level) is treated as the parent node for the next two nodes of the current level and so on.

The input ends when all nodes at the last level are null (-1).
Note :
The above format was just to provide clarity on how the input is formed for a given tree. 

The sequence will be put together in a single line separated by a single space. Hence, for the above-depicted tree, the input will be given as:

1 2 3 4 -1 5 6 -1 7 -1 -1 -1 -1 -1 -1
Output Format :
For each test case, print an integer denoting the largest size of the subtree of the binary tree which is also a BST.
Note:
You do not need to print anything; it has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 100
1 <= N <= 5000
1 <= data <= 10^5 and data!=-1

Time Limit: 1sec
Sample Input 1 :
2
5 2 4 1 3 -1 -1 -1 -1 -1 -1 
2 1 3 -1 -1 -1 -1
Sample Output 1:
3
3
Explanation for Sample 1:
The BST corresponding to the first test case is-

The subtree rooted at 2 is a BST and its size is 3.

The BST corresponding to the second test case is -

The subtree rooted at 2 is a BST and its size is 3.
Sample Input 2 :
1
50 -1 20 -1 30 -1 40 -1 50 -1 -1
Sample Output 2:
4

*/

/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

class NodeValue
{
    public:
    int minNode,maxNode,maxSize;

    NodeValue(int minNode,int maxNode,int maxSize)
    {
        this -> minNode = minNode;
        this -> maxNode = maxNode;
        this -> maxSize = maxSize;
    }
    
};

NodeValue findBST(TreeNode<int> * root)
{
    if(root == NULL)
    {
        return NodeValue(INT_MAX,INT_MIN,0);
    }
    
    auto l = findBST(root -> left);
    auto r = findBST(root -> right);
    
    if(l.maxNode<root -> data && root -> data<r.minNode)
    {
        return NodeValue(min(root->data,l.minNode),max(root->data,r.maxNode),1+l.maxSize+r.maxSize);
    }
    
    return NodeValue(INT_MIN,INT_MAX,max(l.maxSize,r.maxSize));
}

int largestBST(TreeNode<int>* root) 
{
    // Write your code here.
    return findBST(root).maxSize;
}
