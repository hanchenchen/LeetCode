# 72 Edit Distance*

执行用时 :32 ms, 在所有 C++ 提交中击败了28.81%的用户

内存消耗 :9.6 MB, 在所有 C++ 提交中击败了70.82%的用户

```c++
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1=word1.size()+1;
        int len2=word2.size()+1;
        int arr[len1][len2]={0};
        for(int i=0;i<len1;i++){
            arr[i][0]=i;
        }
        for(int i=0;i<len2;i++){
            arr[0][i]=i;
        }
        for(int i=1;i<len1;i++){
            for(int j=1;j<len2;j++){
                //cout<<i<<j<<endl;
                if(word1[i-1]==word2[j-1]){
                    arr[i][j]=min(min(arr[i-1][j],arr[i][j-1]),arr[i-1][j-1]-1)+1;
                }else{
                    arr[i][j]=min(min(arr[i-1][j],arr[i][j-1]),arr[i-1][j-1])+1;
                }
            }
        }
        return arr[len1-1][len2-1];
    }
};
```

