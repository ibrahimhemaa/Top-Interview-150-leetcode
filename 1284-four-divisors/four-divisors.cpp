class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum=0;
        for(int num:nums){
            int cnt=0,first_div=0;
            for(int i=2;i*i<=num;i++){
                if(num%i==0 && !cnt){
                    cnt=1;
                    first_div=i;
                }
                else if(num%i==0){
                    cnt=2;
                    break;
                }
            }
            if(cnt==1 && (int)sqrt(num)*(int)sqrt(num)!=num){
                sum+=(num+1+first_div+num/first_div);
            }
        }
        return sum;
    }
};