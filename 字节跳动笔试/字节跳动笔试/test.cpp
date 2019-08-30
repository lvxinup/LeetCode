#define  _CRT_SECURE_NO_WARNINGS 1

//使用一个二维数组，将有关系的放在一行，最后的豆油瓶数量为二维数组的size
//#include<iostream>
//#include<vector>
//#include<unordered_map>
//#include<algorithm>
//
//using namespace std;
//int main()
//{
//	long long int N;
//	while (cin >> N){
//		vector<vector<long long int>> input;
//		for (long long int i = 0; i < N; ++i){
//			vector<long long int> tmp;
//			for (int j = 0; j < N; ++j){
//				long long int cur;
//				cin >> cur;
//				tmp.push_back(cur);
//			}
//			input.push_back(tmp);
//		}
//		vector<vector<long long int>> output;
//		//首先将所有元素遍历一遍
//		for (long long int i = 0; i < input.size(); ++i){
//			for (long long int j = 0; j < input[i].size(); ++j){
//				if (input[i][j] >= 3){
//					//首先在output中查找
//					bool index = false;	//这个用来判断要不要增加豆油瓶的数量
//					for (long long int k = 0; k < output.size(); k++){
//						//如果i在数组中
//						if (find(output[k].begin(), output[k].end(), i + 1) != output[k].end()){
//							index = true;
//							//判断j在不在，不在的话，插入j
//							if (find(output[k].begin(), output[k].end(), j + 1) == output[k].end()){
//								output[k].push_back(j + 1);
//								N--;
//							}
//							//j在数组中的话，则什么都不做，直接跳出后面的判断，豆油瓶数量不变
//							else{
//								break;
//							}
//						}
//						//如果j在数组中
//						else if (find(output[k].begin(), output[k].end(), j + 1) != output[k].end()){
//							index = true;
//							//如果i不在数组中，插入i
//							if (find(output[k].begin(), output[k].end(), i + 1) == output[k].end()){
//								output[k].push_back(i + 1);
//								N--;
//							}
//								
//							//在数组中的话，什么都不做，跳出后面的判断，豆油瓶数量不变
//							else
//								break;
//						}
//					}
//					//如果i，j都不在数组中，则在数组中插入新的一行
//					if (index == false){
//						vector<long long int> temp;
//						temp.push_back(i + 1);
//						temp.push_back(j + 1);
//						output.push_back(temp);
//						N--;
//					}
//				}
//				else
//					continue;
//			}
//		}
//		cout << N << endl;	
//	}
//}


#include<iostream>
#include<vector>

