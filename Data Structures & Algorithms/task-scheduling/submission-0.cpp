class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int>pq;
        vector<int>v(26,0);
        for(auto& c:tasks){
            v[c-'A']++;
        }
        for(int i=0;i<26;i++){
            if(v[i]>0)pq.push(v[i]);
        }
        int time=0;
        while(!pq.empty()){
            int cnt=0;
            int k=n+1;
            vector<int>temp;
            while(k-- && !pq.empty()){
                int freq= pq.top();
                pq.pop();
                temp.push_back(freq-1);
                cnt++;
            }
            for(auto t:temp){
                if(t>0){
                    pq.push(t);
                }
            }
            time+= pq.empty()?cnt:n+1;
        }
        return time;
        
        
    }
};
