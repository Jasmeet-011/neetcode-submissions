class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        int n=nums.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<>>pq;
        unordered_map<int,int>mpp;
        for(auto &n:nums){
            mpp[n]++;
        }
        for(auto &it:mpp){
            pq.push({it.second, it.first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;


        
    }
};
