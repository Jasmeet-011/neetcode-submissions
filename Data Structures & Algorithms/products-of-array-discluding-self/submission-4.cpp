class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre(n);
        vector<int>pos(n);
        vector<int>ans;
        pre[0]=1;
        pos[n-1]=1;
        for(int i=1;i<nums.size();i++){
            pre[i]=nums[i-1]*pre[i-1];
        }
        
        for(int i=n-2;i>=0;i--){
            pos[i]=nums[i+1]*pos[i+1];
        }
        for(int i=0;i<nums.size();i++){
            ans.push_back(pre[i]*pos[i]);
        }
        return ans;
        

    }
};
