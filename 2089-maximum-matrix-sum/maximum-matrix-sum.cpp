class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum=0;
        int cnt=0,zero=0,mn=1e6;
        for(auto mat:matrix){
            for(int num:mat){sum+=abs(num);
            zero+=(num==0);
            mn=min(mn,abs(num));cnt+=(num<0);}
        }
        if(cnt%2&&!zero)return sum-2*mn;
        else return sum;
    }
};