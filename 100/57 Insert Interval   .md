# 57 Insert Interval

执行用时 : 28 ms, 在Insert Interval的C++提交中击败了62.18% 的用户

内存消耗 : 12.7 MB, 在Insert Interval的C++提交中击败了5.23% 的用户

```c++
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size()<1){
            intervals.push_back(newInterval);
            return intervals;
        }
        
        int a=newInterval[0];
        int b=newInterval[1];
        int i=0;
        while(i<intervals.size()&&intervals[i][1]<a){
            i++;
            if(i==intervals.size()){
                intervals.push_back(newInterval);
                return intervals;
            }
        }
        a=intervals[i][0]<a?intervals[i][0]:a;
        int j=i;
        while(intervals[j][1]<b){
            j++;
            if(j==intervals.size()){
                j--;
                break;
            }
        }
        if(intervals[j][0]<=b){
            b=intervals[j][1]>b?intervals[j][1]:b;
        }else{
            j--;
        }
        vector<int> ab;ab.push_back(a);ab.push_back(b);
        if(j<i){
            intervals.insert(intervals.begin()+i,ab);
        }else if(i==j){
            intervals[i][0]=a;intervals[i][1]=b;
        }else{
            intervals[j][0]=a;intervals[j][1]=b;
            intervals.erase(intervals.begin()+i,intervals.begin()+j);
        }
        return intervals;

    }
};
```

1. erase[intervals.begin()+i,intervals.begin()+j)

2. [[1,5]] [2,7] b超过最大值

3. [[1,5]] [6,8] a、b超过最大值

   