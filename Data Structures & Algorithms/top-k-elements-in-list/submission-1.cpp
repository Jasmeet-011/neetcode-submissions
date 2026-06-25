class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }

        vector<pair<int,int>> v(mpp.begin(), mpp.end());

        sort(v.begin(), v.end(),
            [](const pair<int,int>& a, const pair<int,int>& b) {
                return a.second > b.second;   // sort by value (descending)
            }
        );
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(v[i].first);
        }
        return ans;

        
    }
};
