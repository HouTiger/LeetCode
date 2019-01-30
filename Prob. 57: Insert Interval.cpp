/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        if (intervals.size() == 0) {
            intervals.push_back(newInterval);
            return intervals;
        }
        
        bool l_in = false, r_in = false;
        int a = 0, b = 0, c = 0, d = 0; // i - 1, i, j - 1, j
        // 左右都不在区间内
        // 记录i - 1, i, j - 1, j
        // 左边在区间内，右边不在区间内
        // 记录i， j - 1, j
        // 右边在区间内，左边不在区间内
        // 记录i - 1, i, j
        bool found = false;
        int i, j;
        for (i = 0; i < intervals.size() && !found; ++i) {
            if (intervals[i].start > newInterval.start) {
                if (i == 0 || intervals[i - 1].end < newInterval.start) {
                    // 不在区间内
                    l_in = false;
                    a = i - 1;
                    b = i;
                }
                else {
                    // 在区间内
                    l_in = true;
                    a = i - 1;
                }
                found = true;
            }
            else if (intervals[i].start == newInterval.start) {
                l_in = true;
                a = i;
                found = true;
            }
            else if (i == (intervals.size() - 1)) {
                if (newInterval.start > intervals[i].end) {
                    l_in = false;
                    a = i;
                    b = i + 1;
                }
                else {
                    l_in = true;
                    a = i;
                }
                found = true;
            }
        }
        // cout << "flag1\n";
        found = false;
        for (j = i - 1; j < intervals.size() && !found; ++j) {
            if (intervals[j].start > newInterval.end) {
                if (j == 0 || intervals[j - 1].end < newInterval.end) {
                    // 不在区间内
                    r_in = false;
                    c = j - 1;
                    d = j;
                }
                else {
                    r_in = true;
                    c = j - 1;
                }
                found = true;
            }
            else if (intervals[j].start == newInterval.end) {
                r_in = true;
                c = j;
                found = true;
            }
            else if (j == (intervals.size() - 1)) {
                if (newInterval.end > intervals[j].end) {
                    r_in = false;
                    c = j;
                    d = j + 1;
                }
                else {
                    r_in = true;
                    c = j;
                }
                found = true;
            }
        }
        int newstart = l_in ? intervals[a].start : newInterval.start;
        int newend = r_in ? intervals[c].end : newInterval.end;
        int inter_l = l_in ? a : b;
        intervals.erase(intervals.begin() + inter_l, intervals.begin() + c + 1);
        intervals.insert(intervals.begin() + inter_l, Interval(newstart, newend));
        /*if (l_in && r_in) {
            // cout << 1 << endl;
            int newstart = intervals[a].start, newend = intervals[c].end;
            
            intervals.erase(intervals.begin() + a, intervals.begin() + c + 1);
            
            intervals.insert(intervals.begin() + a, Interval(newstart, newend));
        }
        else if (!l_in && !r_in) {
            // cout << 2 << endl;
            int newstart = newInterval.start, newend = newInterval.end;
            intervals.erase(intervals.begin() + b, intervals.begin() + c + 1);
            intervals.insert(intervals.begin() + b, Interval(newstart, newend));
        }
        else if (l_in && !r_in) {
            // cout << 3 << endl;
            int newstart = intervals[a].start, newend = newInterval.end;
            intervals.erase(intervals.begin() + a, intervals.begin() + c + 1);
            intervals.insert(intervals.begin() + a, Interval(newstart, newend));
        }
        else if (!l_in && r_in) {
            // cout << 4 << endl;
            int newstart = newInterval.start, newend = intervals[c].end;
            intervals.erase(intervals.begin() + b, intervals.begin() + c + 1);
            intervals.insert(intervals.begin() + b, Interval(newstart, newend));
        }*/
        return intervals;
    }
};