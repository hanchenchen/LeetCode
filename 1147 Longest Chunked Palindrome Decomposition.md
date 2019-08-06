# 1147 Longest Chunked Palindrome Decomposition

```c++
class Solution {
public:
    int longestDecomposition(string text) {
        int i=0,j=text.size()-1;
        int arr['z'+1]={0};
        int flag=0;
        int ans=0;
        while(i<j){
            arr[text[i]]++;
            i++;
            arr[text[j]]--;
            j--;
            flag=2;
            for(int k='a';k<='z';k++){
                if(arr[k]>0){
                    flag=0;break;
                }
            }
            ans+=flag;
        }
        if(i==j)arr[text[i]]++;
        flag=0;
        for(int k='a';k<='z';k++){
                if(arr[k]>0){
                    flag=1;break;
                }
            }
        ans+=flag;
        return ans;
    }
};
```

