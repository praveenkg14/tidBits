class MinStack {
public:
    /** initialize your data structure here. */
    
    stack<int> ds;
    vector<int> dv;
    int min;
    
    MinStack() {
        
    }
    
    void push(int x) {
        //ds.push(x);
        dv.push_back(x);
    }
    
    void pop() {
        //ds.pop();
        dv.pop_back();
    }
    
    int top() {
        //return (ds.top());
        return (dv.back());
    }
    
    int getMin() {
        
        min = dv[0];
        int n = dv.size();
        for (int i = 0; i < n; i++)
        {
            if (min > dv[i])
                min = dv[i];
        }
        return min;
        
        
        /*
        int n = ds.size();
        
        if (n == 0)
            return 0;
        if (n == 1)
            return (ds.top());

        vector<int> array;
        
	    while(!ds.empty()) 
        {
		    array.push_back(ds.top());
		    ds.pop();
	    }
        
        min = array[n-1];
        for (int i = n-1; i >= 0; i--)
        {
            if (min > array[i])
                min = array[i];
            ds.push(array[i]);
            
        }
        */
        
        return min;
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