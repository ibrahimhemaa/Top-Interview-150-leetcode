class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left==right)return left;
        int diff=right-left;
        for(int i=30;i>=0;i--){
            if((1<<i)&left || (1<<i)&right){
                if(((1<<i)&left) && ((1<<i)&right)){
                    int ans=1<<i;
                    for(int j=1;j<i;j++){
                        // cout<<((1<<j)&left)<<' '<<((1<<j)&right)<<'\n';
                        if(((1<<j)&left) && ((1<<j)&right) && (1<<j)>diff){ans+=(1<<j);}
                    }
                    return ans;
                }
                else return 0;
            }
        }
        return 0;
    }
};