class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>st;
        int l=0;
        int maxi=0;
        for(int r=0;r<s.size();r++){
            // so basically the idea is to skip ans move the left pointer +1 where there is a repeating character
                if(st.find(s[r])!=st.end()){
                    l=max(st[s[r]]+1,l);
                }
            
            st[s[r]]=r;
            maxi=max(maxi,r-l+1);
            
        }
        return maxi;

        
    }
};
