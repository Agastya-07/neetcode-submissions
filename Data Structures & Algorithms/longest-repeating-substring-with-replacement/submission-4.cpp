class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int ans = 0;
        
        int l=0,r=0;
        int mx=0;
        vector<int> freq(26,0);
        while(r<n){
            freq[s[r]-'A']++;
            mx = max(freq[s[r]-'A'], mx);

            int length = r-l+1;
            if(length-mx <= k){
                ans = max(ans, length);
            }
            else{
                while(r-l+1 - mx > k){
                    freq[s[l]-'A']--;
                    l++;
                    mx = 0;
                    for(int i=0; i<26; i++) mx = max(mx, freq[i]);
                }
                ans = max(ans, r-l+1);
            }
            r++;
        }

        return ans;
    }
};