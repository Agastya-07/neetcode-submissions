class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> a(26,0);
        for(char& c : s){
            a[c-'a']++;
        }
        for(char c: t){
            a[c-'a']--;
        }

        for(int i: a){
            if(i){
                return false;
            }
        }
        return true;
    }
};
