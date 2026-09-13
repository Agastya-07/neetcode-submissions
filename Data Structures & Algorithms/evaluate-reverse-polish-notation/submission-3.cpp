class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> st;
        for(string s: tokens){
            if(s == "*" || s=="+" || s=="-" || s=="/"){
                int last = st.top();
                st.pop();
                int sec_last = st.top();
                st.pop();
               

                if(s=="+"){
                    st.push(last + sec_last);
                   
                }
                else if(s == "-"){
                    st.push(sec_last-last);
                    
                }
                else if(s=="*"){
                    st.push(last * sec_last);
                    
                }
                else{
                    st.push(sec_last/last);
                }
            }

            else{
                st.push(stoi(s));
                
            }
        }

        return st.top();
    }
};
