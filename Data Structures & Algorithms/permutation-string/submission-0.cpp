class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26,0);
        int n = s2.length();

        for(char c: s1){
            freq[c-'a']++;
        }

        int wd = s1.length();
        for(int i=0; i+wd-1<n; i++){
            vector<int> freq2(26,0);

            for(int j =i; j<i+wd; j++){
                freq2[s2[j]-'a']++;
            }
            if(freq2==freq){
                return true;
            }
        }

    return false;
    }
};
