# 62 Unique Paths

**Solution 1   ：C（ （m+n-2），（m-1））**

执行用时 : 0 ms, 在Unique Paths的C++提交中击败了100.00% 的用户

内存消耗 : 8.4 MB, 在Unique Paths的C++提交中击败了44.75% 的用户


1. 解答错误：逻辑错误

   ```c++
   ans=ans*(a-i)/(i+1);
   ```

   ```c++
   ans*=(a-i)/(i+1);
   ```

   两个不一样！

2. 执行出错：*Line 8: Char 16: runtime error: signed integer overflow: 300674088 \* 51 cannot be represented in type 'int' (solution.cpp)*

   ```c++
   unsigned long long ans=1;
   ```

   ```c++
   #include <iostream>
   using namespace std;
   int main(int argc, const char * argv[]) {
       cout<<"CHAR_BIT:"<<CHAR_BIT<<endl;
       cout<<"CHAR_MAX:"<<CHAR_MAX<<endl;
       cout<<"CHAR_MIN:"<<CHAR_MIN<<endl;
       cout<<"SCHAR_MAX:"<<SCHAR_MAX<<endl;
       cout<<"SCHAR_MIN:"<<SCHAR_MIN<<endl;
       cout<<"UCHAR_MAX:"<<UCHAR_MAX<<endl;
       cout<<"SHRT_MAX:"<<SHRT_MAX<<endl;
       cout<<"SHRT_MIN:"<<SHRT_MIN<<endl;
       cout<<"USHRT_MAX:"<<USHRT_MAX<<endl;
       cout<<"INT_MAX:"<<INT_MAX<<endl;
       cout<<"INT_MIN:"<<INT_MIN<<endl;
       cout<<"LONG_MAX:"<<LONG_MAX<<endl;
       cout<<"LONG_MIN:"<<LONG_MIN<<endl;
       cout<<"ULONG_MAX:"<<ULONG_MAX<<endl;
       cout<<"LLONG_MAX:"<<LLONG_MAX<<endl;
       cout<<"LLONG_MIN:"<<LLONG_MIN<<endl;
       cout<<"ULLONG_MAX:"<<ULLONG_MAX<<endl;
   }
   CHAR_BIT:8
   CHAR_MAX:127
   CHAR_MIN:-128
   SCHAR_MAX:127
   SCHAR_MIN:-128
   UCHAR_MAX:255
   SHRT_MAX:32767
   SHRT_MIN:-32768
   USHRT_MAX:65535
   INT_MAX:2147483647
   INT_MIN:-2147483648
   LONG_MAX:9223372036854775807
   LONG_MIN:-9223372036854775808
   ULONG_MAX:18446744073709551615
   LLONG_MAX:9223372036854775807
   LLONG_MIN:-9223372036854775808
   ULLONG_MAX:18446744073709551615
   Program ended with exit code: 0
   ```
   
   


```c++
class Solution {
public:
    int uniquePaths(int m, int n) {
        int a = m+n-2;
        int b = m>n?n-1:m-1;
        unsigned long long ans=1;
        for(int i=0;i<b;i++){
            ans=ans*(a-i)/(i+1);
        }
        cout<<ans<<endl;
        return ans;
    }
};
```

**Solution 2   ：动态规划** "27 35" int溢出

1. 超出时间限制🚫："51 9"

   ```c++
   int arr[100][100]={0};
   if(arr[m][n]==0)
     arr[m][n]=uniquePaths(m-1,n)+uniquePaths(m,n-1);
   ```

2. 执行出错：*Line 6: Char 20: runtime error: index 100 out of bounds for type 'int [100]' (solution.cpp)*

   ```
   int arr[105][105]={0};//"100 2"
   ```

执行用时 : 4 ms, 在Unique Paths的C++提交中击败了94.22% 的用户

内存消耗 : 8.4 MB, 在Unique Paths的C++提交中击败了45.57% 的用户

```c++
class Solution {
public:
    int arr[105][105]={0};
    int uniquePaths(int m, int n) {
        if(m==1||n==1)return 1;
        if(arr[m][n]==0)
            arr[m][n]=uniquePaths(m-1,n)+uniquePaths(m,n-1);
        return arr[m][n];
    }
};
```

**Solution 3** 官方思路

执行用时 : 4 ms, 在Unique Paths的C++提交中击败了93.95% 的用户

内存消耗 : 8.2 MB, 在Unique Paths的C++提交中击败了62.03% 的用户

```c++
class Solution {
public:
    
    int uniquePaths(int m, int n) {
        int arr[105][105]={0};
        for(int i=0;i<m;i++){
            arr[i][0]=1;
        }  
        for(int j=0;j<n;j++){
            arr[0][j]=1;
        } 
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                arr[i][j]=arr[i-1][j]+arr[i][j-1];
            }
        }
        return arr[m-1][n-1];
    }
};
```

