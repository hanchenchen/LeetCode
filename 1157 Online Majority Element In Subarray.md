# 1157 Online Majority Element In Subarray

执行用时 :456 ms, 在所有 C++ 提交中击败了100.00%的用户

内存消耗 :19.7 MB, 在所有 C++ 提交中击败了100.00%的用户

```c++
class MajorityChecker {
public:
    int v[20005]={0};
    MajorityChecker(vector<int>& arr) {
        for(int i=0;i<arr.size();i++){
            v[i]=arr[i];
        }
    }
    
    int query(int left, int right, int threshold) {
        int re=0;
        int num[20003]={0};
        for(int i=left;i<=right;i++){
            num[v[i]]++;
        }
        for(int i=0;i<20003;i++){
            if(num[i]>=threshold)return i;
        }
        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
```

1. @先生

   ```c++
   int main() {
   	//                  0  1  2  3  4  5  6  7  8  9 
   	vector<int> arr = { 1, 2, 2, 3, 3, 3, 4, 4, 4, 4 };
   	cout << lower_bound(arr.begin(), arr.end(), 3) - arr.begin() << endl;	// 3
   	cout << upper_bound(arr.begin(), arr.end(), 3) - arr.begin() << endl;	// 6
   	return 0;
   }
   ```

2. 排序复杂度是O（nlogn）