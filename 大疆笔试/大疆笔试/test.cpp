#define  _CRT_SECURE_NO_WARNINGS 1

//
//在零食间里有一个零食柜，里面会半价供应很多好吃的零食，柜子被隔成了一个个小格子，类似一个矩阵，
//每个格子里会放置由前台小姐姐们精心挑选的零食，并且标上相应的价格。
//
//小A是一个大吃货，每天他都要光顾一次零食间，但是他又要减肥，于是他便对自己做了一个约束，
//每次只能从里面拿走总价格少于V的零食。这时候问题来了，对于每种零食，小A都有一个内心的满意度，小A希望每次都能吃上让自己最满意的零食。
//
//假设零食柜里每个格只放置一种零食，每种零食的数量是有限的，买完就没有了，
//零食只能按照整数倍购买，不能只买半件。问小A在有限价格内买到的零食的总满意度最高是多少？
//
//输入
//输入包含多组测试数据，每组数组 :
//
//第一行有两个正整数 N, T, 分别表示，零食的种类数目 和 小A最多用于购买零食的钱。（1 <= N <= 100, 1 <= T <= 10000）
//
//接下来有N行，每行有三个正整数用空格隔开，按顺序表示 零食需要的价格v，满意度l 和 零食的数量c。
//(1 <= v <= 100, 1 <= l <= 100, 1 <= c <= 100)
//
//输出
//对于每组测试数据 :
//
//输出一个正整数，如果无法购买任何一个零食输出0，否则输出最大的满意度。
//
//
//样例输入
//2 10
//1 1 1
//1 1 1
//3 100
//26 100 4
//5 1 4
//5 2 2
//样例输出
//2
//306

//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<map>
//
//using namespace std;
//
//int main()
//{
//	int a, b;
//	while (cin >> a >> b){
//		map<float, int> primary;	//满意度和价格之比，即每单位满意度的大小
//		vector<vector<int>> input;
//		vector<float> temp;
//		for (int i = 0; i<a; i++){
//			vector<int> tmp;
//			int x, y, z;
//			cin >> x >> y >> z;
//			tmp.push_back(x);
//			tmp.push_back(y);
//			tmp.push_back(z);
//			input.push_back(tmp);
//			primary[(float)y / x] = i;	//性价比与编号的键值对
//			temp.push_back((float)y / x);
//		}
//		int output = 0;
//		std::sort(temp.begin(), temp.end());
//		for (int i = temp.size()-1; i >=0; i--){
//			int id = primary[temp[i]];
//			int nums = input[id][2];//商品数量
//			int price = input[id][0];//商品单价
//			while (b < nums*price){
//				nums--;
//			}
//			b = b - (nums*price);	//买完性价比最高的剩下的钱
//			output += nums*input[id][1];
//		}
//		cout << output << endl;
//	}
//
//	return 0;
//}

//题目描述：
//自从零食间开始免费供应上好的咖啡豆，小杰每天午休后都会来到零食间，按下咖啡机的按钮，
//等待着杯里弥漫开来的香气把自己淹没，纷乱的思绪也渐渐在水雾中模糊。"小杰，你还有N个bug没修，别摸鱼了，快来解bug！"，
//一个不合时宜的声音往往会在此时响起，小杰的脑海中瞬间闪过了无数个文件，无数行代码随着咖啡的香气不断滚动。
//
//"我是不可能写bug的，这辈子都不可能写bug的...", 小杰一边念叨着，一边开始在脑海里盘算起来。
//
//假设每喝一杯咖啡（喝咖啡的时间忽略不计），就能让自己一小时内的debug效率提升到原来的A倍，
//一小时内重复喝没用，最多只能喝X杯，太多了晚上会睡不着，并且为了保证可持续发展，每天最多只能专注工作8个小时，
//而在没喝咖啡的状态下解决每个bug所需要的时间为 t1,t2...tN 分钟。
//
//小杰的咖啡还没有喝完，你能帮他计算出他今天能解完所有bug吗？如果能，最少需要多长时间？
//
//输入
//输入包含多组测试数据，每组数组:
//
//第一行有三个正整数 N, A, X, 分别表示，bug的总数，喝一杯咖啡在一小时内debug效率的倍数，
//最多可以喝的咖啡数目。（1 <= N <= 100, 1 <= A <= 8, 1 <= X <= 8）
//
//第二行有N个正整数，由空格分割开，第i个正整数ti表示解决第i个bug需要的分钟数，（1 <= ti <= 1000）
//
//输出
//对于每组测试数据:
//
//输出一个数字，如果不能解完所有bug，则输出0，如果可以，则输出最少需要的分钟数T（T为正整数，如不满一分钟则按一分钟计算，一旦超过8小时则认为不能解完）
//
//
//样例输入
//8 2 8
//60 60 60 60 60 60 60 60
//4 3 3
//333 77 100 13
//样例输出
//240
//175

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int main()
{
	int N = 0, A = 0, X = 0;
	while (cin >> N >> A >> X){
		vector<int> bugtime;
		for (int i = 0; i<N; i++){
			int tmp = 0;
			cin >> tmp;
			bugtime.push_back(tmp);
		}
		int alltime = 0;	//	总时间
		for (int i = 0; i<bugtime.size(); i++){
			alltime += bugtime[i];
		}
		if (alltime <= A*X * 60){
			//所有时间都有咖啡
			if (alltime %A ==0)
				alltime /= A;
			else{
				alltime /= A;
				alltime++;
			}		
		}
		else{
			int nums = X;
			while (nums--){	//一个小时的咖啡作用，总时间少 倍数*60分钟
				alltime -= (A - 1) * 60;
			}

		}
		if (alltime >= 640)
			cout << "0" << endl;
		else
			cout << alltime << endl;
	}
}