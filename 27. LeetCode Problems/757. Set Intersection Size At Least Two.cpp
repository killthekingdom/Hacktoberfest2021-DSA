//https://leetcode.com/problems/set-intersection-size-at-least-two/


class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];    
    }
    
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        
        int count = 2;
        int secondLastNumber = intervals[0][1] - 1;
        int lastNumber = intervals[0][1];
        
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= secondLastNumber) {
                continue;
            } else if (intervals[i][0] <= lastNumber) {
                count++;
                if (lastNumber != intervals[i][1]) {
                    secondLastNumber = lastNumber;
                    lastNumber = intervals[i][1];                  
                } else {
                    secondLastNumber = lastNumber - 1;
                }

            } else {
                count += 2;
                lastNumber = intervals[i][1];
                secondLastNumber = intervals[i][1] - 1;
            }   
        }
        
        return count;
    }
};
