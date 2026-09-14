class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> sml_to_lft(n,-1);
        vector<int> sml_to_rgt(n,n);

        stack<int> st;
        st.push(0);
        for(int i=1;i<n;i++){
            while(!st.empty()){
                int tp = st.top();
                if(heights[tp] < heights[i]){
                    sml_to_lft[i] = tp;
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
        while(!st.empty()) st.pop();
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!st.empty()){
                int tp = st.top();
                if(heights[tp] < heights[i]){
                    sml_to_rgt[i] = tp;
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
        int res =0;

        for(int i=0;i<n;i++){
            res = max(res, (sml_to_rgt[i] - sml_to_lft[i]-1)*heights[i]);
        }

        return res;

    }
};
