class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // int cnt =1;
        // int ele=nums[0];
        // int maxi=INT_MIN;
        // for(int i=0;i<nums.size()-1;i++){
        //     cout<<nums[i]<<" ";
            
        //     if(nums[i+1]==ele+1 ){
        //         cnt++;
        //         ele=nums[i+1];
        //     }
        //     else if(ele !=nums[i+1]){
        //         cnt=1;
        //         ele=nums[i+1];
        //     }
        //     maxi=max(maxi,cnt);

        // }
        // return maxi;
        if(nums.size()==0) return 0;
        unordered_set<int>st(nums.begin(),nums.end());
        int maxi=INT_MIN;
        for(auto x:st){
            if(st.find(x-1)==st.end()){
                int curr=x;
                int len=1;
                while(st.find(curr+1)!=st.end()){
                    curr+=1;
                    len+=1;
                }
                maxi=max(maxi,len);
            }
        }
        return maxi;
    }
};
