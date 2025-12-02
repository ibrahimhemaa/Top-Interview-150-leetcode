class Solution {
public:
    int calculate(string s) {
        int ans=0,num=0,op=1;
        stack<int>st;
        st.push(1);
        for(char i:s){
            if(i>='0' && i<='9'){
                num=num*10+(i-'0');
            }
            else if(i=='('){
                st.push(op);
            }
            else if(i==')')st.pop();
            else if(i!=' '){
                ans+=num*op;
                op=(i=='+'?1:-1)*st.top();
                num=0;
            }
        }
        return ans+num*op;

    }
};