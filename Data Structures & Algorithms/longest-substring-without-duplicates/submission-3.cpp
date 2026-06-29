class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int ans=0;
        unordered_set<char>st;
        int i=0;
        int j=0;
        while(j<n){
            char ch=s[j];
            while(st.find(ch)!=st.end()){
                st.erase(s[i]);
                i++;
            }
            st.insert(ch);
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;

        
    }
};
