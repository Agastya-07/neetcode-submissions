class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        unordered_map<int,int> mp;
        set<vector<int>> st;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]] = i;
        }
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int num1 = nums[i];
                int num2 = nums[j];
                int tofind  = -(num1 + num2);

                if(mp.find(tofind)!=mp.end() && mp[tofind]!=i && mp[tofind]!=j){
                    vector<int> temp = {num1, num2, tofind};
                    sort(temp.begin(),temp.end());
                    if(st.find(temp)==st.end()){
                    res.push_back(temp);
                    st.insert(temp);
                    }

                }

            }

        }

        return res;
    }
};
