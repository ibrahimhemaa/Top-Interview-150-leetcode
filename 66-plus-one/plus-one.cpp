class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int ind=digits.size()-1;
        while(~ind && digits[ind]==9)digits[ind]=0,ind--;
        digits[(~ind?ind:0)]++;
        if(!~ind)digits.push_back(0);
        return digits;
    }
};