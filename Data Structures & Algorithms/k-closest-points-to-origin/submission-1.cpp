class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<long long,pair<int,int>>>pq;
        for(auto& v:points){
            int x=v[0];
            int y=v[1];
            long long dis= (abs(0-x)*abs(0-x))+(abs(0-y)*abs(0-y));
            pq.push({dis,{x,y}});
            if(pq.size()>k)pq.pop();
        }
        vector<vector<int>>ans;
        while(!pq.empty()){
            long long d= pq.top().first;
            auto [x,y]=pq.top().second;
            pq.pop();
            ans.push_back({x,y});
        }
        return ans;

        
    }
};
