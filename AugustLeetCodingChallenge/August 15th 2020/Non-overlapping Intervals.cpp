class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
         if (intervals.size() <= 1) return 0;     
        
		sort(intervals.begin(), intervals.end(), [](const auto& l, const auto& r) { 
            return l[1] < r[1]; 
        });     
		
        int prevIndex = 0;
        int eraseCount = 0;
        
		for (int i = 1; i < intervals.size(); ++i) {
			if (intervals[prevIndex][1] > intervals[i][0]) ++eraseCount;
		    else prevIndex = i;
		}
        
		return eraseCount;
    }
};
