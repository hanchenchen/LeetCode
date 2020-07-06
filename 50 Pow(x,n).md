# 50 Pow(x,n)

执行用时 :4 ms, 在所有 C++ 提交中击败了88.74%的用户

内存消耗 :8.3 MB, 在所有 C++ 提交中击败了83.76%的用户

```c++
class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        for(int i = n; i != 0; i /= 2){
            if(i % 2 != 0){
                res *= x;
            }
            x *= x;
        }
        return  n < 0 ? 1 / res : res;
    }
};
```

