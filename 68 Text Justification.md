# 68 Text Justification

执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户

内存消耗 :9.5 MB, 在所有 C++ 提交中击败了5.47%的用户

- 没什么巧妙的解法

```c++
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<int> len;
        for(int i=0;i<words.size();i++){
            len.push_back(words[i].size());
        }
        vector<string> ans;
        int l=0;
        while(l<words.size()){
            int r=l+1;
            int num=len[l];
            for(;r<words.size();r++){
                if(maxWidth-num>len[r]){
                    num++;
                    num+=len[r];
                }
                else break;
            }
            int i=maxWidth-num;
            string p=""+words[l];
            if(r<=l+1||r==words.size()){
                for(l++;l<r;l++){
                    p=p+" ";
                    p=p+words[l];
                }
                while(i--){
                p+=" ";
                }
                ans.push_back(p);
                l=r;
                continue;
            }
            
            int j=i%(r-l-1);
            i=i/(r-l-1);
            cout<<i<<j<<endl;
            for(l++;l<r;l++){
                if(j>0){
                    p=p+" ";
                    j--;
                }
                for(int a=0;a<=i;a++){
                    p=p+" ";
                }
                p=p+words[l];
            }
            ans.push_back(p);
        }
        return ans;
    }
};
```

