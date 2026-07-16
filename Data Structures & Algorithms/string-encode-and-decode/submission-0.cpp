class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for(auto& str: strs){
            int l = str.length();
            encoded+=to_string(l);
            encoded+='#';
            for(char& c: str){
                encoded+=c;
            }
        }

        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int l=0,r=0;
        int n =s.length();
            string len="";
        while(r<n){
            if(s[r]=='#'){
                int len2 = stoi(len);
                len="";
                decoded.push_back(s.substr(r+1, len2));
                r += len2+1;
            }
            else {
                len+=s[r];
                r++;
            }
        }
        return decoded;
    }
};
