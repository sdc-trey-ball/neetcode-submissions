class Solution {
public:
    int maxArea(vector<int>& heights) {
       // two pointers from side
       // move left or right to smaller 
       // keep max and eval on cur 
       int left{0}, right{static_cast<int>(heights.size()) - 1}, max_area{0};
       int left_h {0}, right_h{0};
       while(left < right) {
            left_h = heights.at(left);
            right_h = heights.at(right);
            max_area = max(max_area, (min(left_h, right_h) * (right - left)));
            if(left_h <= right_h) {
                left++;
            } else {
                right--;
            }
       }
       return max_area;
    }
};
