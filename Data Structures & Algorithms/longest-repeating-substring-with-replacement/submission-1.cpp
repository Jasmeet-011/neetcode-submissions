class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        unordered_map<char,int>mpp;
        int j=0;
        int i=0;
        int maxf=0;
        int maxi=0;
        while(j<n){
            mpp[s[j]-'A']++;
            maxf=max(maxf,mpp[s[j]-'A']);
            while((j-i+1)-maxf>k){
                mpp[s[i]-'A']--;
                i++;
            }
            maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
        
    }
};
