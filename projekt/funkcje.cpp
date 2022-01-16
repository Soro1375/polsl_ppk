///\file funkcje.cpp
#include "funkcje.h"
///plik zawiera kody funkcji zewnetrznych
//\fn wczytaj_plik
using namespace std;
string wczytaj_plik(const string In){
	///funkcja sprawdza dostep do pliku o podanej nazwie, nastepnie jesli to mozliwe przypisuje jego zawartosc do zmiennej typu string	
	ifstream zrodlo(In.c_str());
	string przeczytany;///@param przeczytany zmienna przyjmujaca zawartosc pliku
	if(zrodlo.fail()){
		cout<<"Brak dostepu do pliku wejsciowego "<<"\""<<In<<"\" lub plik nie istnieje."<<endl;
	}else{
		while(zrodlo){
			zrodlo>>przeczytany;
		}	
	}
	zrodlo.close();
	return przeczytany;
}
///\fn code
void code(const string In,const string Out,const string Key,const short de){
	///funkcja szyfruje algorytmem vigenere string wejsciowy za pomoca stringa klucza, wynik zwraca do pliku;
	fstream zaszyfrowany;///< uzywanie metody fstream gwarantuje utworzenie pliku o podanej nazwie jesli ten wczesniej nie istnieje w folderze programu
	string coded;
	for(int i=0;i<In.length();i++){
		char tmp;
		if((In[i]<='z'&&In[i]>='a')||(In[i]<='Z'&&In[i]>='A')){													//dla alfabetu malego
			if(Key[i%Key.length()]<='z'&&Key[i%Key.length()]>='a'){
				tmp=In[i]+(Key[i%Key.length()]*de)-('a'*de);
				
			}else if(Key[i%Key.length()]<='Z'&&Key[i%Key.length()]>='A'){
				tmp=In[i]+(Key[i%Key.length()]*de)-('A'*de);
			}
			if(!(tmp<='z'&&tmp>='a')&&!(tmp<='Z'&&tmp>='A')){													//jezeli znak spoza alfabetu wroc do alfabetu
				tmp-=26*de;
			}
			coded+=tmp;
		}
		/// dzieki rozbudowanemu warunkowi IF jest wstanie interpretowac duze i male litery zarowno w zmiennej wejsciowej, jak i w zmiennej klucza
	}
	//cout<<endl<<coded<<endl;
	zaszyfrowany.open(Out.c_str(),ios::out);
	zaszyfrowany<<coded;
	zaszyfrowany.close();
	///Szyfr Vigenere nalezy do grupy szyfrow symetrycznych, wiec kodowanie i dekodowanie moze odbywac sie w tej samej funkcji wykorzystujac flage dodatniego lub ujemnego przesuniecia
}

///\fn GetKey

void GetKey(const string clr,const string coded,const string Key){
	///funkcja lamie szyfr na podstawie tekstu zaszyfrowanego i tekstu jawnego, algorytm bada przesuniecie znakow wzgledem poczatku alfabetu, wynik zapisywany jest do pliku
	fstream klucz;
	klucz.open(Key.c_str(),ios::out);
	//clr="KOTY";
	//coded="RODF";
	string k;
	for(int i=0;i<clr.length();i++){
		char tmp;
		if(coded[i]<'a'||coded[i]>'z'){
			if(clr[i]<'a'||clr[i]>'z'){
				tmp=(coded[i]-clr[i]);
				//cout<<int(tmp)<<"	";
			}else{
				tmp=(coded[i]-clr[i])+('a'-'A');//a>A
			}	
		}else{
			if(clr[i]<'a'||clr[i]>'z'){
				tmp=(coded[i]-clr[i])-('a'-'A');
			}else{
				tmp=(coded[i]-clr[i]);
				//cout<<int(tmp)<<"	";
			}
		}
		///drzewo zagniezdzonych IF'ow pozwala ignorowac wielkosc znakow obu danych wejsciowych
		if(tmp<0){
			tmp+=26;
		} 
		k+=('a'+tmp);
		//cout<<int(tmp)<<endl;
	}
	//cout<<endl<<endl<<k<<endl;
	klucz<<k;
	klucz.close();
}
///\fn rem
void rem(const int r,const string i,const string o,const string k){
	///funkcja remote-pilot
	///funkcja interpretuje podane przez uzytkownika parametry i uruchamia odpowiedni podprogram
	switch(r){
		case 1:
			code(wczytaj_plik(i),o,wczytaj_plik(k),1);
			//cout<<"code"<<endl;
		break;
		case 2:
			code(wczytaj_plik(i),o,wczytaj_plik(k),-1);
			//cout<<"decode"<<endl;
		break;
		case 3:
			GetKey(wczytaj_plik(i),wczytaj_plik(o),k);
			//cout<<"break"<<endl;
		break;
	}
}
