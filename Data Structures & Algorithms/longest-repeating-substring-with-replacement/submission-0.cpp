class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        unordered_map<char,int>mpp;
        int maxf=0;
        int l=0;
        int maxi=0;
        for(int r=0;r<n;r++){
            mpp[s[r]-'A']++;
            maxf=max(maxf,mpp[s[r]-'A']);
            while((r-l+1)-maxf>k){
                mpp[s[l]-'A']--;
                l++;
            }
            maxi=max(maxi,r-l+1);
        }
        return maxi;
        
    }
};
