#include "Time.h"

// Nhập cin >>
istream& operator >> (istream& is, Time& t) {
	do {
		cout << "\n Nhap gio: ";
		is >> t.gio;
		cout << "\n Nhap phut: ";
		is >> t.phut;
		cout << "\n Nhap giay: ";
		is >> t.giay;
		if (t.gio < 0 || t.gio > 23
			|| t.phut < 0 || t.phut > 59
			|| t.giay < 0 || t.giay > 59) {
			cout << "\n Thoi gian khong hop le.";
			cout << "\n Vui long nhap lai!\n";
		}
	} while (t.gio < 0 || t.gio > 23 || t.phut < 0 || t.phut > 59 || t.giay < 0 || t.giay > 59);
	return is;
}
// Xuất cout <<
ostream& operator << (ostream& os, const Time& t) {
	if (t.gio <= 12) {
		os << setfill('0') << setw(2) << t.gio << ":";
		os << setfill('0') << setw(2) << t.phut << ":";
		os << setfill('0') << setw(2) << t.giay << " AM" << endl;
	}
	else {
		os << setfill('0') << setw(2) << t.gio << ":";
		os << setfill('0') << setw(2) << t.phut << ":";
		os << setfill('0') << setw(2) << t.giay << " PM" << endl;
	}
	return os;
}

// Toán tử +
Time Time::operator +(Time t) {
	Time tong;
	int soDu;
	int soNguyen;
	tong.setTime(gio + t.gio, phut + t.phut, giay + t.giay);

	if (tong.giay >= 60) {
		soDu = tong.giay % 60;
		soNguyen = tong.giay / 60;
		tong.setGiay(soDu);
		tong.phut += soNguyen;
	}
	if (tong.phut >= 60) {
		soDu = tong.phut % 60;
		soNguyen = tong.phut / 60;
		tong.setPhut(soDu);
		tong.gio += soNguyen;
	}
	if (tong.gio >= 24) {
		if (tong.gio == 24) {
			tong.setGio(0);
		}
		else {
			tong.setGio(tong.gio % 24);
		}
	}
	return tong;
}
// Toán tử -
Time Time::operator -(Time t) {
	Time hieu;

	if (gio == t.gio && phut == t.phut && giay == t.giay) {
		hieu.setTime(0, 0, 0);
	}
	else {
		hieu.setTime(gio - t.gio, phut - t.phut, giay - t.giay);
		if (hieu.gio < 0) {
			hieu.setGio(24 - abs(hieu.gio));
		}
		if (hieu.phut < 0) {
			hieu.setPhut(60 - abs(hieu.phut));
		}
		if (hieu.giay < 0) {
			hieu.setGiay(60 - abs(hieu.giay));
		}
	}
	return hieu;
}
// Toán tử <
bool Time::operator < (Time t) {
	if (gio < t.gio) {
		return true;
	}
	else if (gio > t.gio) {
		return false;
	}
	else {
		if (phut < t.phut) {
			return true;
		}
		else if (phut > t.phut) {
			return false;
		}
		else {
			if (giay < t.giay) {
				return true;
			}
			else {
				return false;
			}
		}
	}
}
// Toán tử >
bool Time::operator > (Time t) {
	if (gio > t.gio) {
		return true;
	}
	else if (gio < t.gio) {
		return false;
	}
	else {
		if (phut > t.phut) {
			return true;
		}
		else if (phut < t.phut) {
			return false;
		}
		else {
			if (giay > t.giay) {
				return true;
			}
			else {
				return false;
			}
		}
	}
}
// Toán tử ==
bool Time::operator == (Time t) {
	return (gio == t.gio && phut == t.phut && giay == t.giay);
}

Time Time::operator ++ () {
	giay++;
	if (giay == 60) {		
		setGiay(0);
		phut++;
	}
	if (phut == 60) {
		setPhut(0);
		gio++;
	}
	if (gio == 24) {
		setGio(0);
	}
	return *this;
}

Time Time::operator ++ (int x) {
	Time temp = *this;
	++giay;
	if (giay == 60) {
		setGiay(0);
		phut++;
	}
	if (phut == 60) {
		setPhut(0);
		gio++;
	}
	if (gio == 24) {
		setGio(0);
	}
	return temp;
}

Time Time::operator -- () {
	giay--;
	if (giay < 0) {
		setGiay(59);
		phut--;
	}
	if (phut < 0) {
		setPhut(59);
		gio--;
	}
	if (gio < 0) {
		setGio(23);
	}
	return *this;
}

Time Time::operator -- (int x) {
	Time temp = *this;
	--giay;
	if (giay < 0) {
		setGiay(59);
		phut--;
	}
	if (phut < 0) {
		setPhut(59);
		gio--;
	}
	if (gio < 0) {
		setGio(23);
	}
	return temp;
}

