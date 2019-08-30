#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<map>

using namespace std;

bool cmy(string tmp1, string tmp2,unordered_map<char,int> map){
	//�ȱȽ����Ԫ�صĲ���
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
	//�������˵��ǰ���Ԫ�ض���ȣ��򳤶ȶ̵ıȽϴ�
	if (tmp1.size() < tmp2.size())
		return true;
	else if (tmp1.size() > tmp2.size())
		return false;
}

int main()
{
	string order;	//�ֵ���
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
		//�����ֵ���
		unordered_map<char, int> map;	//���ֵ������map��
		for (int i = 0; i < order.size(); i++){
			map[order[i]] = i;
		}
		vector<string> output;
		output.push_back(input[0]);	//������������в���һ��Ԫ��
		//Ȼ��Ƚϲ�����
		for (int i = 1; i < input.size(); i++){
			bool index = false;	//������ʾ�Ƿ����
			for (int j = 0; j < output.size(); j++){
				//�Ƚϲ�����,���input����ֱ�Ӳ���
				if (cmy(input[i], output[j],map)){
					index = true;
					output.insert(output.begin()+j,input[i]);
					break;
				}
				//���inputС���������ƶ�
				else{
					continue;
				}
			}
			//˵��û�в���
			if (index == false){
				output.push_back(input[i]);
			}
		}

		//�������֮�󣬴�ӡoutput����
		for (auto& e : output){
			cout << e << endl;
		}
	}
}