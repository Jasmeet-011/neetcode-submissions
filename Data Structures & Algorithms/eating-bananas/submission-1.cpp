class Solution {
    int lastele(vector<int>& piles){
        int maxi=0;
        for(auto n:piles){
            maxi=max(maxi,n);
        }
        return maxi;
    }
    bool timetaken(vector<int>& piles, int mid, int h){
        long long time=0;
        for(auto p:piles){
            time+=(p/mid)+(p%mid!=0?1:0);
            if(time>h) return false;
        }
        return (time<=h)? true:false;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=lastele(piles);
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(timetaken(piles,mid,h)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;

        
    }
};
