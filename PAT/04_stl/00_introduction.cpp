//
// Created by eryo on 2021/8/10.
//

//vector
/*
 * 1.初始化：vector<typename> name;
 *          vector数组:vector<typename> arrayname[size]
 * 2.访问：vec[i]等价于*(vec.begin() + i)
 *      通过下标
 *      通过迭代器：vector<typename>::iterator it = name.begin(); *it; it++;
 *      在常用的STL容器中只有vector和string允许使用it+i的用法
 * 3.vec.push_back(x)
 *   vec.pop_back()
 *   vec.size()
 *   vec.clear():清空vector中所有元素
 *   vec.insert(it, x):在it所指位置处插入一个元素，当前位置原先的元素及其之后的元素后移
 *   vec.erase(it):删除it所指位置的元素
 *   vec.erase(it1, it2):删除[it1,it2)区间内的所有元素
 */

//set
/*
 * 1.初始化:set<typename> name
 *         set数组:set<typename> arrayname[size];
 * 2.访问元素：
 *      迭代器：set<typename>::iterator it = name.begin();
 *             it++;
 *             *it;
 * 3.常用函数：
 *   name.insert(x):复杂度O(logn)
 *   name.find(x):返回集合中值为x的迭代器，时间复杂度为O(logn)
 *   name.erase(it):删除it所指位置的元素，时间复杂度为O(1)
 *   name.erase(x):删除集合中值为x的元素，复杂度为0(logn)
 *   name.erase(it1, it2):删除[it1, it2)区间内的元素
 *   name.size():获取元素的个数，复杂度为O(1)
 *   name.clear():清空所有元素，复杂度为O(n)
 * 4.set的作用是去重并升序排序
 *   multiset允许元素重复
 *   unordered_set:其只实现去重不实现排序，速度更快，
 *          原理为散列实现代替set的红黑树（自平衡二叉树）实现
 */

//string
/*
 * 1.初始化：string str = "abcd";
 *          cin>>str; cout<<str;
 *          scanf不能输入string
 *          printf("%s", str.c_str());
 * 2.访问元素：
 *      通过下标
 *      通过迭代器：string::iterator it = str.begin();
 *                it++;
 *                *it;
 * 3.常用函数：
 *      str1 += str2:将str2拼接到str1后面
 *      str1 = str1 + str2
 *      ==, !=, <, <=, >, >=:以字典序比较两个字符串
 *      str.length(),str.size()
 *      str.insert(pos, string):从下标为pos的位置开始插入字符串，该位置及其之后的元素全部后移
 *      str.insert(it, it1, it2):从it所指位置开始插入it1到it2之间的元素
 *      str.erase(it):删除单个元素
 *      str.erase(it1, it2):删除一个区间内的所有元素
 *      str.erase(pos, length):删除下标为pos开始的length个元素
 *      str.clear():清空元素
 *      str.substr(pos, len):取出len个元素
 *      string::npos:find函数失配时的返回值，常量-1或4294967295
 *      str1.find(str2):当str2是str1的子串的时候，返回第一次出现的位置，否则返回string::npos,复杂度为O(mn)
 *      str.replace(pos, len, str2)
 *      str.replace(it1, it2, str2):将范围内的字符串替换为str2，修改了原字符串
 */

//map-multimap, unordered_map
/*
 * 1.初始化：map<typename1, typename2> mp;key可以为STL类型，但是不能用数组类型
 * 2.访问元素：元素按照key的大小升序排序
 *      通过下标访问
 *      通过迭代器：map<typename1, typename2>::iterator it;
 *                it->first; it->second;
 * 3.常用函数：
 *      mp.find(key):返回key对应的元素的迭代器
 *      mp.erase(it)
 *      mp.erase(key)
 *      mp.erase(it1, it2)
 *      mp.size()
 *      mp.clear()
 */

//queue
/*
 * 1.初始化：queue<typename>name
 * 2.访问元素：q.front()最先进入的元素, q.back()
 * 3.常用函数：
 *      q.front()
 *      q.back()
 *      q.pop()
 *      q.push(x)
 *      q.empty()
 *      q.size()
 */

//priority_queue
/*
 * 1.初始化：priority_queue<typename> name;大顶堆
 * 2.访问元素：q.top();
 * 3.常用函数：
 *      q.push(x):O(logn)
 *      q.top():O(1)
 *      q.pop():O(logn)
 *      q.empty():O(1)
 *      q.size()
 * 4.自定义优先级队列：
 *   基本数据类型：
 *      小顶堆：priority_queue<int, vector<int>, greater<int>> q;
 *      大顶堆(默认)：priority_queue<int, vector<int>, less<int>> q;
 *   结构体：
 *      重载<符号：写在结构体里面
 *          friend bool operator < (student a, student b){
 *              return a.age < b.age;//大顶堆
 *              return a.age > b.age;//小顶堆
 *          }
 *          priority_queue<student> q;
 *      重载：写在结构体外面
 *          struct cmp{
 *              bool operator () (fruit f1, fruit f2){
 *                  return f1.price < f2.price;//大顶堆
 *                  return f1.price > f2.price;//小顶堆
 *              }
 *          }
 *          priority_queue<fruit, vector<fruit>, cmp> q;
 */

//stack
/*
 * 1.初始化：stack<typename> s;
 * 2.访问元素：s.top()
 * 3.常用函数：
 *      s.push(x)
 *      s.top()
 *      s.pop()
 *      s.empty()
 *      s.size()
 */

//pair utility头文件，包含了map头文件也就是包含了utility
//map的元素为元组
/*
 * 1.初始化：pair<typename1, typename2> name(e1, e2);
 *         p = make_pair(e1, e2);
 * 2.访问元素：p.first,p.second;
 * 3.常用函数：
 *      ==, !=, <, <=, >, >=,先比较first，再比较second
 */

//algorithm头文件
/*
 * 1.max(a, b), min(a, b), abs(x)
 * 2.swap(a, b)
 * 3.reverse(it1, it2):将[it1, it2)范围内的元素翻转
 * 4.next_permutation(a, a + 5):返回下一个全排列
 * 5.fill(a, a + 5, 233):将数组指定范围内填充为指定数字
 * 6.sort(it1, it2, cmp),it为指针或者迭代器
 *      bool cmp(int i1, int i2){
 *          return i1 > i2;//递减排列
 *      }
 * 7.lower_bound(it1, it2, val):返回第一个>=val的元素
 *   upper_bound(it1, it2, val):返回第一个>val的元素
 *   否则返回可以插入该元素的指针或者迭代器
 *   找到则返回指针或迭代器
 */