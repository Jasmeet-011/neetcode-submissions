class Solution {
    void backtrack(int n, int open, int close, vector<string>&ans,string&curr){
        if(curr.size()==n*2){
            ans.push_back(curr);
            return;
        }
        if(open<n){
            curr.push_back('(');
            backtrack(n,open+1,close,ans,curr);
            curr.pop_back();
        }
        if(close<open){
            curr.push_back(')');
            backtrack(n,open,close+1,ans,curr);
            curr.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string curr="";
        backtrack(n,0,0,ans,curr);
        return ans;
        
    }
};
