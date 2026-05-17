class Solution {
public:
    int trap(vector<int>& height) {
       int size{static_cast<int>(height.size())}, l_max{height.at(0)}, r_max{height.at(size - 1)};
       int l{0}, r{size - 1};
       int trapped{0}, left{0}, right{0};
       while(l < r){
            if(l_max <= r_max) {
                l++;
                left = height.at(l);
                trapped += max(0, l_max - left); 
                l_max = max(left, l_max);
            } else {
                r--;
                right = height.at(r);
                trapped += max(0, r_max - right); 
                r_max = max(right, r_max);
            }
       }
       return trapped;
    }
};
