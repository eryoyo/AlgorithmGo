//n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。 
//
// 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。 
//
// 
// 
// 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 4
//输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
//解释：如上图所示，4 皇后问题存在两个不同的解法。
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：[["Q"]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 9 
// 皇后彼此不能相互攻击，也就是说：任何两个皇后都不能处于同一条横行、纵行或斜线上。 
// 
// 
// 
// Related Topics 数组 回溯 
// 👍 957 👎 0

/*
 * 题解
类似于在矩阵中寻找字符串，本题也是通过修改状态矩阵来进行回溯。不同的是，我们需要
对每一行、列、左斜、右斜建立访问数组，来记录它们是否存在皇后。
本题有一个隐藏的条件，即满足条件的结果中每一行或列有且仅有一个皇后。这是因为我们
一共只有 n 行和 n 列。所以如果我们通过对每一行遍历来插入皇后，我们就不需要对行建立访问
数组了。
 */

#include <string>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        if(n == 0){
            return ans;
        }
        vector<string> board(n, string(n, '.'));
        vector<bool> column(n, false);
        vector<bool> ldiag(2 * n - 1, false);
        vector<bool> rdiag(2 * n - 1, false);
        backtracking(ans, board, column, ldiag, rdiag, 0, n);
        return ans;
    }

    void backtracking(vector<vector<string>> &ans,
                      vector<string> &board,
                      vector<bool> &column,
                      vector<bool> &ldiag,
                      vector<bool> &rdiag,
                      int row, int n){
        if(row == n){
            ans.push_back(board);
            return;
        }
        for(int i = 0; i < n; ++i){
            if(column[i] || ldiag[n - row + i - 1] || rdiag[row + i +1]){
                continue;
            }
            //修改当前结点状态
            board[row][i] = 'Q';
            column[i] = ldiag[n - row + i - 1] = rdiag[row + i + 1] = true;
            //递归子节点
            backtracking(ans, board, column, ldiag, rdiag, row + 1, n);
            //回改当前结点状态
            board[row][i] = '.';
            column[i] = ldiag[n - row + i - 1] = rdiag[row + i + 1] = false;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
