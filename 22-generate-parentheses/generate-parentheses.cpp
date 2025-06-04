class Solution {
public:
    vector<string>ans;
    void solve(int n,int f,int b,string s=""){
        if(s.size()==2*n){
            ans.push_back(s);
            return;
        }
        if(f==b){
            s+='(';
            solve(n,f-1,b,s); 
        }
        else{
            if(f){
                s+='(';
                solve(n,f-1,b,s);
                s.pop_back(); 
            }
            if(b){
                s+=')';
                solve(n,f,b-1,s);
                s.pop_back(); 
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        solve(n,n,n);
        return ans;
    }
};