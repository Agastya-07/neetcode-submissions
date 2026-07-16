class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> mp;
        for(int i: nums){
            mp[i]++;
        }
        map<int, vector<int>> mp2;
        for(auto it = mp.begin(); it!=mp.end(); it++){
            mp2[it->second].push_back(it->first);
        }

        vector<int> res;
        int cnt=0;
        for(auto it = mp2.rbegin(); it!=mp2.rend() && cnt<k; it++){
            for(int i : it->second){
            if(cnt<k){

            res.push_back(i);
            cnt++;
            }
            else break;
            }
        }
        return res;
    }
};
