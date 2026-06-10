struct LN {
    int val, key;
    LN* next;
    LN* prev;
    LN(int k, int v) : key{k}, val{v}, next{nullptr}, prev{nullptr}{
    }
};

class LRUCache {
    unordered_map<int, LN*> nums{};
    LN* head;
    LN* tail; 
    int count;
    
public:
    LRUCache(int capacity) : count{capacity}, head{new LN(0,0)}, tail{new LN(0,0)}{
        head->next=tail;
        tail->prev = head;
    }

    void remove(LN* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = nullptr;
        node->prev = nullptr;
    }

    void add(LN* node) {
        LN* prev = tail->prev;
        tail->prev = node;
        node->next = tail; 
        prev->next = node;
        node->prev = prev;
    }


    int get(int key) {
        if(nums.count(key)) {
            remove(nums[key]);
            add(nums[key]);
            return nums[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
       if(nums.count(key)) {
            remove(nums[key]);
       }

       LN* new_node = new LN(key, value);
       nums[key] = new_node;
       add(new_node);
       if(nums.size() > count) {
            int key = head->next->key;
            remove(head->next);
            nums.erase(key);
       }
    }
};
