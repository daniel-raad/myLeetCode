    /**

        Problem 155. Min Stack 
        
        Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

        push(x) -- Push element x onto stack.
        pop() -- Removes the element on top of the stack.
        top() -- Get the top element.
        getMin() -- Retrieve the minimum element in the stack.
 
        

    */ 

    /**
        
        Probably my favourite question so far. 
        Initially I didnt recognise that you could use stacks to help build the min stack, so I was using arrays
        and maps to try and find a way to return the min value. This did not work as you can't return a value 
        in constant time, as maps use a tree which while it is O(1) to add the min value, when you wish to add a 
        value to the tree it is O(n); 

        Once I started using the stack, I realised it is using a similar hashing function to a hashtable. 
        There is a function which takes a new min value being pushed in, and saves both it and the min value 
        before it by using the function. This can save a whole chain of min values. 

        If a value is popped and its value is less than the min value, this is the signal that current min value is being popped
        and so the function reveals what the real min value is, while also setting the min value to the other min value in the stack.


        the function is 2*newMin - oldMin = hashcodeValue. when pushing 

        The hashcode value is what is stored on the stack. It will always be smaller than the new min and so will be recognisable.  

        and when popping the min value, the function is 2*newMin - hashcodeValue = oldMin 



        This technique, hashing, is useful and should be thought about whenever doing problems similar to this as its constant time 
        provides quick solutions. 
    */
    

class MinStack {
public:
    /** initialize your data structure here. */
    stack<long> mystack; 
    long min; 
    
    MinStack() {
    }
    
    void push(int x) {  
        long a = (long) x; 
        if(mystack.empty()) {
            mystack.push(a); 
            min = a; 
        } else if(a < min) { 
            mystack.push(2*a - min); 
            min = a; 
        } else {
            mystack.push(x); 
        }
    }
    
    void pop() {
        long popped = mystack.top(); 
        if(popped < min) min = min*2 - popped; 
        
        mystack.pop(); 
    }
    
    int top() {
        if(mystack.top() < min) return min; 
        return (int) mystack.top(); 
    }
    
    int getMin() {
        return (int) min; 
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */