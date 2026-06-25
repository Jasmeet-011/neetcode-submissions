class Solution {
public:

    string encode(vector<string>& strs) {
        string ans;
        for(auto s:strs){
            int l=s.size();
            ans+=to_string(l)+"#"+s;
        }
        return ans;


    }

    vector<string> decode(string s) {
        vector<string>ans;
        int n=s.size();
        int i=0;int j=0;
        while(j<n){
            while(s[j]!='#')j++;
            if(s[j]=='#'){
                int k=stoi(s.substr(i,j-i));
                string st=s.substr(j+1,k);
                ans.push_back(st);
                j+=k+1;
                i=j;
            }
            
        }
        return ans;

    }
};
