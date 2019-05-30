# 43 Multiply Strings

执行用时 : 4 ms, 在Multiply Strings的C++提交中击败了99.73% 的用户

内存消耗 : 9.9 MB, 在Multiply Strings的C++提交中击败了81.90% 的用户

```
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

