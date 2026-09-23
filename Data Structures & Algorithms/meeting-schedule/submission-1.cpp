/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        // Edge case: 0 or 1 meeting means zero conflicts possible
        if (intervals.empty()) {
            return true;
        }

        // STEP 1: Sort the intervals by their start times
        // We use a lambda function to tell C++ to compare the 'start' properties.
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });

        // STEP 2: Check adjacent meetings for conflicts
        // Notice we check (i + 1 < intervals.size()) instead of (size - 1) to avoid underflow
        for (int i = 0; i < intervals.size() - 1; i++) {
            
            // If the current meeting ends AFTER the next meeting starts -> CONFLICT!
            if (intervals[i].end > intervals[i+1].start) {
                return false; 
            }
        }

        // If we survive the loop without returning false, schedule is clean
        return true;
    }
};