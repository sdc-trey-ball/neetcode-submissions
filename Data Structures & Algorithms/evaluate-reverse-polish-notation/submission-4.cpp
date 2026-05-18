class Solution {
public:
    int evalRPN(vector<string>& tokens) {
       stack<int> to_comp;
       char c{};
       int rhs{}, lhs{};
       for(const auto& s: tokens) {
           c = s.at(0);
            if(s == "+") {
                rhs = to_comp.top();
                to_comp.pop();
                lhs = to_comp.top();
                to_comp.pop();
                to_comp.push(lhs + rhs);
           } else if(s =="-") {
                rhs = to_comp.top();
                to_comp.pop();
                lhs = to_comp.top();
                to_comp.pop();
                to_comp.push(lhs - rhs);
           } else if(s =="*") {
                rhs = to_comp.top();
                to_comp.pop();
                lhs = to_comp.top();
                to_comp.pop();
                to_comp.push(lhs * rhs);
           } else if(s =="/") {
                rhs = to_comp.top();
                to_comp.pop();
                lhs = to_comp.top();
                to_comp.pop();
                to_comp.push(lhs / rhs);
           } else {
                to_comp.push(stoi(s));
           }
       } 
       return to_comp.top();
    }
};
