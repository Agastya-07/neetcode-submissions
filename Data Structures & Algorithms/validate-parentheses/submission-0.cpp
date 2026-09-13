class Solution {
public:
    bool isValid(string st) {
        stack<char> s;
        for(char c: st){
            if(s.empty()){
                s.push(c);
            }
            else{
                if((s.top() == '[' && c == ']') || (s.top() == '(' && c == ')') || (s.top() == '{' && c == '}')){
                    s.pop();
                }
                else{
                    s.push(c);
                }
            }
        }

        if(s.empty()) return true;
        return false;
    }
};
