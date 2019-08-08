# 65 Valid Number

1. 解答错误*8：
   1. true ：".1" "-.1"  "1." " 005047e+6""46.e3" ".2e81"
   2. false："."

执行用时 :8 ms, 在所有 C++ 提交中击败了82.41%的用户

内存消耗 :8.1 MB, 在所有 C++ 提交中击败了89.23%的用户

<!--DFA-->

```c++
class Solution {
public:
    bool isNumber(string s) {
        int state=0;
        for(int i=0;i<s.size();i++){
            //cout<<state<<" "<<s[i]<<endl;
            if(s[i]=='+'||s[i]=='-'){
                if(state==0){
                    state=1;
                }else if(state==6){
                    state=8;
                }else{
                    return false;
                }
            }else if(s[i]==' '){
                if(state==0||state==5){
                    
                }else if(state==2||state==4||state==7){
                    state=5;
                }else{
                    return false;
                }
            }else if(s[i]<='9'&&s[i]>='0'){
                if(state==0||state==1||state==2){
                    state=2;
                }else if(state==4||state==3){
                    state=4;
                }else if(state==6||state==7||state==8){
                    state=7;
                }else{
                    return false;
                }
            }else if(s[i]=='.'){
                if(state==2){
                    state=4;
                }else if(state==0||state==1){
                    state=3;
                }else{
                    return false;
                }
            }else if(s[i]=='e'){
                if(state==2||state==4){
                    state=6;
                }else{
                    return false;
                }
            }else return false;
            
        }
        if(state==2||state==5||state==4||state==7)return true;
        else return false;
    }
};
```

