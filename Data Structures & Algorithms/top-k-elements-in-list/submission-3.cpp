class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        unordered_map<int,int>mpp;
        for(auto i:nums){
            mpp[i]++;
        }
        vector<vector<int>>bucket(nums.size()+1);
        
        for(auto it:mpp){
            bucket[it.second].push_back(it.first);
            
        }
        for(int i=bucket.size()-1;i>=0 && ans.size()<k;i--){
            for(auto j:bucket[i]){
                ans.push_back(j);
                if(ans.size()==k) break;
            }
        }
        return ans;
        
    }
};
