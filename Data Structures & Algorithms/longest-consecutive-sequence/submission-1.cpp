class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n =  nums.size();
        sort(nums.begin(), nums.end());
        int longest=0;
       unordered_map<int,int> mp;
       for(int i=0;i<n;i++){
        if(mp.find(nums[i]-1)==mp.end()){
            mp[nums[i]]=1;
        }
        else{
            mp[nums[i]] = mp[nums[i]-1]+1;
        }
            longest = max(longest, mp[nums[i]]);
       }
       return longest;
    }
};
