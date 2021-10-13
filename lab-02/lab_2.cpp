#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
void exc1()
{
	double licznik, mianownik;
	cout << "Podaj licznik: " << endl;
	cin >> licznik;
	cout << "Podaj mianownik: " << endl;
	cin >> mianownik;
	cout << licznik << "/" << mianownik << "="<<licznik / mianownik << endl;
}
void exc2()
{
	double a, b;
	cout << "Podaj parametr a: " << endl;
	cin >> a;
	cout << "Podaj parametr b: " << endl;
	cin >> b;
	cout << "suma a+b=" << a + b << endl << "roznica a-b=" << a - b << endl << "iloczyn a*b=" << a * b << endl << "iloraz a/b=" << a / b << endl << "reszta z dzielenia a%b=" << int(a) % int(b) << endl;
}
void exc3()
{
	float r;
	cout << "Podaj promien kola" << endl;
	cin >> r;
	cout << "+-----------------+---------------+" << endl <<
		"|    Pole pow.    |   Obwod       |" << endl <<
		"+-----------------+---------------+" << endl <<
		"|    " << M_PI * r * r << "      |      "<<2*M_PI*r<<"  |" << endl<<
	"+-----------------+---------------+";

}
void exc4()
{
	float a, b, c;
	cout << "Podaj dlugosci bokow trojkata" << endl;
	cin >> a;
	cin >> b;
	cin >> c;
	if (((a + b) > c && (a + c) > b && (b + c) > a) && a > 0 && b > 0 && c > 0) {
		cout << "Pole trojkata = " << sqrt(((a + b + c) / 2) * (((a + b + c) / 2) - a) * (((a + b + c) / 2) - b) * (((a + b + c) / 2) - c)) << endl;
	}
	else {
		cout << "bledne dane" << endl;
	}
}
void exc5()
{
	float a, b, c, first;// , second, third;
	cout << "Podaj 3 parametry" << endl;
	cin >> a;
	cin >> b;
	cin >> c;
	first = (a > b) ? ((a > c) ? a : b) :((b>c)?b: c);

	cout << first /*<< "	" << second << "	" << third*/ << endl;
}
int main()
{
	//exc1();
	//exc2();
	//exc3();
	//exc4();
	exc5();
	return 0;
}