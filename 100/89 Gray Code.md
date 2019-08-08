# 89 Gray Code

>  格雷码：G(i) = i ^ (i/2);			


1. 异或：^

2. 1<<n ：把1左移n位；n<<1 ：把n左移1位；

3. 格雷码：

   执行用时 :12 ms, 在所有 C++ 提交中击败了68.79%的用户

   内存消耗 :8.6 MB, 在所有 C++ 提交中击败了48.64%的用户

   ```c++
   class Solution {
   public:
       vector<int> grayCode(int n) {
           vector<int> ans;
           ans.push_back(0);
           //if(n==0)return ans;
           for(int i=1;i<1<<n;i++){
               ans.push_back(i^i>>1);
           }
           return ans;
       }
   };
   ```

4. 找规律：

   执行用时 :8 ms, 在所有 C++ 提交中击败了90.28%的用户

   内存消耗 :8.6 MB, 在所有 C++ 提交中击败了47.73%的用户

```c++
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        ans.push_back(0);
        if(n==0)return ans;
        int i=1;
        for(;n>0;n--){
            for(int j=i-1;j>=0;j--){
                ans.push_back(ans[j]+i);
            }
            i*=2;
        }
        return ans;
    }
};
```

