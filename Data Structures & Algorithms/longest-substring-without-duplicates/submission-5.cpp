class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int ans=0;
        vector<int> mpp(256, -1);
        int i=0;
        int j=0;
        while(j<n){
            char ch=s[j];
            if(mpp[ch]>=i){
                i=mpp[ch]+1;
            }
            mpp[ch]=j;
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;

        
    }
};
