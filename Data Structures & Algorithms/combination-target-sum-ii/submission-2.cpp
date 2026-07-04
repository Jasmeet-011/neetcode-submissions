class Solution {
    void calculate(vector<int>& nums, int target,vector<vector<int>>&ans,vector<int>&ds, int ind){
        
            if(target==0){
                ans.push_back(ds);
                return;
            }
            
        
        for(int i=ind;i<nums.size();i++){
            if(i>ind && nums[i]==nums[i-1])continue;
            if(nums[i]>target)break;
            ds.push_back(nums[i]);
            calculate(nums,target-nums[i], ans, ds, i+1);
            ds.pop_back();
        } 
        
    }     
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        sort(candidates.begin(),candidates.end());
        calculate(candidates,target,ans,ds,0);
        
        return ans;
        
    }
};
