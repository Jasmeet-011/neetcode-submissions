class Solution {
private:    
    void gen(vector<string>& ans, string& st, int n, int open, int closed){
        if(open==closed && open==n){
            ans.push_back(st);
            return;
        }
        if(open<n){
            st+="(";
            gen(ans,st,n,open+1,closed);
            st.pop_back();
        }
        if(closed<open){
            st+=")";
            gen(ans,st,n,open,closed+1);
            st.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string st;
        gen(ans,st,n,0,0);
        return ans;
    }
};
