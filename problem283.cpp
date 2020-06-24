	

    #include <iostream>
    #include <sstream>
    #include <vector>
    using namespace std;  
    using namespace std::chrono; 



// to compile 
    // g++ -std=c++11 -O2 -Wall problem283.cpp -o problem283

/** 

this attempt demonstrates solving the problem but without doing it in place. Here we add all the non-zero values to a new vector,
keeping a count of however many 0s we have seen and adding them after. This is O(n) for space complexity as well as O(n) for time complexity

**/ 

    vector<int> basicAttempt(vector<int>& nums){
        vector<int> result; 
        int count = 0; 
        for(int n : nums ){
            if (n != 0 ){
                result.push_back(n); 
            } else { 
                count++; 
            }
        }

        while(count > 0 ){
            count--; 
            result.push_back(0); 
        }

        return result; 
    } 


/**

Here, it remains O(n) for time complexity as it is just a for loop through the array, however, it is done in place, 
as a new vector is not required to be made 

**/ 

    vector<int> constantSpace(vector<int>& nums){

        int nonZeroPos = 0; 

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0 ){
                nums[nonZeroPos++] = nums[i]; 
            } 
        }

        for(int i = nonZeroPos; i < nums.size(); i++){
            nums[i] = 0; 
        }


        return nums; 
    }



/** 

While this is also O(n) time complexity and O(1) space complexity,
this provides a better solution as it does so in optimal steps 

*/
    vector<int> optimumTime(vector<int>& nums){
        
        int nonZeroPos = 0 ; 
        for(int i = 0; i < nums.size(); i++ ){
            if(nums[i] != 0){
                swap(nums[nonZeroPos++], nums[i]); 
            }
        }
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
        vector<int> attempt1 = basicAttempt(numbers); 
        auto stop = high_resolution_clock::now(); 

        auto duration = duration_cast<microseconds>(stop - start); 

        auto start2 = high_resolution_clock::now(); 
        vector<int> attempt2 = constantSpace(numbers); 
        auto stop2 = high_resolution_clock::now(); 

        auto duration2 = duration_cast<microseconds>(stop2 - start2); 

        auto start3 = high_resolution_clock::now(); 
        vector<int> attempt3 = optimumTime(numbers); 
        auto stop3 = high_resolution_clock::now(); 

        auto duration3 = duration_cast<microseconds>(stop3 - start3); 

        cout << "Basic 1: ";
        for(int n : attempt1){ cout << n << ",";  };  
        cout <<  " : Time taken: " << duration.count() <<  " microseconds" << "\n" ; 
        cout << "Answer 2: ";
        for(int n : attempt2){ cout << n << "," ;};   
        cout << " : Time taken: " << duration2.count() << " microseconds" << "\n";
        cout << "Answer 3: ";
        for(int n : attempt3){ cout << n << ","; };  
        cout <<  " : Time taken: " << duration3.count() << " microseconds" << "\n";

        return -1; 
	}







