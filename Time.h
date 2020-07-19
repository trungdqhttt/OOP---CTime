#pragma once
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

class Time
{
private:
	int gio;
	int phut;
	int giay;
public:
	Time() {
		gio = phut = giay = 0;
	}
	void setTime(int h, int p, int s) {
		gio = h;
		phut = p;
		giay = s;
	}
	void setGio(int h) {
		gio = h;
	}
	void setPhut(int p) {
		phut = p;
	}
	void setGiay(int s) {
		giay = s;
	}
	friend ostream& operator << (ostream&, const Time&);
	friend istream& operator >> (istream&, Time&);
	Time operator + (Time);
	Time operator - (Time);
	Time operator ++ ();
	Time operator ++ (int);
	Time operator -- ();
	Time operator -- (int);
	bool operator < (Time);
	bool operator > (Time);
	bool operator == (Time);
	~Time() {};
};

