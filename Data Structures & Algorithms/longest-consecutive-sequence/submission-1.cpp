class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int longest=0;;
        for(auto& n:st){
            if(st.find(n-1)==st.end()){
                int l=1;
            
                while(st.find(n+l)!=st.end()){
                    l++;

                }
                longest=max(longest,l);
            }
        }
        return longest;
    }
};
