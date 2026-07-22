class Solution {
public:
    bool isPalindrome(string s) {
        string new_s="";
        for(char c: s){
            if(isalnum(c)){
                new_s+=tolower(c);
            }
        }
        int n = new_s.length();
        int l=0,r=n-1;
        cout<<new_s;
        while(l<r){
            if(new_s[l]!=new_s[r]) return false;
            else{
                l++;r--;
            }
        }
        return true;
    }
};
