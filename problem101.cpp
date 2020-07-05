/**
        Problem: 101 Symmetric tree;
        Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).


        Found this problem quite tricky, needed to use the solution. My initial attempt was to use array manipulation, however, the problem is passed through as a tree node and so it would not make sense to turn the tree node into an array first. 

        This solution I found was quite helpful in understanding how to traverse the tree and to think of the best way to solve the problem. You want to check that the head of each tree on the symmetrical side are equal. So by recursively going down both sides, you can check if the two values for either side of the tree are equal. 
            1
           / \ 
          2   2
         / \ / \ 
        3  4 4  3 
        you want to check that 2 and 2 are equal, so you recursively go left and right and check the values. 
        Then you want to see 3 and 3 are equal. 
        t1.left should be equal to t2.right, and as they are on other sides of the tree it will prove they are symmetrical. This is the same for t1.right and t2.left. So it will continuely recursively checking that all values are the same (whether or not they're null). 
**/ 




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */




class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true; 
        return isMirror(root -> left, root -> right);
    }
    
    bool isMirror(TreeNode* t1, TreeNode* t2){
        if(t1 == NULL && t2 == NULL) return true; 
        if(t1 == NULL || t2 == NULL) return false; 
        
        return isMirror(t1 -> left, t2 -> right) && 
            isMirror(t1 -> right, t2 -> left) && (t1 -> val == t2 -> val); 
    }
};