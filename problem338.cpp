/**

338. Counting Bits

I did not do this one myself. I spent "some" time trying to figure out the patterns in the bits and didnt really notice there were a few obvious ones. My train of thought was taking me down dividing it by 2 to see how many 1s it would need. In hindisight the patterns were right in front of me and just needed some staring at. This would make for one of those interview type observation questions where you need to find the patterns between the numbers. 

Here the patterns were, that the numbers shift every time you add a new one: 

[0] -> [1]

[0, 1] + [1, 2]

[0,1,1,2] + [1,2,2,3]

[0,1,1,2,1,2,2,3] + [1,2,2,3,2,3,3,4]

[0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4] + []....



Additionally, another pattern was that an odd number increase by 1 from the previous answer and an even number takes the same as its half. 

0 1 2 3 4 5 6 7 8 9 10 11 12 13
0 1 1 2 1 2 2 3 1 2 2   3 2  3


6 takes 3
8 takes 4 



I also found a solution on leetcode which made use of the bitwise AND operator. the and operator ands all the bits 
for example 

5 = 101
4 = 100 

5 & 4 = 100 = 4 

6 = 110 
5 = 101 

5 & 6 = 100 = 4 

7 = 111
6 = 110 

7 & 6  = 110 = 5 

This led to another pattern being seen which is if you and n & (n-1) and add 1 to its solution. You get the correct solution 
*/




class Solution {
public:


// Solution 1: 
    vector<int> countBits(int num) {
        vector<int> result(num+1, 0); 
        for(int i = 1; i <= num; i++ ){
            if(i % 2 == 1) result[i] = result[i-1] + 1; 
            else result[i] = result[i/2]; 
        }
        
        return result; 
    }
    
// Solution 2: Bitwise &
    vector<int> countBits(int num) {
        vector<int>ans (num+1,0);
        
        for(int i = 1; i <= num; i++){
            ans[i] = ans[(i &(i-1))]+1;
        }
        return ans;
    }
};