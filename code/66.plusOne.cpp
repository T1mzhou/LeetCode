class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        int t = 1;
        for (auto& x: digits) {
            t += x;
            x  = t % 10;
            t /= 10;
        }
        if ( t ) digits.push_back(t);
        reverse(digits.begin(), digits.end());

        return digits;
    }
};