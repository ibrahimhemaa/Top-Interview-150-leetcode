class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto &i:tokens){
            if(i=="+"){
                int x=st.top();st.pop();
                x+=st.top();st.pop();
                st.push(x);
            }else if(i=="*"){
                int x=st.top();st.pop();
                x*=st.top();st.pop();
                st.push(x);
            }
            else if(i=="/"){
                int x=st.top();st.pop();
                x=st.top()/x;st.pop();
                st.push(x);
            }
            else if(i=="-"){
                int x=st.top();st.pop();
                x=st.top()-x;st.pop();
                st.push(x);
            }
            else{
                st.push(stoi(i));
            }
        }
        return st.top();
    }
};