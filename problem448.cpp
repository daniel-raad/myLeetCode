/**

	Problem 448. Find all numbers disappeared in arrays




Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.



**/


// run using: g++ -std=c++11 -O2 -Wall problem448.cpp -o problem448
/**


Solution: 

My initial attempt was to sort the array using the inbuilt C++ sort.

This would mean that the solution could only work at O(nlogn), 
however, it effectively finds and uses in  O(1) space, as it does not require to create a new array. 
However, it is not the optimal result. 
Once you have the array ordered, you know all values after the last value in the array which are smaller than the size of the array
need to be added, as well as any values missed between two consecutive indexes. ie 1,2,2,4,4, is missing 3 between 2 and 4 and is missing
the 5 after the 4. so these will be added. 


The optimal result was found by using the index positions. 
For example
[1, 1, 2, 2] should return [3,4]

therefore go through the array, and find at position 0, the value is 1, go to 1 - 1, and mark the value of index 0 as a negative value.
You will find that indexes 2 and 3 are not marked with a negative value. And so you can add the index + 1 into the results array. 
This is O(n) as you only need to peform a forloop to make this happen. 

**/ 



    #include <iostream>
    #include <sstream>
    #include <vector>
    using namespace std;  
    using namespace std::chrono; 






    vector<int> mySortAttempt(vector<int> nums){ 
            
        if(nums.size() == 0){
            return nums;
        }
        
        sort(nums.begin(), nums.end() );
        int size = nums.size(); 
        int current = 0 ; 
        int next; 
        
        if(nums.back() != size){
            for(int i = nums.back() + 1; i <= size; i++){
                nums.push_back(i);
            }
        }
        
        for(int i = 0; i < size; i++){
            next = nums[i]; 
            if(next - current > 1){
                for(int a = next - current - 1; a >= 1 ; a -- )
                    nums.push_back(next - a);
            }
            current = nums[i];
          
        }
        
        nums.erase(nums.begin(), nums.begin() + size  ); 
      
        
        return nums;

    }



    vector<int> optimalSolution(vector<int> nums){
        
        int j;
        int size = nums.size(); 
        for(int i = 0; i < size; i++){
            j = abs(nums[i]) - 1; 
            nums[j] = abs(nums[j]) * -1; 
        }
        
        for(int i = 0; i < size; i++){
            if(nums[i] > 0){
                nums.push_back(i + 1);
            }
        }    

        nums.erase(nums.begin(), nums.begin() + size  ); 
      
        
        return nums;


    }



    int main(){

		//input the numbers you would like into the vector 
		//practise using cin and cout for cpp 
		string line; 
		int number; 
		vector<int> numbers; 

		cout << "Enter numbers separated by spaces: ";
   		getline(cin, line);
    	istringstream stream(line);
    	while (stream >> number)
        	numbers.push_back(number);



		auto start = high_resolution_clock::now(); 
        vector<int> attempt1 = mySortAttempt(numbers); 
        auto stop = high_resolution_clock::now(); 

        auto duration = duration_cast<microseconds>(stop - start); 

        auto start2 = high_resolution_clock::now(); 
        vector<int> attempt2 = optimalSolution(numbers); 
        auto stop2 = high_resolution_clock::now(); 

        auto duration2 = duration_cast<microseconds>(stop2 - start2); 

        cout << "Basic: ";
        for(int n : attempt1){ cout << n << ",";  };  
        cout <<  " : Time taken: " << duration.count() <<  " microseconds" << "\n" ; 
        
        cout << "Optimal: ";
        for(int n : attempt2){ cout << n << "," ;};   
        cout << " : Time taken: " << duration2.count() << " microseconds" << "\n";

        return -1; 
	}

























