/**

234. Palindrome Linked List

Given a singly linked list, determine if it is a palindrome.



This was another interesting problem in which I needed to use the two pointer technique. 

My initial attempt, as always, is to find the normal solution which does not run in O(1) space and O(N) time. 
This involved using a vector and adding all the values to the list, making a reverse copy of the list and 
then going through both lists at the same time comparing them. If two values are not the same then return false. This required 
O(n) space as it will require an array the size of the linked list. 

The optimal solutions used the two pointer technique, initially it was used to find the middle of the linked list. you use the fast 
pointer to reach the end, which it will do exactly as the same time as the slow pointer reaches the middle. fast = fast -> next ->next 
and slow = slow -> next; this will reach the middle node. From this point on you use the slow pointer to reverse the linked list. Then once it is reversed, you can check if both lists are the same. 
*/


	bool isPalindromeNormal(ListNode* head){
	    if(!head) return true; 
        vector<int> mylist; 
        
        while(head){
            mylist.push_back(head->val); 
            head = head->next; 
        }
        
        vector<int> secondlist = mylist; 
        reverse(secondlist.begin(), secondlist.end());
        
        for(int i = 0; i < mylist.size(); i++){
            if(mylist.at(i) != secondlist.at(i)) return false; 
        }
        
        return true; 
	}



	bool isPalindromeOptimal(ListNode* head) {
        
 
        ListNode *fast = head, *slow = head; 
        
        while(fast && fast -> next){
            fast = fast -> next -> next; 
            slow = slow -> next; 
        }
        
        fast = head; 
        
        ListNode *temp = NULL, *prev = NULL;
        while(slow){
            temp = slow->next; 
            slow->next = prev; 
            prev = slow; 
            slow = temp; 
        }
        
        slow = prev; 
       
        
        while(slow){
            if(slow->val != fast -> val) return false; 
            slow = slow -> next;
            fast = fast -> next;
        }
        
        return true;
    }