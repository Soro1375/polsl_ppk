#include <iostream>
#include <math.h>
using namespace std;
int nwd(int a,int b){
	if(a<=0||b<=0){
		cout<<"No chyba nie"<<endl;
	}else if(a>b){
		while((a%b)!=0){
			b--;
		}
		return b;
	}else if(a<b){
		while((b%a)!=0){
			a--;
		}
		return a;
	}else if(a==b){
		return a;
	}
	return 0;
}
void zad1(){
	int x,y,z;
	cout<<"Podaj x"<<endl;
	cin>>x;
	cout<<endl<<"Podaj y"<<endl;
	cin>>y;
	cout<<endl<<"Podaj z"<<endl;
	cin>>z;
	int tmp=nwd(x,y);
	cout<<"NWD tych trzech liczb wynosi: "<<nwd(tmp,z)<<endl;
}
float f(float a, float b, float x){
	//return ;
}
void zad2(){
	cout<<"Podaj a "<<endl;
	float a;
	cin>>a;
	cout<<"Podaj b "<<endl;
	float b;
	cin>>b;
	cout<<"Podaj poczatek calkowania "<<endl;
	float start;
	cin>>start;
	cout<<"Podaj koniec calkowania "<<endl;
	float koniec;
	cin>>koniec;
	cout<<"Podaj liczbe przedzialow na ktore ma zostac podzielona f() podcalkowa "<<endl;
	int ile;
	cin>>ile;
	float wynik=0;
	float delta=koniec-start;
	for(int i=0;i<ile;i++){
		wynik+=i;
	}
	
	cout<<wynik<<endl; 
	//-a·cos(koniec)+b·koniec+a·cos(start)-b·start
}
unsigned int zad3(){
	cout<<"Podaj R"<<endl;
	short r;
	cin>>r;
	cout<<"Podaj G"<<endl;
	short g;
	cin>>g;
	cout<<"Podaj B"<<endl;
	short b;
	cin>>b;
	return b+(g*256)+(r*256*256);
}
int main() {
	//zad1();
//	zad2();
 	int g=zad3();
	cout.fill('0');
//	const char t='0';
	//cout.width(8);
	cout<<setw(8)<<hex<<g<<endl;
	
	return 0;
}
