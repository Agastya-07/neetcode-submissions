class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n  = nums.size();
        vector<int> res;
        map<int,int> mp;
        for(int i=0;i<k;i++){
            mp[nums[i]]++;
        }

        for(int i=k;i<n;i++){
            auto it = mp.rbegin();
            if(it->second){
                res.push_back(it->first);
            }
            mp[nums[i]]++;
            mp[nums[i-k]]--;
            if(mp[nums[i-k]]==0){
                mp.erase(nums[i-k]);
            }
        }
        auto it = mp.rbegin();
            if(it->second){
                res.push_back(it->first);
            }

            return res;
    }
};
