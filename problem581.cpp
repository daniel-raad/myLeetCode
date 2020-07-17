/**

581. Shortest Unsorted Continuous Subarray

Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.


This question has taught me a few things: number 1, i need to spend more time thinking about the actual question. 
This was hard and needed a lot of thinking about what you really want to do. Sometimes it really is best to start with a brute force solution first. This would've benefitted from it as i wouldve realised what i am looking 
for. In this case, I was looking for the minimum element AFTER you realise the array is unsorted. I was along the right lines with my solution but this wasnt exactly what i was looking for. You then also want to find the 
maximum number in unsorted array. This helps you figure out whether or not you need to sort more than what it seems, which i got caught up on in my attempt. Sometimes id realise that a smaller number is somewhere further away. 

in this case, picturing it like a graph really helped. i have my attempts commented out. 

*/ 



class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        Attempt 1:
// would work if there were no duplicates 
//         int pos1; 
//         int pos2;
//         for(int i = 0; i < nums.size(); i++){
//             if(nums[i] > nums[i+1]){
//                 pos1 = i; 
//                  break; 
//             }
//         }
        
//         for(int i = nums.size() - 1; i > pos1; i--){
//             if(nums[i] < nums[i-1]){
//                 pos2 = i; 
//                 break;
//             }
//         }
        
        
//         return pos2 - pos1 + 1; 
        
        
        

        Attempt 2:
//         if(nums.size() == 0 || nums.size() == 1 ) return 0;
        
//         int pos1 = 0; 
//         int pos2 = 0;
        
        
//         for(int i = nums.size() - 1; i > 0; i--){
//             if(nums[i] < nums[i-1]){
  
//                 int a = i; 
//                 if(a + 1 < nums.size()){
//                     while(nums[a + 1] < nums[i - 1]){
//                         if(a + 1 < nums.size()) a++; 
//                         else break;
//                     }
//                 }
//                 pos2 = a + 1; 
//                 break;
//             }
//         }
        
        
//         for(int i = 0; i < nums.size(); i++){
//             if(i + 1 < nums.size()){
//                 if(nums[i] > nums[i+1]){
//                     int a = i; 
//                     if(a - 1 >= 0){ 
//                         while(nums[a - 1] > nums[i+1] ){
//                             if(a - 1 >= 0){
//                                 a--; 
//                             } else  break; 
//                         }
//                     }
//                     pos1 = a; 
//                     break; 
//                 }
//             }
//         }
            
        

        //CORRECT SOLUTION 
        
        if(nums.size()<2) return 0;

        int low = INT_MAX, high = INT_MIN, l, r; 
        bool flag = false; 

        //once you realise the array is unsorted, find the low and highs. 
        for(int i = 0; i < nums.size() - 1; i ++){
           if (nums[i] > nums[i + 1]){
                low = min(low, nums[i+1]);
                high = max(high,nums[i]);
                flag = true;
           }
        }

        if(!flag) return 0;       

        //go through and flag where the min and max elements need to go  
        for(l = 0; l < nums.size(); l++ ){
            if(low < nums[l]) break; 
        }
        for(r = nums.size() - 1; r >= 0; r --){
            if(high > nums[r]) break; 
        }
        

        

        
        return r - l + 1;
        

    }
};