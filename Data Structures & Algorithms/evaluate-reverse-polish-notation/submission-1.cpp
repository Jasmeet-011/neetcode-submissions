class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        //int ans=0;
        stack<int>st;
        for(auto s:tokens){

            if(s!="+"&& s!="-" && s!="*"&&s!="/"){
                st.push(stoi(s));
            }
            else if(st.size()>1){
                int x= st.top();
                st.pop();
                int y= st.top();
                st.pop();
                if(s=="+"){
                    int val=y+x; 
                    st.push(val);           
                }
                else if(s=="-"){
                    int val=y-x;
                    st.push(val);
                }
                else if(s=="*"){
                    int val=y*x;
                    st.push(val);
                }
                else if(s=="/"){    
                    int val=y/x;
                    st.push(val);

                }
                
            }
        }
        
        return st.top();
        
    }
};
