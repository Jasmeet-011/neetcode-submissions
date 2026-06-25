class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        stack<pair<int,int>>st;
        vector<int>res(n,0);
        for(int i=0;i<n;i++){
            int temp=temperatures[i];
            while(!st.empty()&&temp>st.top().first){
                auto p=st.top();
                st.pop();
                res[p.second]=(i-p.second);
            }
            st.push({temp,i});
        }
        return res;
        
    }
};
