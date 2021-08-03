//给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。 
//
// 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。 
//
// 
//
// 示例 1： 
//
// 
//输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "AB
//CCED"
//输出：true
// 
//
// 示例 2： 
//
// 
//输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SE
//E"
//输出：true
// 
//
// 示例 3： 
//
// 
//输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "AB
//CB"
//输出：false
// 
//
// 
//
// 提示： 
//
// 
// m == board.length 
// n = board[i].length 
// 1 <= m, n <= 6 
// 1 <= word.length <= 15 
// board 和 word 仅由大小写英文字母组成 
// 
//
// 
//
// 进阶：你可以使用搜索剪枝的技术来优化解决方案，使其在 board 更大的情况下可以更快解决问题？ 
// Related Topics 数组 回溯 矩阵 
// 👍 973 👎 0

/*
 * 题解
不同于排列组合问题，本题采用的并不是修改输出方式，而是修改访问标记。在我们对任意
位置进行深度优先搜索时，我们先标记当前位置为已访问，以避免重复遍历（如防止向右搜索后
又向左返回）；在所有的可能都搜索完成后，再回改当前位置为未访问，防止干扰其它位置搜索
到当前位置。使用回溯法，我们可以只对一个二维的访问矩阵进行修改，而不用把每次的搜索状
态作为一个新对象传入递归函数中。
 */

#include <vector>
#include <string>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty()){
            return false;
        }
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        bool find = false;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                backtracking(i, j, board, word, find, visited, 0);
            }
        }
        return find;
    }

    void backtracking(int i, int j,
                      vector<vector<char>>& board,
                      string& word, bool& find,
                      vector<vector<bool>>& visited,
                      int pos){
        if(i < 0 || i >= board.size() ||
        j < 0 || j >= board[0].size()){
            return;
        }
        if(visited[i][j] || find || board[i][j] != word[pos]){
            return;
        }
        if(pos == word.size() - 1){
            find = true;
            return;
        }
        visited[i][j] = true;
        backtracking(i + 1, j, board, word, find, visited, pos + 1);
        backtracking(i - 1, j, board, word, find, visited, pos + 1);
        backtracking(i, j + 1, board, word, find, visited, pos + 1);
        backtracking(i, j - 1, board, word, find, visited, pos + 1);
        visited[i][j] = false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
