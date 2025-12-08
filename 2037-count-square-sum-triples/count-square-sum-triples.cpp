class Solution {
public:
    int countTriples(int n) {
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                cnt+=sqrt(j*j-i*i)==ceil(sqrt(j*j-i*i));
            }
        }
        return cnt;
    }
};