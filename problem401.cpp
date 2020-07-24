/**

Problem 401: Binary watch

A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).
Each LED represents a zero or one, with the least significant bit on the right.
Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.


This is a backtracking problem alongside bit manipulation. This was a complete pain. 
I started with a bit string of length 10, all 0s. Then i make all possible answers, changing one bit at a time. 
and either when i have got to the end of the bit string, or have the correct number of 1s, i finish. 
*/



class Solution {
public:
    
    vector<string> ans; 
    vector<string> readBinaryWatch(int num) {
        if(num == 0){ 
            ans.push_back("0:00"); 
            return ans; 
        }
        bitset<10> myset(string("0000000000"));
        readBinary(num, myset,0);
        return ans; 
    }
    
    void readBinary(int val, bitset<10> myset, int count){
        if(myset.count() == val){
            string answer = myset.to_string(); 
            bitset<4> hours(answer.substr(0,4)); 
            bitset<6> minutes(answer.substr(4,6)); 
            int minsint = minutes.to_ulong();
            int hourint = hours.to_ulong();
            if(hourint > 11) return; 
            if(minsint > 59) return;    
            string mins; 
            string hour = to_string(hourint);
            (minutes.to_ulong() < 10) ? mins = "0" + to_string(minutes.to_ulong()) : mins = to_string(minutes.to_ulong()); 
            ans.push_back(hour + ":" + mins); 
            return; 
        } else if( count == 10) return; 
                          
        readBinary(val, myset, count + 1);
        myset[count] = 1; 
        readBinary(val, myset,count + 1);
    }
};