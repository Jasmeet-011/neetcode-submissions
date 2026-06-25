class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mpp;
        for(int i=0;i<strs.size();i++){
            string sorted=strs[i];
            sort(sorted.begin(),sorted.end());
            mpp[sorted].push_back(strs[i]);
        }
        for(auto it:mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
