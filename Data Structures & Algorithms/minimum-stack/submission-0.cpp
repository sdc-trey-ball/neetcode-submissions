class MinStack {
    int cur_index {-1};
    int arr[1000] = {};
    int min_collection[1000] = {};
public:
    MinStack() {
        cur_index = -1;
    }
    
    void push(int val) {
       arr[++cur_index] = val; 
       if(cur_index == 0) {
            min_collection[cur_index] = val;
       } else {
            min_collection[cur_index] = min(min_collection[cur_index - 1], val);
       }
    }
    
    void pop() {
       cur_index--; 
    }
    
    int top() {
       return arr[cur_index];
    }
    
    int getMin() {
       return min_collection[cur_index]; 
    }
};
