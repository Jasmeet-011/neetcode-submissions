class Solution {
public:
    bool isValid(string s) {
       stack<char>st;
       int n=s.size();
       if(n<2)return false;
       for(auto& c:s){
        if(c=='('|| c=='[' || c=='{'){
            st.push(c);
        }else if(!st.empty() &&( (c=='}'&& st.top()=='{') || (c==']'&& st.top()=='[') ||(c==')'&& st.top()=='(') )){
            st.pop();
        }
        else return false;
       }
        return st.empty()? true: false;
    }
};