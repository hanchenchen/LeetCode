

# 56 Merge Interval

1. new一个新的vector<vector<int>>插入 比erase和修改旧的vector<vector<int>>更快
2. [[1,4],[2,3]] [[1,4],[0,4]]
3. 

执行用时 : 40 ms, 在Merge Intervals的C++提交中击败了26.41% 的用户

内存消耗 : 12.4 MB, 在Merge Intervals的C++提交中击败了5.08% 的用户

执行用时 : 36 ms, 在Merge Intervals的C++提交中击败了40.92% 的用户

内存消耗 : 12.3 MB, 在Merge Intervals的C++提交中击败了5.08% 的用户

```c++
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()<=1)return intervals;
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        for(int i=0;i<intervals.size();i++){
            if(i<intervals.size()-1&&intervals[i][1]>=intervals[i+1][0]){
                intervals[i+1][0]=intervals[i][0];
                intervals[i+1][1]=
                    intervals[i][1]>intervals[i+1][1]?
                    intervals[i][1]:intervals[i+1][1];
                //intervals.erase(intervals.begin()+i);i--;
                
            }else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
```



执行用时 : 1832 ms, 在Merge Intervals的C++提交中击败了5.17% 的用户

内存消耗 : 12.5 MB, 在Merge Intervals的C++提交中击败了5.08% 的用户

```c++
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()<=1)return intervals;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size()-1;i++){
            if(intervals[i][1]>=intervals[i+1][0]){
                intervals[i+1][0]=intervals[i][0];
                intervals[i+1][1]=
                    intervals[i][1]>intervals[i+1][1]?
                    intervals[i][1]:intervals[i+1][1];
                intervals.erase(intervals.begin()+i);
                i--;
            }
        }
        return intervals;
    }
};
```



