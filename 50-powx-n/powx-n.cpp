class Solution {
public:
    double fastpow(double x,long long n){
        if(n==0)return 1;
        double ret=fastpow(x,n/2);
        ret*=ret;
        if(n&1)ret*=x;
        return ret; 
    }
    double myPow(double x, int n) {
        long long N=n;
        return (N<0?1/fastpow(x,-N):fastpow(x,N));
    }
};