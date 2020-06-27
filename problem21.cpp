
/**


    Problem 21: Merge Two Sorted Lists: 


    Comes from the merge sort, where you need to merge two lists together after they have already been sorted. 
    My attempt is the solMergeTwoLists and while this is easy in something like Java, I had to learn how to use the pointers correctly. 
    This proved relatively challenging and took a fair amount of time trying to understand what some problems were, including NULL being 
    in caps rather than null (doh). 
    My solution is relatively verbose and so I dont think is very optimal, however achieved faster than 96% with 4ms. 

    It is relatively straightforward, and similar to the shortAndSweet I found in the discussion section. 
    Check that l1 and l2 are not null, see which one is smaller between the two and add it to a new List. Then just increment the list which was added. Nice and easy. 

    The reason I added the shortAndSweet here is because it is also important to write problems quickly, as well as making them fast. While mine is faster because it doesnt use ? and other built in functionalities, it is quite long to write. So something like shortAndSweet could potentially be better, depending on the situation. ShortandSweet took 9ms. 



**/      
    









    struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
    };



    ListNode* shortAndSweet(ListNode* l1, ListNode* l2){
        ListNode l3;
        ListNode* cur = &l3;
        
        while (l1 && l2)
        {
            (l1->val < l2->val) ? (cur->next = l1, l1 = l1->next) : (cur->next = l2, l2 = l2->next);
            cur = cur->next;
        }
        
        cur->next = (l1) ? l1 : l2;
        
        return l3.next;
    }


    ListNode* solMergeTwoLists(ListNode* l1, ListNode* l2){

        ListNode* curr = new ListNode();
        ListNode* head = curr; 
        
        if((l1) == NULL && (l2) == NULL){
            return l1;
        } else if((l1) == NULL){
            return l2;
        } else if((l2) == NULL){
            return l1;
        }
        
        while(l1 != NULL && l2 != NULL){
            if((*l1).val <= (*l2).val){
                (*curr).val = (*l1).val; 
                (*curr).next = new ListNode(); 
                curr = (*curr).next; 
                l1 = (*l1).next; 
            } else {
                (*curr).val = (*l2).val; 
                (*curr).next = new ListNode(); 
                curr = (*curr).next; 
                l2 = (*l2).next; 
            }
        }
        
        if(l1 == NULL){
            while(l2 != NULL){
                (*curr).val = (*l2).val; 
                l2 = (*l2).next; 
                if(l2 != NULL){
                    (*curr).next = new ListNode(); 
                    curr = (*curr).next; 
                }
            }
        } else if(l2 == NULL){
            while(l1 != NULL){
                (*curr).val = (*l1).val; 
                l1 = (*l1).next; 
                if(l1 !=NULL){
                    (*curr).next = new ListNode(); 
                    curr = (*curr).next; 
                }
            }
        }        
        
        return head; 

    }
