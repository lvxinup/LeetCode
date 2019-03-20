#define  _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		map<string, int> countmap;
		for (auto& word : words)
			countmap[word]++;

		multimap<int, string, greater<int>> sortmap;
		for (auto& countkv : countmap)
			sortmap.insert(make_pair(countkv.second, countkv.first));

		vector<string> ret;
		auto it = sortmap.begin();
		while (it != sortmap.end())
		{
			if (k>0)
			{
				ret.push_back(it->second);
				--k;
			}
			else
			{
				break;
			}
			++it;
		}
		return ret;
	}
};