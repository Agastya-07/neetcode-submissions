class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        stack<int> st;
        vector<int> res(n,0);
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            int x = temp[i];
            while(!st.empty()){
                if(temp[st.top()] > x){
                    res[i] = st.top()-i;
                    st.push(i);
                    break;
                }
                else{
                    st.pop();
                    if(st.empty()){
                        st.push(i);
                        break;
                    }
                }
            }
        }
        return res;
    }
};
