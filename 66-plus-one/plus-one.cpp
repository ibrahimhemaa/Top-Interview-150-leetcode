class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int ind=digits.size()-1;
        while(~ind && digits[ind]==9)ind--;
        int last0=digits.size()-1;
        while(last0!=ind) digits[last0--]=0;
        if(~ind)digits[ind]++;
        else{
            digits[0]=1;
            digits.push_back(0);
        }
        return digits;
    }
};