class Solution {
public:
    int trap(vector<int>& height) {
        int size = static_cast<int>(height.size());
        vector<int> fwd(size, 0), bck(size, 0);
       int max_left{height.at(0)}, max_right{height.at(size - 1)};
       for(int i {1}; i < size; ++i) {
            fwd.at(i) = max_left;
            bck.at(height.size() - 1 - i) = max_right;
            max_right = max(max_right, height.at(size - 1 - i));
            max_left = max(max_left, height.at(i));
       }
        int total_water {0};
        for(int i{0}; i < size; ++i) {
            total_water += max(0, ((min(fwd.at(i), bck.at(i))) - height.at(i)));
        }
        return total_water;
    }
};
