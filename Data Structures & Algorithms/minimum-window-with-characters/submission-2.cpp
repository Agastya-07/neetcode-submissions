class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> freqt;
        for(char c: t){
            freqt[c]++;
        }
        int ans = INT_MAX;
        pair<int,int> res = {0,0};
        int l=0,r=0;
        int need  = freqt.size();
        int have = 0;
        if(t.length() == 0) return "";
        unordered_map<char,int> freqs;
        while(r<s.length()){
            freqs[s[r]]++;
            if(freqt[s[r]] == freqs[s[r]]){
                have++;
            }

            while(have == need){
                if(r-l+1 < ans){
                    ans = r-l+1;
                    res = {l,r};
                }
                freqs[s[l]]--;
                if(freqs[s[l]]<freqt[s[l]]){
                    have--;
                }
                
                    l++;
                
            }
            r++;
        }
        if(ans == INT_MAX){
            return "";
        }
        else{
            return s.substr(res.first, res.second-res.first+1);
        }
    }
};
