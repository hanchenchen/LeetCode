# 5069 Last Substring in Lexicographical Order

```c++
class Solution {
public:
    string lastSubstring(string s) {
        int n=s.size();
        int dp[100004]={0};
        char x='a';string ans;
        for(int i=0;i<n;i++){
            if(s[i]>x)x=s[i];
        }
        if(x=='a')return s;
        s+='1';
        int num=0;
        for(int i=0;i<n;i++){
            if(x==s[i]){
                dp[i]=1;
                num++;
            }
        }
        int len=0,flag=1;
        while(flag>0){
            flag=-1;
            x='a'-1;
            for(int j=0;j<n;j++){
                if(dp[j]==0)continue;
                flag++;
                x=max(x,s[j+len]);
            }
            if(x<'a')break;
            ans+=x;
            for(int j=0;j<n;j++){
                if(s[j+len]!=x)dp[j]=0;
            }
            len++;
        }
        int i=0;
        while(!dp[i])i++;
        return s.substr(i,n-i);
    }
};
```

1. 之前用`stack`TLE（23/24），换成数组就好用了。