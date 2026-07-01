class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>>mpp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({timestamp,value});
        
    }
    
    string get(string key, int timestamp) {
        auto values=mpp[key];
        int low=0;
        int high=values.size()-1;
        string res="";
        while(low<=high){
            int mid=low+(high-low)/2;
            if(values[mid].first<=timestamp){
                res=values[mid].second;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return res;
        
    }
};
