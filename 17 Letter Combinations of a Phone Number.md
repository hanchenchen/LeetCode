# 17 Letter Combinations of a Phone Number

执行用时 : 8 ms, 在Letter Combinations of a Phone Number的C++提交中击败了95.00% 的用户

内存消耗 : 8.7 MB, 在Letter Combinations of a Phone Number的C++提交中击败了36.79% 的用户

```c++
class Solution {
public:
    vector<string> ans;
    string d;
    int len;
    void func(int n,string s){
        if(n<len){
            char cc=3*(d[n]-'2')+'a';
            if(cc=='s'||cc=='v')cc++;
            func(n+1,s+cc);cc++;
            //cout<<s+cc<<endl;
            func(n+1,s+cc);cc++;
            //cout<<s+cc<<endl;
            func(n+1,s+cc);
            //cout<<s+cc<<endl;
            if(cc=='y'||cc=='r'){
                cc++;func(n+1,s+cc);
            }
            
        }if(n==len){
            ans.push_back(s);
        }
    }
    vector<string> letterCombinations(string digit) {
        len=digit.size();
        d = digit;
        if(len!=0)func(0,"");
        //sort(ans.begin(),ans.end());
        return ans;
    }
};
```

1. 输入为🈳️，输出vector为空

   输入：**""**

   输出：**[""]**

   预期：**[]**

2. 下标和迭代器之间转化

   ```c++
   ans[i]
   ans.begin()+i
   ```

   