using namespace std;
int main()
{
	int n;
	while (cin >> n){
		vector<vector<long long int>> input;
		for (long long int i = 0; i < 4; ++i){
			vector<long long int> tmp;
			for (int j = 0; j < 4; ++j){
				long long int cur;
				cin >> cur;
				tmp.push_back(cur);
			}
			input.push_back(tmp);
		}
		//根据n判断上下左右
		//向上
		if (n == 1){
			//先合并，然后合并完放在上面的一格，然后另一格补0，最后进行移动，如果上面为0，就向上移动
			//先判断最上面两行能不能合并
			for (int i = 0; i < 4; i++){
				//相等且不为0，则可以合并，
				if ((input[0][i] == input[1][i]) && (input[0][i] != 0) && (input[1][i] != 0)){
					input[0][i] = (input[0][i] + input[1][i]);
					input[1][i] = 0;
				}
				//否则不能合并,不能合并则不用管
			}
			//然后判断下面两行能不能合并
			for (int i = 0; i < 4; i++){
				//相等且不为0，则可以合并，
				if ((input[2][i] == input[3][i]) && (input[2][i] != 0) && (input[3][i] != 0)){
					input[2][i] = (input[2][i] + input[3][i]);
					input[3][i] = 0;
				}
				//否则不能合并,不能合并则不用管
			}
			//然后进行上移，如果上面为0，则向上移动
			for (int i = 0; i < 4; i++){//列
				for (int j = 1;j <=3; j++){//行
					//不为0，且上面为0，则向上移动
					int i1 = i, j1 = j;
					while (input[j1][i1] != 0 && input[j1-1][i1] == 0){
						//数字上移，并将原来的位置置0
						input[j1 - 1][i1] = input[j1][i1];
						input[j1][i1] = 0;
						j1--;
						if (j1 == 0)
							break;
					}
				}
			}
		}
		else if (n == 2){
			//先合并，然后合并完放在下面的一格，然后另一格补0，最后进行移动，如果下面为0，就向下移动
			//先判断最上面两行能不能合并
			for (int i = 0; i < 4; i++){
				//相等且不为0，则可以合并，
				if ((input[0][i] == input[1][i]) && (input[0][i] != 0) && (input[1][i] != 0)){
					input[1][i] = (input[0][i] + input[1][i]);
					input[0][i] = 0;
				}
				//否则不能合并,不能合并则不用管
			}
			//然后判断下面两行能不能合并
			for (int i = 0; i < 4; i++){
				//相等且不为0，则可以合并，
				if ((input[2][i] == input[3][i]) && (input[2][i] != 0) && (input[3][i] != 0)){
					input[3][i] = (input[2][i] + input[3][i]);
					input[2][i] = 0;
				}
				//否则不能合并,不能合并则不用管
			}
			//然后进行下移，如果下面为0，则向下移动
			for (int i = 0; i < 4; i++){//列
				for (int j = 2; j >=0; j--){//行
					//不为0，且上面为0，则向上移动
					int i1 = i, j1 = j;
					while (input[j1][i1] != 0 && input[j1 + 1][i1] == 0){
						//数字上移，并将原来的位置置0
						input[j1 + 1][i1] = input[j1][i1];
						input[j1][i1] = 0;
						j1++;
					}
				}
			}
		}
		//向左移动
		else if (n == 3){
			//先合并，然后合并完放在左面的一格，然后另一格补0，最后进行移动，如果左面为0，就向左移动
			//先判断最左面两行能不能合并
			for (int i = 0; i < 4; i++){
				//相等且不为0，则可以合并，
				if ((input[i][0] == input[i][1]) && (input[i][0] != 0) && (input[i][1] != 0)){
					input[i][0] = (input[i][0] + input[i][1]);
					input[i][1] = 0;
				}
				//否则不能合并,不能合并则不用管
			}
			//然后判断下面两行能不能合并
			for (int i = 0; i < 4; i++){
				//相等且不为0，则可以合并，
				if ((input[i][2] == input[i][3]) && (input[i][2] != 0) && (input[i][3] != 0)){
					input[i][2] = (input[i][2] + input[i][3]);
					input[i][3] = 0;
				}
				//否则不能合并,不能合并则不用管
			}
			//然后进行左移，如果左面为0，则向左移动
			for (int i = 0; i < 4; i++){//行
				for (int j = 3; j >=1; j--){//列
					//不为0，且上面为0，则向左移动
					int i1 = i, j1 = j;
					while (input[i1][j1] != 0 && input[i1][j1-1] == 0){
						//数字上移，并将原来的位置置0
						input[i1][j1-1] = input[i1][j1];
						input[i1][j1] = 0;
						j1++;
					}
				}
			}
		}
		//右移
		else if (n == 4){
			//先合并，然后合并完放在左面的一格，然后另一格补0，最后进行移动，如果左面为0，就向左移动
			//先判断最左面两行能不能合并
			for (int i = 0; i < 4; i++){
				//相等且不为0，则可以合并，
				if ((input[i][0] == input[i][1]) && (input[i][0] != 0) && (input[i][1] != 0)){
					input[i][1] = (input[i][0] + input[i][1]);
					input[i][0] = 0;
				}
				//否则不能合并,不能合并则不用管
			}
			//然后判断下面两行能不能合并
			for (int i = 0; i < 4; i++){
				//相等且不为0，则可以合并，
				if ((input[i][2] == input[i][3]) && (input[i][2] != 0) && (input[i][3] != 0)){
					input[i][3] = (input[i][2] + input[i][3]);
					input[i][2] = 0;
				}
				//否则不能合并,不能合并则不用管
			}
			//然后进行左移，如果左面为0，则向左移动
			for (int i = 0; i < 4; i++){//行
				for (int j = 2; j>=0; j--){//列
					//不为0，且上面为0，则向左移动
					if (input[i][j] != 0 && input[i][j+1] == 0){
						//数字上移，并将原来的位置置0
						input[i][j+1] = input[i][j];
						input[i][j] = 0;
					}
				}
			}
		}

		//打印
		for (int i = 0; i < 4; i++){
			for (int j = 0; j < 4; j++){
				cout << input[i][j] << " ";
			}
			cout << endl;
		}
	}
}