



// run using: g++ -std=c++11 -O2 -Wall problem70.cpp -o problem70
/**
	

	Problem 70: Climbing Stairs

	You are climbing a stair case. It takes n steps to reach to the top.
	Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?


	My initial approach was the recursive approach as I realised the base cases will always be 1 way for 1, step 2 way for 2 steps and 3 ways for 3 steps. Therefore every possible route should go down a tree of either taking 1 step or 2 step and continuing down to the base cases which can add to the overall score. This creates a lot of branches especially in higher values and so is not an entirely efficient result, as it is exponential. 

	However, it was a start in realising that the result will follow a similar to fibonacci route. As you find this, you can apply dynamic programming as this breaks up the problem and keeps the optimal solution without having to go through all the extra steps seen in the recursive algorithm. This makes this solution the best solution.



**/



    #include <iostream>
    #include <sstream>
    #include <vector>
    using namespace std;  
    using namespace std::chrono; 




	int recursive(int n){ 
        int answer = 0; 
        if(n  == 1) { 
            return 1; 
        } else if (n == 2){
            return 2; 
        } else if (n == 3) {
            return 3; 
        } else if (n < 0){
            return 0; 
        }
        
        
        answer = answer + recursive(n - 2) + recursive(n - 1); 
        
        return answer;
	}

	int dynamic(int n){
		int f[n+4]; 
        
        f[0] = 0; 
        f[1] = 1; 
        f[2] = 2; 
        f[3] = 3; 
        
        
        for(int i = 4; i <= n; i++ ){
            f[i] = f[i-1] + f[i-2]; 
        }
        
        return f[n];  


	}



    int main(){

		//input the numbers you would like into the vector 
		//practise using cin and cout for cpp 
		string line; 
		int number; 
	

		cout << "Enter the number of steps: ";
		cin >> number; 
		

		auto start2 = high_resolution_clock::now(); 
        int attempt2 = dynamic(number); 
        auto stop2 = high_resolution_clock::now(); 

        auto duration2 = duration_cast<microseconds>(stop2 - start2); 

		auto start = high_resolution_clock::now(); 
        int attempt1 = recursive(number); 
        auto stop = high_resolution_clock::now(); 

        auto duration = duration_cast<microseconds>(stop - start); 



        cout << "Recursive: ";
        cout << attempt1 << "\n";
        cout <<  " : Time taken: " << duration.count() <<  " microseconds" << "\n" ; 
        
        cout << "Optimal: ";
        cout << attempt2 << "\n";
        cout << " : Time taken: " <<  duration2.count() << " microseconds" << "\n";

        return -1; 
	}
