#include"Time.h"
using namespace std;

int main() {
	Time t1;
	Time t2;

	cout << "\n Nhap thoi gian thu nhat";
	cin >> t1;
	cout << "\n Nhap thoi gian thu hai";
	cin >> t2;

	cout << "\n\n\t\t HAI THOI GIAN DA NHAP\n";
	cout << "\n Thoi gian thu nhat: " << t1;
	cout << "\n Thoi gian thu hai: " << t2;

	cout << "\n\t\t TONG HAI THOI GIAN\n " << t1 + t2;
	cout << "\n\n\t\t HIEU HAI THOI GIAN\n " << t1 - t2;

	cout << "\n\n\t\t SO SANH HAI THOI GIAN\n";
	if (t1 > t2) {
		cout << "\n Thoi gian thu nhat lon hon.";
	}
	else if (t1 < t2) {
		cout << "\n Thoi gian thu hai lon hon.";
	}
	else {
		cout << "\n Hai thoi gian bang nhau.";
	}

	cout << "\n\n\t\t ++t1\n " << ++t1;
	cout << "\n\n\t\t --t2\n " << --t2;

	cout << endl;
	system("pause");
	return 0;
}