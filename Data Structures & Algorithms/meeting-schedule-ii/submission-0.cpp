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
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();

        int ans=0;

        sort(intervals.begin(),intervals.end(),[](const Interval a, const Interval b){
            return a.start < b.start;
        });

        priority_queue<int,vector<int>, greater<int>>pq;

        for(int i=0;i<n;i++){
            if(pq.empty()){
                pq.push(intervals[i].end);
            }
            else{
                if(pq.top()<=intervals[i].start){
                    pq.pop();
                    pq.push(intervals[i].end);
                }
                else{
                    pq.push(intervals[i].end);
                }
            }

            ans = max(ans, (int)pq.size());
        }

        return ans;
    }
};
