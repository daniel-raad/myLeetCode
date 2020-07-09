/**
    Problem 1: 
    Two Sum 
    
    Given an array of integers, return indices of the two numbers such that they add up to a specific target.
  
    You may assume that each input would have exactly one solution, and you may not use the same element twice.
**/ 



class Solution {
public:


  /**
      
      Solution 1 was my brute force attempt, starting at a point and going through the entire array to see if its partner is there.
      If not, move to the next element in the array and repeating the process. If found add both to the vector and return. O(n^2).
  
  **/
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j ++){
                if(nums[i] + nums[j] == target){
                    result.push_back(i); 
                    result.push_back(j); 
                }
            }
        }
        
        return result; 
    }
    
    
    
    /**
        The second solution I tried was using a hashmap. In cpp it is a unordered_map. The reason a hash_map is better is because lookup in a hashmap is done with
        hashing, which has O(1) lookup time. A hashing function is used which stores the value in a bucket which can be quickly looked up as the function can 
        be used on the value you are looking for, which is just one function, so therefore O(1). 
        
        You calculate the complement, and if it is found, you can return it. This means, at worst case you will only need one pass so this is O(n). 
    
    */
    
      vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int,int> map; 
        for(int i = 0; i < nums.size(); i++){
            int complement = target - nums[i]; 
            if(!(map.find(complement) == map.end())){
                result.push_back(i); 
                result.push_back(map.at(complement)); 
                return result; 
            }            
            map[nums[i]] = i; 
        }
        
        return result; 
    }
};  
  
  
  

    
    
    
 
