class Solution {
public:
    int lastele(vector<int>& piles){
        int maxi=INT_MIN;
        for(int i=0;i<piles.size();i++){
            if(piles[i]>maxi){
                maxi=piles[i];
            }
        }
        return maxi;
    }
    bool timetaken(vector<int>& piles, int h,int mid){
        int t=0;
        for(int i=0;i<piles.size();i++){
            t+=ceil(double(piles[i])/double(mid));
        }
        if(t>h) return false;
        else return true;

    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=lastele(piles);
        while(low<=high){
            int mid=low+(high-low)/2;
            if(timetaken(piles,h,mid)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;

        

    }
};
