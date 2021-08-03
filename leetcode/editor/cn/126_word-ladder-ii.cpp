//按字典 wordList 完成从单词 beginWord 到单词 endWord 转化，一个表示此过程的 转换序列 是形式上像 beginWord -> s
//1 -> s2 -> ... -> sk 这样的单词序列，并满足： 
//
// 
// 
// 
// 每对相邻的单词之间仅有单个字母不同。 
// 转换过程中的每个单词 si（1 <= i <= k）必须是字典 wordList 中的单词。注意，beginWord 不必是字典 wordList 中的单
//词。 
// sk == endWord 
// 
//
// 给你两个单词 beginWord 和 endWord ，以及一个字典 wordList 。请你找出并返回所有从 beginWord 到 endWord 的
// 最短转换序列 ，如果不存在这样的转换序列，返回一个空列表。每个序列都应该以单词列表 [beginWord, s1, s2, ..., sk] 的形式返回。 
//
// 
//
// 示例 1： 
//
// 
//输入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","lo
//g","cog"]
//输出：[["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
//解释：存在 2 种最短的转换序列：
//"hit" -> "hot" -> "dot" -> "dog" -> "cog"
//"hit" -> "hot" -> "lot" -> "log" -> "cog"
// 
//
// 示例 2： 
//
// 
//输入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","lo
//g"]
//输出：[]
//解释：endWord "cog" 不在字典 wordList 中，所以不存在符合要求的转换序列。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= beginWord.length <= 7 
// endWord.length == beginWord.length 
// 1 <= wordList.length <= 5000 
// wordList[i].length == beginWord.length 
// beginWord、endWord 和 wordList[i] 由小写英文字母组成 
// beginWord != endWord 
// wordList 中的所有单词 互不相同 
// 
// 
// 
// Related Topics 广度优先搜索 哈希表 字符串 回溯 
// 👍 464 👎 0

/*
 * 题解
我们可以把起始字符串、终止字符串、以及单词表里所有的字符串想象成节点。若两个字符
串只有一个字符不同，那么它们相连。因为题目需要输出修改次数最少的所有修改方式，因此我
们可以使用广度优先搜索，求得起始节点到终止节点的最短距离。
我们同时还使用了一个小技巧：我们并不是直接从起始节点进行广度优先搜索，直到找到终
止节点为止；而是从起始节点和终止节点分别进行广度优先搜索，每次只延展当前层节点数最少
的那一端，这样我们可以减少搜索的总结点数。举例来说，假设最短距离为 4，如果我们只从一
端搜索 4 层，总遍历节点数最多是 1 + 2 + 4 + 8 + 16 = 31；而如果我们从两端各搜索两层，总遍
历节点数最多只有 2 × (1 + 2 + 4) = 14。
在搜索结束后，我们还需要通过回溯法来重建所有可能的路径。
 */

#include <string>
#include <vector>
#include<unordered_map>
#include <unordered_set>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        unordered_set<string> dict;
        for(const auto &w : wordList){
            dict.insert(w);
        }
        if(!dict.count(endWord)){
            return ans;
        }
        dict.erase(beginWord);
        dict.erase(endWord);
        unordered_set<string> q1{beginWord};
        unordered_set<string> q2{endWord};
        unordered_map<string, vector<string>> next;
        bool reversed = false;
        bool found = false;
        while(!q1.empty()){
            unordered_set<string> q;
            for(const auto &w : q1){
                string s = w;
                for(size_t i = 0; i < s.size(); i++){
                    char ch = s[i];
                    for(int j = 0; j < 26; j++){
                        s[j] = j + 'a';
                        if(q2.count(s)){
                            reversed ? next[s].push_back(w) : next[w].push_back(s);
                            found = true;
                        }
                        if(dict.count(s)){
                            reversed ? next[s].push_back(w) : next[w].push_back(s);
                            q.insert(s);
                        }
                    }
                    s[i] = ch;
                }
            }
            if(found){
                break;
            }
            for(const auto &w : q){
                dict.erase(w);
            }
            if(q.size() <= q2.size()){
                q1 = q;
            } else{
                reversed = !reversed;
                q1 = q2;
                q2 = q;
            }
        }
        if(found){
            vector<string> path = {beginWord};
            backtracking(beginWord, endWord, next, path, ans);
        }
        return ans;
    }

    void backtracking(const string & src, const string &dst,
                      unordered_map<string, vector<string>>& next,
                      vector<string> &path,
                      vector<vector<string>> &ans){
        if(src == dst){
            ans.push_back(path);
            return;
        }
        for(const auto &s : next[src]){
            path.push_back(s);
            backtracking(s, dst, next, path, ans);
            path.pop_back();
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
