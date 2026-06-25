class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        long long num=0;
        for(int i=0;i<digits.size();i++){
            num+=digits[i]*pow(10,n-1);
            n--;
        }
        num+=1;
        vector<int>ans;
        while(num!=0){
            int r=num%10;
            ans.push_back(r);
            num/=10;
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
        
    }
};
