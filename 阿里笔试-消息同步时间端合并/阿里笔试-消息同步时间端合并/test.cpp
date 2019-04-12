#define  _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <list>
#include <string>
#include<Windows.h>
typedef long int  uint64_t;

struct TimeSegment{
	uint64_t btime;
	uint64_t etime;
	TimeSegment() : btime(0), etime(0){
	}
	TimeSegment(uint64_t btime_, uint64_t etime_) : btime(btime_), etime(etime_){
	}
};


inline void MergeTimeSegment(uint64_t nBeginTime, uint64_t nEndTime, std::list<TimeSegment>& lstTimeSegment){
	// TODO 
	int size = lstTimeSegment.size();
	uint64_t begin = nBeginTime;
	uint64_t end = nEndTime;
	for (std::list<TimeSegment>::iterator it = lstTimeSegment.begin(); it != lstTimeSegment.end(); ++it)
	{
		if (nBeginTime< it->btime)
		{//beginС����߽�
			if (nEndTime<it->btime)
			{//�ұ�ҲС����߽�
				TimeSegment tmp(0, 0);
				lstTimeSegment.push_back(tmp);
				std::list<TimeSegment>::iterator end = lstTimeSegment.end();
				end--;
				for (std::list<TimeSegment>::iterator cur = end; cur != it; cur--)
				{//����Ԫ�����Ų��
					std::list<TimeSegment>::iterator flag = cur;
					flag--;
					cur->btime = flag->btime;
					cur->etime = flag->etime;
				}
				//�����������������
				it->btime = nBeginTime;
				it->etime = nEndTime;
			}
			else
			{//�ұߴ�����߽�
				if (nEndTime <= it->etime)
				{//endС���ұ߽�
					it->btime = begin;
				}
				else
				{//end�����ұ߽�
					it->btime = begin;
					it->etime = end;
				}
			}
		}
	}
}

TimeSegment ParseTimeSegmentString(const std::string& input){
	TimeSegment timestamp;
	size_t nPos = input.find("-");
	size_t nLength = input.length();
	if (nPos > 0 && nPos < nLength){
		try{
			timestamp.btime = std::stoull(input.substr(0, nPos));
			timestamp.etime = std::stoull(input.substr(nPos + 1, nLength));
		}
		catch (...){
			std::cout << "��������Ч����.\n";
		}
	}
	else{
		std::cout << "��������Ч����.\n";
	}

	return timestamp;
}

std::list<TimeSegment> ParseTimeSegmentList(const std::string& input){
	TimeSegment timestamp;
	std::list<TimeSegment> lstTimestamp;
	std::string temp;
	size_t nStartPos = 0;
	size_t nEndPos = input.find(",");
	size_t nLength = input.length();
	while (nEndPos > nStartPos && nEndPos <= nLength){
		temp = input.substr(nStartPos, nEndPos);
		if (temp.size() > 0){
			timestamp = ParseTimeSegmentString(temp);
			lstTimestamp.push_back(timestamp);
		}
		nStartPos = nEndPos + 1;
		nEndPos = input.find(",", nStartPos);
		if (-1 == nEndPos){
			nEndPos = nLength;
		}
	}

	return lstTimestamp;
}

int main(int argc, char *argv[]) {
	std::string input;
	std::cin >> input;
	int nPos = input.find(";");
	std::list<TimeSegment> lstTimestamp = ParseTimeSegmentList(input.substr(0, nPos));
	TimeSegment timestamp = ParseTimeSegmentString(input.substr(nPos + 1, input.size()));

	MergeTimeSegment(timestamp.btime, timestamp.etime, lstTimestamp);

	for (auto it = lstTimestamp.begin(); it != lstTimestamp.end();) {
		std::cout << it->btime << "-" << it->etime;
		if (++it != lstTimestamp.end()){
			std::cout << ",";
		}
	}
	system("pause");
	return 0;
}