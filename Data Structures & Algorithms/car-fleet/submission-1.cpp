class Solution {
public:
    struct fleet{
        int count;
        int position;
        int speed;
        bool operator<(const fleet &rhs) {
            return this->position < rhs.position;
        }
    };
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<fleet> fleets;
        int size {static_cast<int>(position.size())};
        int finished {0};
        for(int i{0}; i < size; ++i) {
            fleets.push_back({1, position.at(i), speed.at(i)});
        }
        sort(fleets.begin(), fleets.end(), [](fleet a, fleet b) {return a.position > b.position;});
        stack<double> counts;
        counts.push((target - fleets.at(0).position) / double(fleets.at(0).speed));
        for(int i{1}; i < size; ++i) {
            double top = counts.top();
            fleet cur = fleets.at(i);
            double cur_val = ((target - fleets.at(i).position) / double(fleets.at(i).speed));
            if(cur_val > top) counts.push(cur_val);

        } 
        return counts.size();
    }
};
