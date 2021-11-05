#include <iostream>
#include <string>
#include <fstream>
using namespace std;
void code(){
	ifstream czysty;//czysty tekt
	ofstream zaszyfrowany;
	ifstream klucz;
	czysty.open("clear.txt");
	string clr;
	while(czysty){
		czysty>>clr;
	}
	czysty.close();
	klucz.open("key.txt");
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
	zaszyfrowany.open("coded.txt");
	zaszyfrowany<<coded;
	zaszyfrowany.close();
}
void decode(){																			//odwrotnie jak code
	ofstream czysty;
	ifstream zaszyfrowany;
	ifstream klucz;
	zaszyfrowany.open("coded.txt");
	string coded;
	while(zaszyfrowany){
		zaszyfrowany>>coded;
	}
	zaszyfrowany.close();
	klucz.open("key.txt");
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
	czysty.open("clear.txt");
	//cout<<endl<<endl<<clr<<endl;
	czysty<<clr;
	czysty.close();
}
void GetKey(){
	ifstream czysty;//czysty tekt
	ifstream zaszyfrowany;
	ofstream klucz;
	czysty.open("clear.txt");
	string clr;
	while(czysty){
		czysty>>clr;
	}
	czysty.close();
	zaszyfrowany.open("coded");
	string coded;
	while(zaszyfrowany){
		zaszyfrowany>>coded;
	}
	zaszyfrowany.close();
	klucz.open("key.txt");
	clr="KOTY";
	coded="RODF";
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
int main(int argc,      // Number of strings in array argv
          char *argv[],   // Array of command-line argument strings
          char *envp[] ) {
	string q=argv[1];
	if(q=="--en"){
		code();
	}else if(q=="--de"){
		decode();
	}else if(q=="--br"){
		GetKey();
	}
	cout<<endl<<"WORKS"<<endl<<argv[1]<<endl<<q<<endl;
	system("pause");
	return 0;
}

