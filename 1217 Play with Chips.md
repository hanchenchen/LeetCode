# 1217 Play with Chips

执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户

内存消耗 :9.6 MB, 在所有 C++ 提交中击败了100.00%的用户

```c++
class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int odd=0;
        for(int i=0;i<chips.size();i++){
            if(chips[i]&1){
                odd++;//cout<<i<<endl;
            }     
        }
        return min((int)chips.size()-odd,odd);
    }
};
```

