# 79 Word Search

执行用时 :968 ms, 在所有 C++ 提交中击败了5.00%的用户

内存消耗 :213.3 MB, 在所有 C++ 提交中击败了6.75%的用户???

```c++
class Solution {
public:
    bool func(string word,vector<vector<char>> board,int index,int x,int y){
        if(index>=word.size())return true;
        board[x][y]='1';
        if(y>0&&word[index]==board[x][y-1]){
            if(func(word,board,index+1,x,y-1))return true;
        }
        if(y<board[0].size()-1&&word[index]==board[x][y+1]){
            if(func(word,board,index+1,x,y+1))return true;
        }
        if(x>0&&word[index]==board[x-1][y]){
            if(func(word,board,index+1,x-1,y))return true;
        }
        if(x<board.size()-1&&word[index]==board[x+1][y]){
            if(func(word,board,index+1,x+1,y))return true;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size()<1||board[0].size()<1)return false;
        for(int i=0;i<board.size() ;i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0])
                    if(func(word,board,1,i,j))
                        return true;
            }
        }
        return false;
    }
};
```

