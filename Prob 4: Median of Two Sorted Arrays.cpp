class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() == 0) {
            return double((nums2[nums2.size() / 2] + nums2[(nums2.size() - 1)/ 2]) / 2.0);
        }
        // let n >= m 
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1); // if n < m, then swap arguments
        }
        int m = nums1.size(), n = nums2.size(); 
        int left = 0, right = m;
        while(left <= right) {
            int i = (left + right) / 2;
            int j = (m + n + 1) / 2 - i;
            int leftmax, rightmin;
            if (i == 0) 
                leftmax = nums2[j - 1];
            else if (j == 0) 
                leftmax = nums1[i - 1];
            else
                leftmax = max(nums1[i - 1], nums2[j - 1]);
            //cout << "flag1\n";
           
            if (i == m) 
                rightmin = nums2[j];
            else if (j == n) 
                rightmin = nums1[i];
            else
                rightmin = min(nums1[i], nums2[j]);
            //cout << "flag2\n";
            // printf("leftmax = %d, rightmin = %d\n", leftmax, rightmin);
            if ((j == 0 || i == m || nums2[j - 1] <= nums1[i]) &&
                (i == 0 || j == n || nums1[i - 1] <= nums2[j])) {
                // target founded
                if ((m + n) % 2)  // m + n is odd
                    return double(leftmax);
                else // m + n is even
                    return double((leftmax + rightmin) / 2.0);
            }
            else if (nums2[j - 1] > nums1[i]) // i is too small
                left = i + 1;
            else if (nums1[i - 1] > nums2[j]) // i is too large
                right = i - 1;
            
        }
        return double(0);
        
        
        
    }
};