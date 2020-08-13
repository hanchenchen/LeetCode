# [43. Multiply Strings](https://leetcode-cn.com/problems/multiply-strings/)

#### 方法一：

执行用时 : 4 ms, 在Multiply Strings的C++提交中击败了99.73% 的用户

内存消耗 : 9.9 MB, 在Multiply Strings的C++提交中击败了81.90% 的用户

```c++
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0")return "0";
        string ans="";
        int c=0;
        int i=num1.size()+num2.size()-2;
        int x=0; 
        while(i>=0){
            x=c;
            //cout<<x<<"."<<endl;
            for(int j=i<num1.size()?i:(num1.size()-1);i-j<num2.size()&&j>=0;j--){
                x+=((num1[j]-'0')*(num2[i-j]-'0'));
                //cout<<j<<" "<<i-j;
                //cout<<"="<<x<<endl;
                //cout<<num1[j]<<" "<<num2[i-j];
                //cout<<"="<<x<<endl;
            }
            c=x/10;
            x=x%10;
            char a='0'+x;
            ans=a+ans;
            //cout<<i<<endl;
            i--;
        }
        if(c!=0)ans=char(c+'0')+ans;
        return ans;
    }
};
```

#### 方法二：

```python
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        ans = '0'*230
        if len(num1)<len(num2):
            num1,num2 = num2,num1
        for i in range(len(num2)):
            # print(ans)
            p = len(num2) - i -1
            x = num1
            # print('x',x)
            c = 0
            for j in range(len(num1)):
                q = len(num1) - j -1
                c = int(num2[p])*int(num1[q])+c
                x = x[:q]+str(c%10)+x[q+1:]
                c//=10
            x = '0'+str(c)+x
            c = 0
            # print('x*',num2[p],x)
            for j in range(len(x)):
                q = len(x) - j -1
                # print(ans[len(ans)-i-j-1],x[q])
                c = int(ans[len(ans)-i-j-1])+int(x[q])+c
                ans = ans[:len(ans)-i-j-1]+str(c%10)+ans[len(ans)-i-j:]
                c//=10
            # print('ans',ans)
        for i in range(len(ans)):
            if ans[i]=='0':
                i+=1
            else:
                return ans[i:]
        return '0'
```

