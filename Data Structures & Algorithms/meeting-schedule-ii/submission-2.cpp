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
        int n=intervals.size();
        vector<int>st(n);
        vector<int>end(n);
        for(int i=0;i<n;i++){
            st[i]=intervals[i].start;
            end[i]=intervals[i].end;
        }
        sort(st.begin(),st.end());
        sort(end.begin(),end.end());
        int cnt=0;
        int s=0;
        int e= 0;
        int maxi=0;
        while(s<n){
            if(st[s]<end[e]){
                cnt++;
                s++;
            }
            else{
                cnt--;
                e++;
                
            }
            maxi=max(maxi,cnt);
        }
        return maxi;
        
        
    }
};
