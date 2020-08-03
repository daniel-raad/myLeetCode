/**


Problem 746: Min cost climbing stairs 


On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).

Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.



Two strategies are implemented here - dynamic programming for the first solution, where we are memoising 
parts of the problem which have been calculated and calculating all possible routes. This is good as it prevents you from 
calculating one part over and over again. This is accepted but is one of the slower solutions. 

The second strategy is a mixture of greedy and dynamic programming. It saves the solutions as we calculate them, but in the array which is being used to store the initial values. Therefore it is just updating the cost array with the minimum cumulated value. 

**/ 




class Solution {
public:
    
    unordered_map<int,int> memo; 
    int size;
    
    int minCostClimbingStairs(vector<int>& cost) {

    // can return one of either 
        size = cost.size(); 
        return min(dpSolution(cost, 0), dpSolution(cost,1));
        
        return optimumSolution(cost); 
        
    }
    
    int dpSolution (vector<int>& cost, int idx){
        if(idx >= size) return 0; 
        
        if(memo.find(idx) != memo.end()){
            return memo.at(idx); 
        }
 
        int value1 = cost[idx] + dpSolution(cost, idx + 1); 
        int value2 = cost[idx] + dpSolution(cost, idx + 2); 
        
        memo.insert({idx, min(value1,  value2)}); 
        return(min(value1, value2));
    }
    
    int optimumSolution(vector<int>& cost){
        int i; 
        for(i = 2 ; i < cost.size(); i++){
            cost[i] += min(cost[i-1], cost[i-2]);
        }
        return min(cost[i - 1], cost[i-2]); 
    }
    
};