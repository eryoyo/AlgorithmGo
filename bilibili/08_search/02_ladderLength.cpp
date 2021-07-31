//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <set>

/*
	词语阶梯-127

	已知两个单词（分别是起始单词和结束单词），一个单词词典，
	根据转换规则计算从 起始单词到结束单词的最短转换步数
	转换规则：
		1.在转换时，只能转换单词中的一个字符
		2.转换得到的新单词必须在单词词典中

	方法：
		构造图-使用map，key为单词，value为string数组，这些string是由value到达
		的点，然后进行宽度优先搜索
*/

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
			wordList.push_back(beginWord);	//将起始点加到图中
			for(int i = 0; i < wordList.size(); i++){
				graph[wordList[i]] = std::vector<std::string>();
			}
			for(int i = 0; i < wordList.size(); i++){
				for(int j = i + 1; j < wordList.size(); j++){
					if(connect(wordList[i], wordList[j])){
						graph[wordList[i]].push_back(wordList[j]);
						graph[wordList[j]].push_back(wordList[i]);
					}
				}
			}
		}

		int BFS_graph(std::string &beginWord, std::string &endWord,
					std::map<std::string, std::vector<std::string> > &graph){
			std::queue<std::pair<std::string, int> > Q;
			std::set<std::string> visit;
			Q.push(std::make_pair(beginWord, 1));
			visit.insert(beginWord);
			while(!Q.empty()){
				std::string node = Q.front().first;
				int step = Q.front().second;
				Q.pop();
				if(node == endWord){
					return step;
				}
				const std::vector<std::string> &neighbors = graph[node];
				for(int i = 0; i < neighbors.size(); i++){
					if(visit.find(neighbors[i]) ==visit.end()){
						Q.push(std::make_pair(neighbors[i], step + 1));
						visit.insert(neighbors[i]);
					}
				}
			}
			return 0;
		}

		int ladderLength(std::string beginWord, std::string endWord,
				std::vector<std::string>& wordList){
			std::map<std::string, std::vector<std::string> > graph;
			construct_graph(beginWord, wordList, graph);
			return BFS_graph(beginWord, endWord, graph);
		}
};