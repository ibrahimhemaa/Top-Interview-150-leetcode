class Solution {
public:
    int countTriples(int n) {
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int val=j*j-i*i;
                if(sqrt(val)==ceil(sqrt(val)))++cnt;
            }
        }
        return cnt;
    }
};