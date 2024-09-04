class Solution {
public:
    bool isHappy(int n) {
        string s=to_string(n);
        do{
            int sum=0;
            for(auto &i:s){
                sum+=(i-'0')*(i-'0');
            }
            if(sum==1){
                return 1;
            }
            s=to_string(sum);
        }while(s.size()>1 || s[0]>'4');
        return 0;
    }
};