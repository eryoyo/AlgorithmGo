//
// Created by eryo on 2021/8/7.
//

/*
 * 1.cstdio头文件：程序中处理输入输出
 * 2.scanf printf %d %lld f% lf% c% s%
 * 3.变量类型：int(9),long long(18),float(128),double(1024)
 *           char(127),bool(0,1)
 * 4.0~9(48~57),A~Z(65~90),a~z(97~122)
 * 5.^相同为0，不同为1
 * 6.scanf("%d:%d:%d", &hh, &mm, &ss)
 * 7.除了%c以外，scanf对其他格式符例如%d、s%的输入是以空白符（空格、Tab）
 *  为结束判断标志的
 * 8.%md:保持m位右对齐输出，不足m位用空格补齐
 * 9.%0md:用0补齐
 * 10.%.mf:使浮点数保留m位小数输出，
 * 11.getchar:输入单个字符，可识别换行符，putchar:输出单个字符
 * 12.typedef long long ll:给long long起一个别名ll
 * 13.math函数：fabs(取浮点数绝对值),floor,ceil(向下、上取整)
 *      pow(a, b):返回a的b次方，sqrt:算术平方根，log:以自然对数为底的对数
 *      没有对任意底数求对数的函数，使用换底公式：
 *      以a为底b的对数=以自然对数为底b的对数除以以自然对数为底a的对数
 *      sin,cos,tan,asin,acos,atan,pi=acos(-1.0)
 *      round四舍五入
 * 14.给数组赋初值0：int a[10] = {0}
 * 15.二维数组赋初值：int a[10][10] = {{}, {}, {}}
 * 16.当数组较大时应该定义在主函数的外面10^6
 * 17.memset(数组名， 值， sizeof(数组名)):为数组里面的每一个元素赋相同的初值
 *      string.h头文件，值=0赋全0，值=-1赋全1
 * 18.字符串数组赋初值可以用字符串"hello world"
 *      scanf,printf输入输出：c%识别空格和换行，s%以空格和换行作为分隔符
 *      getchar(),putchar(char)输入输出：识别换行符
 *      gets(str),puts(str)输入输出：以换行符作为分隔符
 *      字符数组的末尾有\0,表示空字符，占用一个字符位
 *      gets和printf会在末尾自动添加，此外需要自己添加\0
 * 19.string.h
 *      strlen(字符数组):返回\0字符前的字符个数，不包含\0
 *      strcmp(字符数组a，字符数组b)：字典序排序
 *          a == b:返回0
 *          a < b:返回负数
 *          a > b:返回正数
 *      strcpy(字符数组a，字符数组b):将b复制给a,包括\0
 *      strcat(字符数组a，字符数组b):将b拼接到a后面
 * 20.sscanf(str, "%d", &n):将str以整数的格式输出到n
 *    sprintf(str, "%d", n):将n以整数的格式写到字符数组中
 * 21.数组作为函数参数的时候，第一维不需要填写长度，第二维需要
 *    数组不允许返回数组
 * 22.指针变量支持加减法操作和自增自减操作，操作单位为其基类型，例如int为其基类型
 *      储存的是int类型变量的地址，那么＋1之后指向当前变量的下一个int
 * 23.数组名称可作为数组的首地址来使用
 * 24.指针的引用：int* &p指针本质也是一个无符号整数，所以可以使用引用
 * 25.cin和cout:iostream
 *      char str[100];  cin.getline(str, 100);
 *      string str; getline(cin, str);
 *      cout设置小数精度：头文件iomanip
 *          cout<<setiosflags(ios::fixed)<<setprecision(2)<<123.4567<<endl
 *          输出123.46
 * 26.浮点数的比较：
 *      const double eps = 1e-8
 *      #define Equal(a, b) ((fabs((a) - (b))) < (eps))
 * 27.圆周率π：const double pi = acos(-1.0)
 * 28.0.00输出为-0.00只能先将结果存到字符串中然后与-0.00比较配合eps修正为0.00
 * 29.sqrt,asin,acos配合eps使得变量在定义域内
 * 30.scanf有返回值，代表成功读入的参数个数，如果读取失败则返回EOF
 *      while(scanf("%d", &n) != EOF)
 *      while(gets(str) != NULL)
 * 31.用一个结构体给另一个结构体赋值的时候，结构体里面假如有字符串数组，赋值的过程中不是用的地址，而是地址上面的值
 */