class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
       sort(piles.begin(), piles.end());
       int low {1}, high = piles.at(piles.size() - 1);
       int min_speed {piles.at(piles.size() - 1)};
       while(low <= high) {
            int m = (high + low) / 2;
            int hours {};
            for(const int& p : piles){
                hours += ceil(double(p) / m);
            } 
            if(hours <= h) {
                min_speed = m;
                high = m -1;
            } else {
                low = m + 1;
            }
       }
       return min_speed;
    }
};
