class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        int n=height.size();
        int res=0;
        int i=0;
        int j=n-1;
        int leftmax=height[i];
        int rightmax=height[j];
        while(i<j){
            if(leftmax<rightmax){
                i++;
                leftmax=max(leftmax,height[i]);
                res+=leftmax- height[i];
            }
            else{
                j--;
                rightmax=max(rightmax, height[j]);
                res+=rightmax-height[j];
            }
        }
        return res;
        
    }
};
