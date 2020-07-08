

/**


Problem 437. Path Sum III


Definitely the question I have found the hardest so far. Not sure what it is about tree nodes but i find them much more difficult than standard questions. Very happy I found my own solution, but it took a lot of attempts to iron out the bugs of this problem. I decided to almost nested for loop each node of the tree, finding the full possible sums from each node in the tree before moving to the next node. This proved faster than 55% and I will look into what solution may have been faster. This was just the first thing which came to mind. 


*/



/**
You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

*/



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
    int result = 0; 
    int pathSum(TreeNode* root, int sum) {
        if(root == NULL) return result; 
        if(root-> val == sum) result+=1;
        if(root -> right == NULL && root->left == NULL) {
            return result; 
        }    
        traverseTree(root, sum); 
        return result; 
        
    }
    
    void traverseTree(TreeNode* root, int sum){
        
        if(root -> left == NULL && root-> right == NULL){
            return; 
        } else if (root -> left == NULL){
            if(root->right->val == sum) result+=1; 
            isSum(root->right, sum, root->val);
            traverseTree(root->right, sum); 
        } else if(root -> right == NULL){
            if(root->left->val == sum) result+=1; 
            isSum(root->left, sum, root->val); 
            traverseTree(root->left, sum); 
        } else { 
            if(root->left->val == sum) result+=1; 
            if(root->right->val == sum) result+=1; 
            isSum(root->right, sum, root->val);
            isSum(root->left, sum, root->val); 
            traverseTree(root->right, sum);
            traverseTree(root->left, sum);
        }
    }
    
    void isSum(TreeNode* root, int sum, int current){
        
        
        current += root->val;
        if(current == sum) result+=1; 
        
        if(root->right == NULL && root->left == NULL) {
            return; 
        } else if(root->right != NULL && root->left != NULL){
            isSum(root->right, sum, current); 
            isSum(root->left, sum, current); 
        }else if(root->left == NULL) {
            isSum(root->right, sum, current); 
        }else if(root->right == NULL) {
            isSum(root->left, sum, current); 
        }
        

        
    }
    

};







/**


BELOW IS SIMILAR TO MY SOLUTION JUST MUCH TIDIER CODE while also using a list to good effect 
it performs the exact same functionality in O(n^2 ) time, however is perhaps easier to see the recursive effect 

I have not been able to find a solution which can do it faster than O(n^2) time. 

*/


    int result = 0; 
    vector<int> mylist; 
    int pathSum(TreeNode* root, int sum){
        getSum(root, sum);
        return result; 
    }
    
    
    void getSum(TreeNode* root, int sum){
        
        if(root == NULL ) return; 
        
        mylist.push_back(root -> val); 
        
        getSum(root->left, sum);
        getSum(root-> right, sum);
        
    
        
        int temp = 0; 
        for(int i = mylist.size()-1; i >= 0; i--){
            temp += mylist.at(i);
            if(temp == sum) result++; 
        }
        
        mylist.pop_back();
    } 




