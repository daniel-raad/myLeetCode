/**


Problem 337: House Robber III 


The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." 
Besides the root, each house has one and only one parent house. 
After a tour, the smart thief realized that "all houses in this place forms a binary tree". 
It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.


I have now started focusing on certain problems. At the moment i will work on depth first search.  
This in particular is Depth first search to do with dynamic programming.


Dynamic programming is possible here thanks to the overlapping nature of finding which path is best. You check each node several times,
so to improve this you can save the nodes result and use it again later (memoisation). 

This is done with a bottoms up approach, finding the results out at the bottom first and allowing the parent to choose the max of two values.




*/


    int rob(TreeNode* root) {
        
        if(!root) return 0;
        
        vector<int> result = robSum(root);    
        return max(result[0], result[1]);
        
        
    }
    
    vector<int> robSum(TreeNode* root){
        vector<int> ans(2,0); 
        if(root == NULL ) return ans; 
        
        vector<int> left  = robSum(root -> left);
        vector<int> right = robSum(root -> right); 
        
        ans[0] = max(left[0], left[1]) + max(right[0], right[1]); 
        ans[1] = root->val + left[0] + right[0]; 
        return ans; 
    }
