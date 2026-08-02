class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int l=0,r=0;
        if(n==0 || n==1) return n;
        unordered_set<char> st;
        int ans=0;
        while(r<n){
            if(st.find(s[r])==st.end()){
                st.insert(s[r]);
            }
            else{
                while(s[l]!=s[r]){
                    st.erase(s[l]);
                    l++;
                }
                st.erase(s[l]);
                l++;
                st.insert(s[r]);
            }
            r++;
                ans = max(ans, r-l);
        }

        return ans;
    }
};
