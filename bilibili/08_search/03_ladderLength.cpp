//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <vector>
#include <string>
#include <map>

/*
	词语阶梯II-127

	已知两个单词（分别是起始单词和结束单词），一个单词词典，
	根据转换规则计算从起始单词到结束单词的所有最短转换路径
	转换规则：
		1.在转换时，只能转换单词中的一个字符
		2.转换得到的新单词必须在单词词典中

	方法：
		构造图-使用map，key为单词，value为string数组，这些string是由value到达
		的点，然后进行宽度优先搜索
*/

struct Qitem{
    std::string node;	//搜索结点
    int parent_pos;		//前驱结点在队列中的位置
    int step;			//到达当前结点的步数
    Qitem(std::string _node, int _parent_pos, int _step) :
            node(_node), parent_pos(_parent_pos), step(_step){}
};

class Solution{
public:
    bool connect(const std::string &word1, const std::string &word2){
        int cnt = 0;	//比较两个字符串之间能否相互转换
        for(int i = 0; i < word1.length(); i++){
            if(word1[i] != word2[i]){
                cnt++;
            }
        }
        return cnt == 1;
    }

    //邻接表形式构造图
    void construct_graph(std::string &beginWord,
                         std::vector<std::string>& wordList,
                         std::map<std::string, std::vector<std::string> > &graph){
        int flag = 0;	//标记wordList中是否已经有beginWord
        for(int i = 0; i < wordList.size(); i++){
            if(wordList[i] == beginWord){
                flag = 1;
            }
        }
        for(int i = 0; i < wordList.size(); i++){
            for(int j = i + 1; j < wordList.size(); j++){
                if(connect(wordList[i], wordList[j])){
                    graph[wordList[i]].push_back(wordList[j]);
                    graph[wordList[j]].push_back(wordList[i]);
                }
            }
            if(flag == 0 && connect(beginWord, wordList[i])){
                graph[beginWord].push_back(wordList[i]);
            }
        }
    }

    int BFS_graph(std::string &beginWord, std::string &endWord,
                  std::map<std::string, std::vector<std::string> > &graph,
                  std::vector<Qitem> &Q,	//队列，保存所有的信息
                  std::vector<int> &end_word_pos){//终点endWord所在队列的下标
        std::map<std::string, int> visit;	//单词到步数的映射
        int min_step = 0;	//到达endWord的最小步数
        Q.push_back(Qitem(beginWord, -1, 1));	//起始单词前驱为-1
        visit[beginWord] = 1;
        int front = 0;	//front指向队列头
        while(front < Q.size()){
            const std::string &node = Q[front].node;
            int step = Q[front].step;
            if(min_step != 0 && step > min_step){	//搜索结束
                break;
            }
            if(node == endWord){
                min_step = step; 	//当搜索到结果时，记录到达终点的最小步数
                end_word_pos.push_back(front);
            }
            const std::vector<std::string> &neighbors = graph[node];
            for(int i = 0; i < neighbors.size(); i++){
                if(visit.find(neighbors[i]) == visit.end() || //结点没被访问
                   visit[neighbors[i]] == step + 1){	//另一条最短路径
                    Q.push_back(Qitem(neighbors[i], front, step + 1));
                    visit[neighbors[i]] = step + 1;
                }
            }
            front++;
        }
        return 0;
    }

    std::vector<std::vector<std::string> > ladderLength(std::string beginWord, std::string endWord,
                                                        std::vector<std::string>& wordList){
        std::map<std::string, std::vector<std::string> > graph;
        construct_graph(beginWord, wordList, graph);
        std::vector<Qitem> Q;
        std::vector<int> end_word_pos;
        BFS_graph(beginWord, endWord, graph, Q, end_word_pos);
        std::vector<std::vector<std::string> > result;
        for(int i = 0; i < end_word_pos.size(); i++){
            int pos = end_word_pos[i];
            std::vector<std::string> path;
            while(pos != -1){
                path.push_back(Q[pos].node);
                pos = Q[pos].parent_pos;
            }
            result.push_back(std::vector<std::string>());
            for(int j = path.size() - 1; j >= 0; j--){
                result[i].push_back(path[j]);
            }
        }
        return result;
    }
};

int main(){
    std::string beginWord = "hit";
    std::string endWord = "cog";
    std::vector<std::string> wordList;
    wordList.push_back("hot");
    wordList.push_back("dot");
    wordList.push_back("dog");
    wordList.push_back("lot");
    wordList.push_back("log");
    wordList.push_back("cog");
    Solution s;
    std::vector<std::vector<std::string> > result = s.ladderLength(beginWord, endWord, wordList);
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            printf("[%s]", result[i][j].c_str());
        }
        printf("\n");
    }
    return 0;

}