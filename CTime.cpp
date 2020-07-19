#include "CTime.h"

ostream& operator << (ostream& os, const CTime& t) {
	if (t.hour < 13) {
		os << setw(2) << setfill('0') << t.hour << ":";
		os << setw(2) << setfill('0') << t.minute << ":";
		os << setw(2) << setfill('0') << t.second;
	}
	else {
		os << setw(2) << setfill('0') << t.hour << ":";
		os << setw(2) << setfill('0') << t.minute << ":";
		os << setw(2) << setfill('0') << t.second;
	}
	return os;
}

istream& operator >> (istream& is, CTime& t) {
	do {
		cout << "\n Nhap gio: ";
		is >> t.hour;
		cout << "\n Nhap phut: ";
		is >> t.minute;
		cout << "\n Nhap giay: ";
		is >> t.second;
		if (t.hour < 0 || t.hour > 23
			|| t.minute < 0 || t.minute > 59
			|| t.second < 0 || t.second > 59) {
			cout << "\n Thoi gian khong hop le!";
			cout << "\n Vui long kiem tra lai.\n";
		}
	} while (t.hour < 0 || t.hour > 23
		|| t.minute < 0 || t.minute > 59
		|| t.second < 0 || t.second > 59);
	return is;
}

CTime CTime::operator + (CTime t) {
	CTime res;
	int sub; // giây của res sau khi xử lý (TH >= 60)
	int tmp; // giá trị sẽ cộng qua cho đại lượng tiếp theo
	res.setTime(this->hour + t.hour, this->minute + t.minute, this->second + t.second);

	if (res.second >= 60) {
		sub = res.second - 60;
		tmp = res.second / 60;
		if (sub == 60) {
			res.setSecond(0);
		}
		else {
			res.setSecond(sub);
		}
		res.minute += tmp;
	}
	if (res.minute >= 60) {
		sub = res.minute - 60;
		tmp = res.minute / 60;
		if (sub == 60) {
			res.setMinute(0);
		}
		else {
			res.setMinute(sub);
		}
		res.hour += tmp;
	}
	return res;
}

CTime CTime::operator + (int val) {
	int mod;
	int div;

	this->second += val;

	if (this->second >= 60) {
		mod = this->second % 60;
		div = this->second / 60;
		setSecond(mod);
		this->minute += div;
	}
	if (this->minute >= 60) {
		mod = this->minute % 60;
		div = this->minute / 60;
		setMinute(mod);
		this->hour += div;
	}
	return *this;
}

CTime CTime::operator - (CTime t) {
	CTime res;
	int sub; // giây của res sau khi xử lý (TH >= 60)
	int tmp; // giá trị sẽ cộng qua cho đại lượng tiếp theo

	if (*this == t) {
		res.setTime(0, 0, 0);
	}
	else {
		res.setTime(this->hour - t.hour, this->minute - t.minute, this->second - t.second);
		if (res.second < 0) {
			res.setSecond(60 - abs(res.second));
			res.minute--;
		}
		if (res.minute < 0) {
			res.setMinute(60 - abs(res.minute));
			res.hour--;
		}
		if (res.hour < 0) {
			res.setHour(24 - abs(res.hour));
		}
	}
	return res;
}

CTime CTime::operator - (int val) {
	int mod;
	int div;
	if (val < this->second) {
		this->second -= val;
		return *this;
	}
	this->second += val;

	if (this->second >= 60) {
		mod = this->second % 60;
		div = this->second / 60;
		setSecond(mod);
		this->minute -= div;
	}
	if (this->minute >= 60) {
		mod = this->minute % 60;
		div = this->minute / 60;
		setMinute(mod);
		this->hour -= div;
	}
	return *this;
}

CTime CTime::operator ++ () {
	this->second++;
	if (this->second == 60) {
		setSecond(0);
		this->minute++;
	}
	if (this->minute == 60) {
		setMinute(0);
		this->hour++;
	}
	if (this->hour == 24) {
		setHour(0);
	}
	return *this;
}

CTime CTime::operator ++ (int val) {
	CTime tmp = *this;
	this->second++;
	if (this->second == 60) {
		setSecond(0);
		this->minute++;
	}
	if (this->minute == 60) {
		setMinute(0);
		this->hour++;
	}
	if (this->hour == 24) {
		setHour(0);
	}
	return tmp;
}

CTime CTime::operator -- () {
	this->second--;
	if (this->second < 0) {
		setSecond(59);
		this->minute--;
	}
	if (this->minute < 0) {
		setMinute(59);
		this->hour--;
	}
	if (this->hour < 0) {
		setHour(23);
	}
	return *this;
}

CTime CTime::operator -- (int val) {
	CTime tmp = *this;
	this->second--;
	if (this->second < 0) {
		setSecond(59);
		this->minute--;
	}
	if (this->minute < 0) {
		setMinute(59);
		this->hour--;
	}
	if (this->hour < 0) {
		setHour(23);
	}
	return tmp;
}

