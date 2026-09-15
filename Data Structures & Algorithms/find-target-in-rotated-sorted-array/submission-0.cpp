class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n  =nums.size();
         int l=0,r=n-1;

         while(r-l> 1){
            int mid = l + (r-l)/2;
            if(nums[l] < nums[mid]){
                if(nums[l] <= target && target <= nums[mid])
                r= mid;
                else l = mid;
            }

            else if(nums[mid] < nums[r]){
                if(nums[mid] <= target && target <= nums[r])
                l= mid;
                else r = mid;
            }
         }
         if(nums[l] == target) return l;
         else if(nums[r] == target) return r;
         return -1;
    }
};
