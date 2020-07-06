# 36 Valid Sudoku

执行用时 : 28 ms, 在Valid Sudoku的C++提交中击败了79.52% 的用户

内存消耗 : 10.7 MB, 在Valid Sudoku的C++提交中击败了80.62% 的用户

```c++
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> block;
        vector<int> cc;
        for(int i=0;i<9;i++){
            block.push_back(cc);
        }
        for(int i=0;i<9;i++){
            vector<char> row;
            vector<char> col;
            for(int j=0;j<9;j++){
                if(find(row.begin(),row.end(),board[i][j])!=row.end())
                    return false;
                if(find(col.begin(),col.end(),board[j][i])!=col.end())
                    return false;
                if(board[i][j]!='.')
                    row.push_back(board[i][j]);
                if(board[j][i]!='.')
                    col.push_back(board[j][i]);
                int block_num=i/3*3+j/3;
                if(find(block[block_num].begin(),block[block_num].end(),board[i][j])!=block[block_num].end())
                    return false;
                if(board[i][j]!='.')
                    block[block_num].push_back(board[i][j]);
            }
        }
        return true;
    }
};
```

