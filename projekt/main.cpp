///\file main.cpp
#include <iostream>
#include <string>
#include "funkcje.h"
using namespace std;
///\namespace std
///\fn main
/// main sprawdza poprawnosc wprowadzonych parametrow
int main(int argc,      								///@param argc dlugosc ciagu parametrow
    	char *argv[]   								///@param argv ciag parametrow
        ) {
        string IN,OUT,KEY;///@param IN nazwa pliku wejscia
		///@param OUT nazwa pliku wyjscia,
		///@param KEY nazwa pliku klucz
        short remot;///@param remot sterowanie wyborem podprogramu
	if(argc==8){
		for(int i=1;i<argc;i++){
			if(string(argv[i])=="-i"){
				if(argv[i+1]!=("")&&
				argv[i+1]!="-o"&&
				argv[i+1]!="-k"&&
				argv[i+1]!="--en"&&
				argv[i+1]!="--de"&&
				argv[i+1]!="--br"){
					IN=argv[i+1];
					i++;
				}else{
					cout<<"Brak parametru -i"<<endl;
				}
			}else if(string(argv[i])=="-o"){
				if(argv[i+1]!=""&&
				argv[i+1]!="-i"&&
				argv[i+1]!="-k"&&
				argv[i+1]!="--en"&&
				argv[i+1]!="--de"&&
				argv[i+1]!="--br"){
					OUT=argv[i+1];
					i++;
				}else{
					cout<<"Brak parametru -o"<<endl;
				}
			}else if(string(argv[i])=="-k"){
				if(argv[i+1]!=""&&
				argv[i+1]!="-o"&&
				argv[i+1]!="-i"&&
				argv[i+1]!="--en"&&
				argv[i+1]!="--de"&&
				argv[i+1]!="--br"){
					KEY=argv[i+1];
					i++;
				}else{
					cout<<"Brak parametru -k"<<endl;
				}
			}else if(string(argv[i])=="--en"){
				remot=1;
			}else if(string(argv[i])=="--de"){
				remot=2;
			}else if(string(argv[i])=="--br"){
				remot=3;
			}else{
				cout<<"Nieprawidlowy parametr "<<i<<"."<<endl;
				system("pause");
				return 0;
			}
		}
	}else{
		cout<<"Podano bledna ilosc parametrow"<<endl;
	}
	rem(remot,IN,OUT,KEY);
	/*cout<<"in=	"<<IN<<endl<<"out=	"<<OUT<<endl<<"key=	"<<KEY<<endl<<"option=	"<<remot<<endl;*/
	system("pause");
	return 0;
}

