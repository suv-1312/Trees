/*

Given a binary tree with distinct nodes(no two nodes have the same data values). The problem is to print the path from root to a given node x. If node x is not present then print “No Path”.

Examples: 

Input :          1
               /   \
              2     3
             / \   /  \
            4   5  6   7

               x = 5

Output : 1->2->5

*/



//-----------------------------------------------APPROACH-----------------------------------

Approach: 

We will use an external list to store our path. This list will be passed by reference to our recursive function. 
Moreover, we can set the return value of our function as boolean, this will help us to know whether node V was found in a subtree or not.

The algorithm steps can be stated as follows:

1. We pass the function with our root node, the path list and node V.

2. For the base case, if root is pointing to NULL, we return false as clearly node V can’t be found.

3. Now we first push the node to our path list.

4. Then we check whether the current node is the target node or not, if it is then no further execution 
   is needed and we return to the parent function.

5. If not, then we recursively call its left and right child to find the target node V. If any one of 
   them returns true, it means we have found node V at lower levels and return true from the current function.

6. If the value is not found at the current node and neither in any of the recursive calls, it means 
   that the value is not present in the current sub-tree, therefore we pop out the current node from the path list and return false.

//---------------------------------------------------------------------------------------------------



#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

bool getPath(node * root, vector < int > & arr, int x) {
  // if root is NULL
  // there is no path
  if (!root)
    return false;

  // push the node's value in 'arr'
  arr.push_back(root -> data);

  // if it is the required node
  // return true
  if (root -> data == x)
    return true;

  // else check whether the required node lies
  // in the left subtree or right subtree of
  // the current node
  if (getPath(root -> left, arr, x) ||
    getPath(root -> right, arr, x))
    return true;

  // required node does not lie either in the
  // left or right subtree of the current node
  // Thus, remove current node's value from
  // 'arr'and then return false   
  arr.pop_back();
  return false;
}

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}

int main() {

  struct node * root = newNode(1);
  root -> left = newNode(2);
  root -> left -> left = newNode(4);
  root -> left -> right = newNode(5);
  root -> left -> right -> left = newNode(6);
  root -> left -> right -> right = newNode(7);
  root -> right = newNode(3);

  vector < int > arr;

  bool res;
  res = getPath(root, arr, 7);

  cout << "The path is ";
  for (auto it: arr) {
    cout << it << " ";
  }

  return 0;
}
