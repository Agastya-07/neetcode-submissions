class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n =  nums.size();
        
        int longest=0;
       unordered_set<int> st;
       for(int& i: nums){
            st.insert(i);
       }
       for(int num: st){
        if(st.find(num-1)==st.end()){
            int x = num;
            int l =1;
            while(st.find(x+1)!=st.end()){
                l++;
                x++;
            }
            longest = max(l, longest);
        }
       }
       return longest;
    }
};
