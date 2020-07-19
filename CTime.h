#pragma once
#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<math.h>
using namespace std;

class CTime
{
private:
	int hour;
	int minute;
	int second;
public:
	CTime() {
		hour = minute = second = 0;
	}
	void setTime(int h, int m, int s) {
		hour = h;
		minute = m;
		second = s;
	}
	void setHour(int h) {
		hour = h;
	}
	void setMinute(int m) {
		minute = m;
	}
	void setSecond(int s) {
		second = s;
	}
	int totalSecond() {
		return hour * 60 * 60 + minute * 60 + second;
	}
	friend ostream& operator << (ostream&, const CTime&);
	friend istream& operator >> (istream&, CTime&);
	CTime operator + (CTime); // Timespan +
	CTime operator + (int); // Cộng một giá trị giây bất kỳ
	CTime operator - (CTime); // Timespan -
	CTime operator - (int); // Trừ một giá trị giây bất kỳ
	CTime operator ++ (); // Tăng 1 giây
	CTime operator ++ (int); // Tăng 1 giây
	CTime operator -- (); // Giảm 1 giây
	CTime operator -- (int); // Tăng 1 giây
	bool operator < (CTime);
	bool operator <= (CTime);
	bool operator > (CTime);	
	bool operator >= (CTime);
	bool operator == (CTime);
	bool operator != (CTime);
	friend void Menu(CTime, CTime);
	~CTime() {};
};