bool CTime::operator < (CTime t) {
	return (totalSecond() < t.totalSecond());
}

bool CTime::operator <= (CTime t) {
	return (totalSecond() <= t.totalSecond());
}

bool CTime::operator > (CTime t) {
	return (totalSecond() > t.totalSecond());
}

bool CTime::operator >= (CTime t) {
	return (totalSecond() >= t.totalSecond());
}

bool CTime::operator == (CTime t) {
	return (totalSecond() == t.totalSecond());
}

bool CTime::operator != (CTime t) {
	return (totalSecond() != t.totalSecond());
}

void Menu(CTime t1, CTime t2) {
	while (true) {
		system("cls");
		cout << "\n\n\t\t ========================= OOP-CTIME =========================\n";
		cout << "\n\t 1. Nhap thoi gian.";
		cout << "\n\t 2. Xuat thoi gian.";
		cout << "\n\t 3. Tong hai thoi gian.";
		cout << "\n\t 4. Hieu hai thoi gian.";
		cout << "\n\t 5. So sanh hai thoi gian.";
		cout << "\n\t 6. Cong thoi gian cho gia tri giay bat ky.";
		cout << "\n\t 7. Tru thoi gian cho gia tri giay bat ky.";
		cout << "\n\t 8. Tang mot giay.";
		cout << "\n\t 9. Giam mot giay.";
		cout << "\n\t 0. Thoat chuong trinh.";

		int query;
		do {
			cout << "\n\n\t Nhap lua chon cua ban: ";
			cin >> query;
			if (query < 0 || query > 9) {
				cout << "\n Lua chon khong hop le!.";
			}
		} while (query < 0 || query > 9);

		switch (query) {
		case 1:
			system("cls");
			cout << "\n\n\t\t =========== NHAP THOI GIAN ===========\n";
			cout << "\n Nhap thoi gian thu nhat: ";
			cin >> t1;
			cout << "\n Nhap thoi gian thu hai: ";
			cin >> t2;
			system("pause");
			break;
		case 2:
			system("cls");
			cout << "\n\n\t\t =========== THOI GIAN DA NHAP ===========\n";
			cout << "\n Thoi gian thu nhat: " << t1;
			cout << "\n Thoi gian thu hai: " << t2 << endl;
			system("pause");
			break;
		case 3:
			cout << "\n\n\t\t =========== TONG HAI THOI GIAN ===========\n";
			cout << "\n\t " << t1 + t2 << endl;
			system("pause");
			break;
		case 4:
			cout << "\n\n\t\t =========== HIEU HAI THOI GIAN ===========\n";
			cout << "\n\t " << t1 - t2 << endl;
			system("pause");
			break;
		case 5:
			cout << "\n\n\t\t =========== SO SANH HAI THOI GIAN ===========\n";
			if (t1 > t2) {
				cout << "\n\t Thoi gian thu nhat (" << t1 << ") " << " lon hon!\n";
			}
			else if (t1 < t2) {
				cout << "\n\t Thoi gian thu hai (" << t2 << ") " << " lon hon!\n";
			}
			else {
				cout << "\n\t Hai thoi gian bang nhau!\n";
			}
			system("pause");
			break;
		case 6:
		{
			int val;
			cout << "\n Nhap gia tri giay muon cong: ";
			cin >> val;
			CTime tmp1 = t1;
			CTime tmp2 = t2;
			cout << "\n\t Thoi gian thu nhat sau khi cong: " << tmp1 + val;
			cout << "\n\t Thoi gian thu hai sau khi cong: " << tmp2 + val << endl;
			system("pause");
		}
		break;
		case 7:
		{
			int val;
			cout << "\n Nhap gia tri giay muon tru: ";
			cin >> val;
			CTime tmp1 = t1;
			CTime tmp2 = t2;
			cout << "\n\t Thoi gian thu nhat sau khi tru: " << tmp1 - val;
			cout << "\n\t Thoi gian thu hai sau khi tru: " << tmp2 - val << endl;
			system("pause");
		}
		break;
		case 8:
		{
			CTime tmp1 = t1;
			CTime tmp2 = t2;
			cout << "\n\t Thoi gian thu nhat sau khi tang 1 giay: " << ++tmp1;
			cout << "\n\t Thoi gian thu hai sau khi tang 1 giay: " << ++tmp2++ << endl;
			system("pause");
		}
		break;
		case 9:
		{
			CTime tmp1 = t1;
			CTime tmp2 = t2;
			cout << "\n\t Thoi gian thu nhat sau khi giam 1 giay: " << --tmp1;
			cout << "\n\t Thoi gian thu hai sau khi giam 1 giay: " << --tmp2 << endl;
			system("pause");
		}
		break;
		case 0:
			cout << "\n\n\t\t =========== THE END ===========\n";
			return;
		}
	}
}


