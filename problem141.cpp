


/**


Problem 141: linked list cycle

Given a linked list, determine if it has a cycle in it.



Two solutions below: 

The first solution I arrived at was the hasCycleSlow. This involves using an unorderedset (for o(1) lookup speeds) to store the pointers as we visit each node. When you visit the next node, you can lookup whether that pointer has already been visited. If it has, you can then say that there is a cycle. This works, however, is very slow and not ideal. 


The optimal solution involves using Floyds Algorithm of the hare and the tortoise. Two pointers moving at different speeds and so if there is a cycle, you will get these two pointers to point to each other at one point. 



*/




bool hasCycleOptimal(ListNode* head){

	    if(head == NULL ) return false; 
        ListNode* fast = head; 

        
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next; 
            head = head -> next; 
            
            if(fast == head) return true; 
        }
        
        return false; 

}



bool hasCycleSlow(ListNode* head){
        unordered_set<ListNode*> set; 
        if(head == NULL) return false; 
        
        while(head->next != NULL ){
             if(set.find(head) != set.end()) return true;
             set.insert(head);
             head = head->next; 
        }
        return false;
}