#pragma once
struct myOwnTimeStruct
{
	int min;
	int hour;
	int day;
	int mon;
	int year;


	void printTime()
	{
		cout << day << "/" << mon << "/" << year  ;
	}
	void printDate()
	{
		cout << hour << ":" << min;
	}
	string TimeToString()
	{
		ostringstream oss;
		oss << hour << ":" << min;
		string str = oss.str();
		return str;
	}
	string DateToString()
	{
		ostringstream oss;
		oss << day << "/" << mon << "/" << year;
		string str = oss.str();
		return str;
	}
	// do structa
	long long int GetHash() {
		long long int value;
		value += year * 100000000;
		value += mon * 1000000;
		value += day * 10000;
		value += hour * 100;
		value += min;
		return value;
	}

	
};
