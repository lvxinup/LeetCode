#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<map>

using namespace std;

bool cmy(string tmp1, string tmp2,unordered_map<char,int> map){
	//先比较相等元素的部分
	for (int i = 0; (i < tmp1.size() && i < tmp2.size()); i++){
		if (map[tmp1[i]] == map[tmp2[i]]){
			continue;
		}
		else if (map[tmp1[i]] < map[tmp2[i]]){
			return true;
		}
		else{
			return false;
		}
	}
	//到这里，则说明前面的元素都相等，则长度短的比较大
	if (tmp1.size() < tmp2.size())
		return true;
	else if (tmp1.size() > tmp2.size())
		return false;
}

int main()
{
	string order;	//字典序
	while (getline(cin, order)){
		int tmp;
		cin >> tmp;
		vector<string> input;
		string tmp1;
		getline(cin, tmp1);
		for (int i = 0; i < tmp; i++){
			tmp1 = "";
			getline(cin, tmp1);
			input.push_back(tmp1);
		}
		//构建字典序
		unordered_map<char, int> map;	//将字典序存在map中
		for (int i = 0; i < order.size(); i++){
			map[order[i]] = i;
		}
		vector<string> output;
		output.push_back(input[0]);	//先在输出数组中插入一个元素
		//然后比较并插入
		for (int i = 1; i < input.size(); i++){
			bool index = false;	//用来表示是否插入
			for (int j = 0; j < output.size(); j++){
				//比较并插入,如果input大，则直接插入
				if (cmy(input[i], output[j],map)){
					index = true;
					output.insert(output.begin()+j,input[i]);
					break;
				}
				//如果input小，则往后移动
				else{
					continue;
				}
			}
			//说明没有插入
			if (index == false){
				output.push_back(input[i]);
			}
		}

		//插入完成之后，打印output数组
		for (auto& e : output){
			cout << e << endl;
		}
	}
}