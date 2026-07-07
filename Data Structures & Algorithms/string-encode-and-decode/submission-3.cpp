class Solution {
public:

    string encode(vector<string>& strs) {
        string s;
        for(auto st:strs){
            int n=st.size();
            s+=to_string(n)+"#"+st;
        }
        return s;
        


    }

    vector<string> decode(string s) {
        int i =0;
        int j=0;
        int n=s.size();
        vector<string>ans;
        while(j<n){
            while(s[j]!='#'){
                j++;
            }
            if(s[j]=='#'){
                int n=stoi(s.substr(i,j-i));
                string st=s.substr(j+1,n);
                ans.push_back(st);
                j+=n+1;
                i=j;
            }

        }
        return ans;
        

    }
};
