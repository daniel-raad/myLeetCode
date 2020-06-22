// leetcode problem 169. Majority Element 





// to compile use 
// g++ -std=c++11 -O2 -Wall problem169.cpp -o problem169
// ./problem 169


	#include <iostream>
	#include <sstream>
	#include <vector>
	using namespace std;  
	using namespace std::chrono; 



	int majorityElementSort(vector<int> &nums){
    //sorting the entire vector first then passing then returning the middle number which should be the majority 
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2 ]; 
    }

    int majorityElementBoyes(vector<int> &nums){
    	//counting the majority element as +1 and other elements as -1 
        int count = 0; 
        
        int candidate = -1; 
        
        for(int num : nums){
            
            if (count == 0){
            	//this resets the majority element after they have been cancelled out by each other 
            	//e.g you have found 3 5s and 3 7s
                candidate = num; 
            }
            
            count += (num == candidate) ? 1 : - 1; 
            
        }
        
        return candidate; 
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
        int majorityElementSortVal = majorityElementSort(numbers); 
        auto stop = high_resolution_clock::now(); 

        auto duration = duration_cast<microseconds>(stop - start); 

        auto start2 = high_resolution_clock::now(); 
        int majorityElementBoyesVal = majorityElementBoyes(numbers);
        auto stop2 = high_resolution_clock::now(); 

        auto duration2 = duration_cast<microseconds>(stop2 - start2); 

        cout << "Sorting first: " << majorityElementSortVal  <<  " : Time taken: " << duration.count() <<  " microseconds" << "\n" ; 
        cout << "Boyes Algorithm: " << majorityElementBoyesVal << " : Time taken: " << duration2.count() << " microseconds" << "\n";

        return -1; 
	}

/** 
The results show that the Boyes algorithm is evidently faster even in small problems. This is because the sorting algorithm requires O(nlogn)
to sort the array first. Therefore despite the code being shorter, as the input gets larger, this is not a good solution. 
Boyes algorithm on the other hand provides a more suitable solution to this problem, efficiently solving the problem in O(1) time. 

**/ 



