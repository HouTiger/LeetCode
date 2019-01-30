class Solution {
  public:
    int maxArea(vector<int> &height) {
        int max = 0;
        for (int i = 0, j = height.size() - 1; i < j;) {

            int min = 0;
            if (height[i] > height[j]) {
                min = height[j];
                j--;
            }
            else {
                min = height[i];
                i++;
            }
            int area = (j - i + 1) * min;
            if (area > max)
                max = area;
        }
        return max;
    }
};