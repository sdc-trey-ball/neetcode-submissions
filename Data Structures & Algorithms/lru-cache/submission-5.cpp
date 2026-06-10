struct LN {
    int val, key;
    LN* next;
    LN* prev;
    bool operator<(const LN &rhs) {
        return val < rhs.val && key < rhs.key;
    }
    bool operator==(const LN &rhs) const{
        return this->val == rhs.val && this->key == rhs.key;
    }
    LN(int k, int v) : key{k}, val{v}, next{nullptr}, prev{nullptr}{

    }
};

namespace std {
    template <>
    struct hash<LN> {
        size_t operator()(const LN& p) const {
            return hash<int>()(p.val);
        }
    };
}

class LRUCache {
    unordered_map<int, LN*> nums{};
    LN* head;
    LN* tail; 
    int count;
    
public:
    LRUCache(int capacity) : count{capacity}, head{nullptr}, tail{nullptr} {
        
    }
    
    int get(int key) {
        if(nums.count(key)) {
            move_to_end(key);
            return nums[key]->val;
        }
        return -1;
    }

    void move_to_end(int key) {
        LN* node = nums[key];
        if(node == tail) return;
        if(node->prev) node->prev->next = node->next;
        if(node->next) node->next->prev = node->prev;
        if(node == head) head = head->next;

        node->prev = tail;
        node->next = nullptr;

        if(tail) tail->next = node;
        tail = node;
        if(!head) head = node;
    }

    
    void put(int key, int value) {
       //is in map
        if(nums.count(key)) {
            move_to_end(key);
            nums[key]->val = value;
        } else {
            //is first entrance
            if(head == nullptr) {
                head = new LN(key, value);
                tail = head;
                nums[key] = head;
            } else {
                if((nums.size() == count)) {
                    nums.erase(head->key);
                    head = head->next;
                    if(head)
                        head->prev = nullptr;
                    else 
                        tail = nullptr;
                }
                if(head == nullptr) {
                head = new LN(key, value);
                tail = head;
                nums[key] = head;
                } else {
                tail->next = new LN(key, value);
                nums[key] = tail->next;
                tail->next->prev = tail;
                tail = tail->next;
                }                
            }
        }
    }
};
