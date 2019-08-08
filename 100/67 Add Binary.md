# 67 Add Binary

1. 解答错误：错了一个数字

执行用时 :12 ms, 在所有C++提交中击败了58.57%的用户

内存消耗 :9.2 MB, 在所有C++提交中击败了18.09%的用户

```c++
class Solution {
public:
    string addBinary(string a, string b) {
        int c=0,p=0;
        string ans;
        int i=a.size()-1;
        int j=b.size()-1;
        while(i>=0&&j>=0){
            p=c+a[i]-'0'+b[j]-'0';
            if(p==0){
                c=0;
                ans="0"+ans;
            }else if(p==1){
                c=0;
                ans="1"+ans;
            }else if(p==2){
                c=1;
                ans="0"+ans;
            }else{
                c=1;
                ans="1"+ans;
            }
            i--;j--;
        }
        while(i>=0){
            p=c+a[i]-'0';
            if(p==0){
                c=0;
                ans="0"+ans;
            }else if(p==1){
                c=0;
                ans="1"+ans;
            }else{
                c=1;
                ans="0"+ans;
            }
            i--;
        }
        while(j>=0){
            p=c+b[j]-'0';
            if(p==0){
                c=0;
                ans="0"+ans;
            }else if(p==1){
                c=0;
                ans="1"+ans;
            }else{
                c=1;
                ans="0"+ans;
            }
            j--;
        }
        if(c!=0)ans="1"+ans;
        return ans;
        
    }
};
```

