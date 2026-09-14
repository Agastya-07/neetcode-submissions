class Solution {
public:

    bool check(vector<int>& piles ,int mid, int h){
        int sm= 0;
        for(int i=0;i<piles.size();i++){
            sm+=ceil((piles[i]+mid-1)/mid);
        }
        if(sm<=h) return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l =1;
        int r = *max_element(piles.begin(), piles.end());

        while(r-l>1){
            int mid = l+  (r-l)/2;
            cout << mid<<endl;
            if(check(piles, mid, h)){
                r=mid;
            }
            else{
                l=mid;
            }
        }

        if(check(piles, l, h)) return l;
        return r;
    }
};
