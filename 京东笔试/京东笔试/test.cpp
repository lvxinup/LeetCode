#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long int up(vector<long long int>& input, vector<long long int>& index){
	vector<long long int>::iterator it;
	long long int output = 1;
	for (int i = 0; i < index.size() - 1; i++){
		for (int j = 0; j < input.size() - 1; j++){
			/*it = find(input.begin(), input.end(), index[i]);*/
			if (index[i] == input[j]){
				//相邻元素相等则继续
				if (j == input.size() - 1){
					output++;
					continue;
				}
				if (index[i + 1] == input[j+1]){

					continue;
				}
				else
					output++;
			}
			else
				continue;
		}
	}
	return output;
}

int main()
{
	long long int N;
	while (cin >> N){
		vector<long long int> input;
		vector<long long int> index;
		long long int tmp;
		while (N--){
			cin >> tmp;
			input.push_back(tmp);
			index.push_back(tmp);
		}
		sort(index.begin(), index.end());
		long long int output1 = up(input, index);
		reverse(index.begin(), index.end());
		long long int output2 = up(input, index);
		if (output1 == index.size())
			output1 = 2147483647;
		if (output2 == index.size())
			output2 = 2147483647;
		long long int output = min(output1, output2);
		cout << output1 << endl;
	}
}