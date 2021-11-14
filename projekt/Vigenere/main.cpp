#include <iostream>
#include <string>
#include <fstream>
using namespace std;
void code(const string In,const string Out,const string Key){
	ifstream czysty;//czysty tekt
	ofstream zaszyfrowany;
	ifstream klucz;
	czysty.open(In.c_str());
	string clr;
	while(czysty){
		czysty>>clr;
	}
	czysty.close();
	klucz.open(Key.c_str());
	string k;
	while(klucz){
		klucz>>k;
	}
	klucz.close();
	//k="a";
	//clr="takoawoa";
	string coded;
	for(int i=0;i<clr.length();i++){
		char tmp;
		if(clr[i]<='z'&&clr[i]>='a'){													//dla alfabetu malego
			if(k[i%k.length()]<='z'&&k[i%k.length()]>='a'){
				tmp=clr[i]+(k[i%k.length()])-'a';
				
			}else if(k[i%k.length()]<='Z'&&k[i%k.length()]>='A'){
				tmp=clr[i]+(k[i%k.length()])-'A';
			}
			if(tmp>'z'||tmp<'a'){													//jezeli znak spoza alfabetu wroc do alfabetu
				tmp-=26;
			}
			coded+=tmp;
		}else if(clr[i]<='Z'&&clr[i]>='A'){											//dla alfabetu duzego
			if(k[i%k.length()]<='z'&&k[i%k.length()]>='a'){
				tmp=clr[i]+(k[i%k.length()])-'a';
			}else if(k[i%k.length()]<='Z'&&k[i%k.length()]>='A'){
				tmp=clr[i]+(k[i%k.length()])-'A';
			}
			if(tmp>'Z'||tmp<'A'){													//jezeli znak spoza alfabetu wroc do alfabetu
				tmp-=26;
			}
			coded+=tmp;
		}	
	}
	//cout<<endl<<coded<<endl;
	zaszyfrowany.open(Out.c_str());
	zaszyfrowany<<coded;
	zaszyfrowany.close();
}
void decode(const string In,const string Out,const string Key){																			//odwrotnie jak code
	ofstream czysty;
	ifstream zaszyfrowany;
	ifstream klucz;
	zaszyfrowany.open(In.c_str());
	string coded;
	while(zaszyfrowany){
		zaszyfrowany>>coded;
	}
	zaszyfrowany.close();
	klucz.open(Key.c_str());
	string k;
	while(klucz){
		klucz>>k;
	}
	klucz.close();
	//coded="rodf";
//	k="hak";
	string clr;
	for(int i=0;i<coded.length();i++){
		char tmp;
		if(coded[i]<'z'&&coded[i]>'a'){													
			if(k[i%k.length()]<='z'&&k[i%k.length()]>='a'){
				tmp=coded[i]-(k[i%k.length()])+'a';
				
			}else if(k[i%k.length()]<='Z'&&k[i%k.length()]>='A'){
				tmp=coded[i]-(k[i%k.length()])+'A';
			}
			if(tmp>'z'||tmp<'a'){													
				tmp+=26;
			}
			clr+=tmp;
		}else if(coded[i]<'Z'&&coded[i]>'A'){											
			if(k[i%k.length()]<='z'&&k[i%k.length()]>='a'){
				tmp=coded[i]-(k[i%k.length()])+'a';
			}else if(k[i%k.length()]<='Z'&&k[i%k.length()]>='A'){
				tmp=coded[i]-(k[i%k.length()])+'A';
			}
			if(tmp>'Z'||tmp<'A'){													
				tmp+=26;
			}
			clr+=tmp;
		}	
	}
	czysty.open(Out.c_str());
	//cout<<endl<<endl<<clr<<endl;
	czysty<<clr;
	czysty.close();
}
void GetKey(const string In,const string Out,const string Key){
	ifstream czysty;//czysty tekt
	ifstream zaszyfrowany;
	ofstream klucz;
	czysty.open(In.c_str());
	string clr;
	while(czysty){
		czysty>>clr;
	}
	czysty.close();
	zaszyfrowany.open(Out.c_str());
	string coded;
	while(zaszyfrowany){
		zaszyfrowany>>coded;
	}
	zaszyfrowany.close();
	klucz.open(Key.c_str());
	//clr="KOTY";
	//coded="RODF";
	string k;
	for(int i=0;i<clr.length();i++){
		char tmp=(coded[i]-clr[i]);
		if(tmp>26||tmp<0){
			tmp+=26;
		}
		k+=('a'+tmp);
	}
	//cout<<endl<<endl<<k<<endl;
	klucz<<k;
	klucz.close();
}
void rem(const int r,const string i,const string o,const string k){
	switch(r){
		case 1:
			code(i,o,k);
			//cout<<"code"<<endl;
		break;
		case 2:
			decode(i,o,k);
			//cout<<"decode"<<endl;
		break;
		case 3:
			GetKey(i,o,k);
			//cout<<"break"<<endl;
		break;
	}
}
int main(int argc,      								//dlugosc ciagu parametrow
    	char *argv[],   								//ciag parametrow
        char *envp[] ) {
        string IN,OUT,KEY;//plik wejscia,plik wyjscia,plik klucz
        int remot;//sterowanie wyborem podprogramu
	for(int i=1;i<argc;i++){
		if(string(argv[i])=="-i"){
			IN=argv[i+1];
		}
		if(string(argv[i])=="-o"){
			OUT=argv[i+1];
		}
		if(string(argv[i])=="-k"){
			KEY=argv[i+1];
		}
		if(string(argv[i])=="--en"){
			remot=1;
		}
		if(string(argv[i])=="--de"){
			remot=2;
		}
		if(string(argv[i])=="--br"){
			remot=3;
		}
	}
	rem(remot,IN,OUT,KEY);
	/*cout<<"in=	"<<IN<<endl<<"out=	"<<OUT<<endl<<"key=	"<<KEY<<endl<<"option=	"<<remot<<endl;
	system("pause");*/
	return 0;
}

