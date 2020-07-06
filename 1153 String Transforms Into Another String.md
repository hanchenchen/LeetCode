# 1153 String Transforms Into Another String

Given two strings `str1` and `str2` of the same length, determine whether you can transform `str1` into `str2` by doing **zero or more** *conversions*.

In one conversion you can convert **all** occurrences of one character in `str1` to **any** other lowercase English character.

Return `true` if and only if you can transform `str1` into `str2`. 

**Example 1:**

```
Input: str1 = "aabcc", str2 = "ccdee"
Output: true
Explanation: Convert 'c' to 'e' then 'b' to 'd' then 'a' to 'c'. Note that the order of conversions matter.
```

**Example 2:**

```
Input: str1 = "leetcode", str2 = "codeleet"
Output: false
Explanation: There is no way to transform str1 to str2.
```

**Note:**

1. `1 <= str1.length == str2.length <= 10^4`
2. Both `str1` and `str2` contain only lowercase English letters.

```c++
class Solution {
public:
    string stra,strb;
    bool func(char a,char b){
        for(int i=0;i<stra.size();i++){
            if(stra[i]==a&&strb[i]!=b)return false;
            //if(stra[i]!=a&&strb[i]==b)return false;
        }
        return true;
    }
    bool canConvert(string str1, string str2) {
        if(str1==str2)return true;
        if(str1.size()!=str2.size())return false;
        stra=str1;strb=str2;
        int vis['z'+1]={0};
        int num['z'+1]={0};
        int num2['z'+1]={0};
        for(int i=0;i<str1.size();i++){
            num[str1[i]]++;num2[str2[i]]++;
            if(vis[str1[i]]||str1[i]==str2[i])continue;
            if(func(str1[i],str2[i]))vis[str1[i]]=1;
            else return false;
        }
        int cc=0;int cc2=0;
        for(int i='a';i<='z';i++){
            if(num[i]>0)cc++;
            if(num2[i]>0)cc2++;
        }
        //cout<<cc<<' '<<cc2<<endl;
        if(cc==26&&cc2==26)return false;
        if(cc2>cc)return false;
        return true;
    }
};
```

1. ...a... ...b... 那么所有的str1中的a都要对应b
2. 特殊情况：str1中的字母种类变换后会不变或者减少，当str1字母种类为26时，任何一个字符的变化都会导致字母种类减少，若str2字母种类也为26，return false；