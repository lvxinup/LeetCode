#define  _CRT_SECURE_NO_WARNINGS 1


//本题需要让你模拟一下在Windows系统里窗口和鼠标点击的操作，具体如下：
//1.屏幕分辨率为3840 * 2160，左上角坐标为(0, 0)， 右下角坐标为(3839, 2159)
//2.窗口是一个矩形的形状，由左上角坐标(X, Y)，和宽高(W, H)，四个数字来定位。
//左上角坐标为(X, Y)、右下角坐标为(X + W, Y + H)，其中左上角坐标一定会在屏幕范围内，其他一些部分可能会超过屏幕范围。
//3.窗口的点击和遮挡规则同Windows，但是不考虑关闭窗口、最大化、最小化和强制置顶的情况。即
//3.1 如果发生重叠的话，后面打开的窗口会显示在前面打开的窗口上面
//3.2 当鼠标发生一次点击的时候，需要判断点击到了哪个窗口，如果同个坐标有多个窗口，算点击到最上层的那个
//3.3 当一个窗口被点击的时候，会浮动到最上层
//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//
////根据坐标和窗口判断的函数
//bool inwindow(vector<int> zuobiao, vector<int> chuangkou){
//	if ((zuobiao[0] >= chuangkou[0] && zuobiao[0] <= chuangkou[2]) && (zuobiao[1] >= chuangkou[1] && zuobiao[1] <= chuangkou[3])){
//		return true;
//	}
//	else{
//		return false;
//	}
//}
//
//int main()
//{
//	int a, b;
//	//a代表窗口数目，b代表点击次数
//	while (cin >> a >> b){
//		vector<vector<int>> window;    //窗口
//		vector<vector<int>> index;    //点击位置
//		int mainwindow = 2;    //主窗口ID
//		vector<int> primary(a + 1);    //窗口优先级
//		for (int i = 1; i <= a; i++){
//			primary[i] = i;
//		}
//		int x, y, w, h;
//		while (a--){
//			cin >> x >> y >> w >> h;
//			//3840*2160
//			if (x + w >= 3840)
//				w = 3839;
//			if (y + h >= 2160)
//				h = 2159;
//			vector<int> tmp1;
//			tmp1.push_back(x);
//			tmp1.push_back(y);
//			tmp1.push_back(x + w);
//			tmp1.push_back(y + h);
//			window.push_back(tmp1);
//		}
//		int x1, y1;
//		for(int i = 0;i<b;i++){
//			cin >> x1 >> y1;
//			vector<int> tmp2;
//			tmp2.push_back(x1);
//			tmp2.push_back(y1);
//			index.push_back(tmp2);
//		}
//		vector<int> output;    //输出数组
//		for (int i = 0; i<index.size(); i++){
//			int temp;
//			bool need = false;//判断是否需要更新窗口优先级
//			bool output1 = false;
//			for (int j = primary.size() - 1; j >= 1; j--){
//				if (inwindow(index[i], window[primary[j] - 1])){
//					output.push_back(primary[j]);
//					temp = j;
//					need = true;
//					output1 = true;
//					break;
//				}
//			}
//			if (output1 == false){
//				output.push_back(-1);
//			}
//			if (need){
//				//更改窗口优先级
//				int flag = primary[temp];
//				for (int k = temp; k<=primary.size() - 2; k++){
//					primary[k] = primary[k + 1];
//				}
//				primary[primary.size() - 1] = flag;
//			}
//		}
//
//		//打印窗口id，output数组
//		for (int i = 0; i<output.size(); i++){
//			cout << output[i] << endl;
//		}
//	}
//
//
//	return 0;
//}


//游戏规则如下
//- 在棋盘上有N个数字（A1~AN）从左到右排列成一行
//- A，B两个玩家轮流进行游戏，第一回合A玩家行动，第二回合B玩家行动，依次行动直到游戏结束
//- 每回合玩家可以选择拿走棋盘上最左边或者最右边的一个数字，其余的都不能拿
//- 拿走的数字依次从左到右排列在自己面前
//- 棋盘上所有数字被拿走后游戏结束
//- 最优策略的说明：在任意局面下，玩家如果取左边的数字或者取右边的数字，最终最优得分都一样，那么只能取左边的数字
//
//当所有数字都被拿走后，A, B两个玩家面前都各有一个数列。
//假设A玩家面前数字从左到右为 X1, X2, X3...XM，则他的最终得分Sa计算方式如下（B玩家的得分计算Sb也类似，不赘述）：
//Sa = abs(X1 - 0) + abs(X2 - X1) + abs(X3 - X2) + ... + abs(XM - X(M - 1))
//
//
//请计算在以上的规则下，如果两个玩家都想拿到尽量多的分数，用最优策略进行游戏，计算两个人的最终得分。
//输入描述:
//第一行一个数字 N, 一半的测试用例(0 < N <= 50)，一半的测试用例(0 < N <= 1000)
//	第二行N个数字 Ai(0 <= Ai <= 50)
//输出描述 :
//	 用空格隔开的两个整数Sa和Sb
//	 示例1输入输出示例仅供调试，后台判题数据一般不包含示例
//	 输入
//	 4
//	 1 2 3 4
//	 输出
//   7 4



#include<iostream>
#include<vector>
#include<math.h>
using namespace std;


int main()
{
	int N;
	while (cin >> N){
		int tmp;
		vector<int> input;
		for (int i = 0; i<N; i++){
			cin >> tmp;
			input.push_back(tmp);
		}
		long long int sa = 0, sb = 0;
		vector<int> v1(1, 0);
		vector<int> v2(1, 0);
		int left = 0, right = input.size() - 1;//表示数据的长度
		//0个元素
		if (N == 0){
			cout << "0" << " " << "0" << endl;
			continue;
		}

		//一个元素
		if (N == 1){
			cout << input[0] << " " << "0" << endl;
			continue;
		}
		while (left <= right){
			if (right<left)
				break;
			//a先拿
			//右边大
			if (abs(input[right] - v1[v1.size() - 1]) > abs(input[left] - v1[v1.size() - 1])){
				v1.push_back(input[right]);
				sa += abs(v1[v1.size() - 1] - v1[v1.size() - 2]);
				right--;
			}
			else{//左边大
				v1.push_back(input[left]);
				sa += abs(v1[v1.size() - 1] - v1[v1.size() - 2]);
				left++;
			}
			if (right<left)
				break;
			//b后拿
			//右边大
			if (abs(input[right] - v2[v2.size() - 1]) > abs(input[left] - v2[v2.size() - 1])){
				v2.push_back(input[right]);
				sb += abs(v2[v2.size() - 1] - v2[v2.size() - 2]);
				right--;
			}
			else{//左边大
				v2.push_back(input[left]);
				sb += abs(v2[v2.size() - 1] - v2[v2.size() - 2]);
				left++;
			}
		}
		cout << sa << " " << sb << endl;
	}

	return 0;
}