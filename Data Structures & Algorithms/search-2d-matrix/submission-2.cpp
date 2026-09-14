class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m  = matrix.size();
        int n = matrix[0].size();
        int l=0,r=m-1;
        while(r-l>1){
            int mid = l + (r-l)/2;
            if(target >= matrix[mid][0] && target <= matrix[mid][n-1]){
                int ll = 0, rr = n;

                while(rr-ll>1){
                    int midd = ll + (rr-ll)/2;
                    if(target == matrix[mid][midd]){
                        return true;
                    }
                    else if(target < matrix[mid][midd]){
                        rr = midd;
                    }
                    else{
                        ll= midd;
                    }
                }

                if(matrix[mid][ll] == target) return true;
                if(matrix[mid][rr] == target) return true;
                return false;
            }
            else if(target < matrix[mid][0]) r = mid;
            else l = mid;
        }

        auto lb = lower_bound(matrix[l].begin(), matrix[l].end(), target) - matrix[l].begin();
        int lb2 = lower_bound(matrix[r].begin(), matrix[r].end(), target) - matrix[r].begin();
        if(lb< n && matrix[l][lb] == target) return true;
        if(lb2<n && matrix[r][lb2] == target) return true;

        return false;
    }
};
