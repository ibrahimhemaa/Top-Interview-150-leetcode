class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum=0;
        int cnt=0,mn=1e6;
        for(vector<int> mat:matrix){
            for(int num:mat){
                sum+=abs(num);
                mn=min(mn,abs(num));
                cnt+=(num<0);
            }
        }
        return sum-2*(mn*(cnt%2));
       
    }
};