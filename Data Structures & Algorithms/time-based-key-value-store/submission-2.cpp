class TimeMap {
private:
    map<string, vector<pair<int,string>>> logs;
public:
    TimeMap() : logs{}{
        
    }
    
    void set(string key, string value, int timestamp) {
        if(logs.contains(key))
            logs[key].push_back(make_pair(timestamp, value)); 
        else 
            logs[key] = {make_pair(timestamp, value)}; 
    }
    
    string get(string key, int timestamp) {
        auto retrieve = logs.find(key);
        if(retrieve == logs.end())return "";
        if(timestamp < retrieve->second.at(0).first) return "";
        int low {0}, high = retrieve->second.size() - 1;
        auto max_found =retrieve->second.at(0);
        while(low <= high) {
            int m = low + (high - low) / 2;
            cout << retrieve->second.at(m).first << " ";
            if(retrieve->second.at(m).first <= timestamp) {
                max_found = max_found.first > retrieve->second.at(m).first ? max_found : retrieve->second.at(m);
                low = m + 1;
            } else high = m - 1;
        }
        return max_found.second;
        
    }
};
