// 
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a[3] = {};
        for (int i = 0; i < nums.size(); ++i) {
            a[nums[i]] += 1;
        }
        nums.clear();
        for (int i = 0; i < a[0]; ++i)
            nums.push_back(0);
        for (int i = 0; i < a[1]; ++i)
            nums.push_back(1);
        for (int i = 0; i < a[2]; ++i)
            nums.push_back(2);
    }
};