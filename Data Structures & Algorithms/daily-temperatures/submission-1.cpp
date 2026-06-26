class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>>st;
        // we can take it for temp, index
        int n=temperatures.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            int temp=temperatures[i];
            while(!st.empty() &&temp>st.top().first){
                auto [t, ind]=st.top();
                ans[ind]=i-ind;
                st.pop();
            }
            st.push({temp,i});
        }
        return ans;

    }
};
