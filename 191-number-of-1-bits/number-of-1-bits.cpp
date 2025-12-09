class Solution {
public:
    int hammingWeight(int n) {
        int cnt=0;
        for(int i=0;i<31;i++){
            cnt+=((n & (1<<i))>0);
        }
        return cnt;
    }
};