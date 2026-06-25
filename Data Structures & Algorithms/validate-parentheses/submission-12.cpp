class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        stack<char>st;
        if(n<2) return false;
        for(auto ch:s){
            if(ch=='('|| ch=='{'|| ch=='['){
                st.push(ch);
            }
            else if((!st.empty()) && (ch==')'&& st.top()== '(' ||
                    ch=='}'&& st.top()== '{' ||
                    ch==']'&& st.top()== '[') ){
                        st.pop();
                    }
            else{
                return false;
            }        
        }
        return st.empty();
        
    }
};
