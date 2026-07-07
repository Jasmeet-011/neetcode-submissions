class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>freq;
        for(auto i:t){
            freq[i]++;
        }
        int j=0;
        int i=0;
        int mini=INT_MAX;
        int st=-1;
        int cnt=0;
        while(j<s.size()){
            if(freq[s[j]]>0)cnt++;
            freq[s[j]]--;
            while(cnt==t.size()){
                if(mini>j-i+1){
                    mini=j-i+1;
                    st=i;
                }
                
                freq[s[i]]++;
                if(freq[s[i]]>0)cnt--;
                i++;
            }
            j++;
        }
        return st==-1?"": s.substr(st,mini);
        
    }
};
