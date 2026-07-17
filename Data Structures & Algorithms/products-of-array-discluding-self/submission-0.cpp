class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixpdt(n), suffix(n);
        prefixpdt[0] = nums[0];
        suffix[n-1] = nums[n-1];

        for(int i=1;i<n;i++){
            prefixpdt[i] = prefixpdt[i-1]*nums[i];
            suffix[n-1-i] = suffix[n-i]*nums[n-1-i];
        }

        vector<int> res(n);
        res[0] = suffix[1];
        res[n-1] = prefixpdt[n-2];
        for(int i=1;i<n-1;i++){
            res[i] = prefixpdt[i-1]*suffix[i+1];
        }
        return res;
    }
};
