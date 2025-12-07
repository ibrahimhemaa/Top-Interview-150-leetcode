class Solution {
public:
    int countOdds(int low, int high) {
        return (high+1-low)/2+(low%2&&high%2);
    }
};