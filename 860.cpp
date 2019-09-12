class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int len = bills.size();
        int fiv = 0, ten = 0, twe = 0;
        for (int i = 0; i < len; ++i) {
            if (bills[i] == 5) {
                fiv += 1;
            }
            if (bills[i] == 10) {
                if (fiv > 0) {
                    fiv -= 1;
                    ten += 1;
                }
                else {
                    return false;
                }
            }
            if (bills[i] == 20) {
                if (ten > 0 && fiv > 0) {
                    ten -= 1;
                    fiv -= 1;
                    twe += 1;
                }
                else if (fiv >= 3) {
                    fiv -= 3;
                    twe += 1;
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};
