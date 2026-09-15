class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int n  = nums.size();
        int r = n-1;
        if(n == 1) return nums[0];
        while(r-l>1){

        int mid = l + (r-l)/2;
        if(nums[l] > nums[mid]){
            r= mid;
        }
        else if(nums[mid] > nums[r]){
            l = mid;
        }
        else return nums[0];
        }
        if(nums[l]< nums[r]) return nums[l];
        else return nums[r];
    }
};
