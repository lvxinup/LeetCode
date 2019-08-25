#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>

using namespace std;

void find(vector<long long int>& input, long long int& target,int left,int right)
{
	if (input[(left + right) / 2] == target){
		cout << (left + right) / 2 << endl;
		return;
	}
	if (input[(left + right) / 2] < target){
		find(input, target, (left + right) / 2+1, right);
	}
	else if (input[(left + right) / 2] > target){
		find(input, target, left, (left + right) / 2 - 1);
	}
}

int main()
{ 
	long long int N;
	long long int target;
	while (cin >> N){
		vector<long long int> input;
		long long int tmp;
		for (int i = 0; i < N; i++){
			cin >> tmp;
			input.push_back(tmp);
		}
		
		cin >> target;

		find(input,target,0,input.size()-1);
	}


	return 0;
}

#include<iostream>
using namespace std;

int main()
{
	long long int input;
	while (cin >> input){
		long long int tmp1 = input / 2;
		long long int tmp2 = input / 2;
		if (tmp1 * 2 != input)
			tmp2++;
		cout << tmp1*tmp2 << endl;
	}
}
