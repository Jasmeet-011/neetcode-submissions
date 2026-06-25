class Solution {
private:
    void calculate(vector<int>& nums, int target,vector<vector<int>>&ans,vector<int>&ds, int ind){
        if(ind==nums.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        if(nums[ind]<=target){
            ds.push_back(nums[ind]);
            calculate(nums,target-nums[ind], ans, ds, ind);
            ds.pop_back();
        }
        calculate(nums,target,ans, ds,ind+1);
    }     
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        calculate(nums, target, ans, ds,0);
        return ans;
        
    }
};
