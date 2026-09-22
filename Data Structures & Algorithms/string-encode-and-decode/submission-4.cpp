class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded="";
        for(auto s:strs){
            int l=s.size();
            encoded+=to_string(l)+"#"+s;
        }
        return encoded;


    }

    vector<string> decode(string s) {
        int i=0;
        int j=0;
        int n=s.size();
        vector<string>ans;
        while(j<n){
            while(j<n&&s[j]!='#'){
                j++;
            }
            int l= stoi(s.substr(i,j-i));
            string st= s.substr(j+1,l);
            i=j+1+l;
            j=i;
            ans.push_back(st);
        }
        return ans;

    }
};
