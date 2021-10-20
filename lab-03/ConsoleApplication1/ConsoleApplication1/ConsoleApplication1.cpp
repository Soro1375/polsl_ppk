#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;
void z1()
{
	double r=1;
	double sum = 0;
	double avg = 0;
	double min = DBL_MAX;
	double max = DBL_MIN;
	while (r) {
		cin >> r;
		sum += r;
		avg++;
		if (r > max && r!=0) {
			max = r;
		}
		if (r < min && r != 0) {
			min = r;
		}
	}
	cout << "Suma=" << sum << endl << "Srednia=" << sum/--avg << endl << "Min=" << min << endl << "Max=" << max << endl;
}
void z2() {
	char q = 13;
	int licznik = 0;
	while (q != 'q' && q != 'Q') {
		q = _getche();
		if (q == 'a' || q == 'e' || q == 'i' || q == 'u' || q == 'y' || q == 'o'|| q == 'A' || q == 'E' || q == 'I' || q == 'U' || q == 'Y' || q == 'O') {
			licznik++;
		}
	}
	cout << endl<< "Bylo " << licznik << " samoglosek";
}
void z3() {
	char q = 13;
	int a = 0, e = 0, i = 0, u = 0, y = 0, o = 0;
	while (q != 'q' && q != 'Q') {
		q = _getche();
		if (q == 'a' || q == 'A') {
			a++;
		}
		if (q == 'i' || q == 'I') {
			i++;
		}
		if (q == 'u' || q == 'U') {
			q++;
		}
		if (q == 'y' || q == 'Y') {
			y++;
		}
		if (q == 'o' || q == 'O') {
			o++;
		}
		if (q == 'e' || q == 'E') {
			e++;
		}
	}
	cout << endl << "Bylo " << endl << a<<" a"<<endl << e << " e"<< endl << i << " i" << endl << u << " u" << endl << y << " y" << endl << o << " o" ;
}
void z4() {
	cout << "Podaj x" << endl;
	double x=2;
	while (x > 1 || x < -1) {
		cin >> x;
	}
	double sum = 1.0;
	double tmp = 0;
	for (double int i=0; sum > 1e-10;i++) {
		sum* (-1 * -x) / (3 * i));
		cout << "Warosc " << i << "-ego wyrazu =" sum-tmp;

	}
}
int main() {
	//z1();
	//z2();
	//z3();
	z4();
}