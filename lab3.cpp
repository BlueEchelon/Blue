#include <iostream>
#include <cstdlib>
#include <conio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
class Zawodnik{
	private:
		string nazwisko;
		string imie;
		string klub;
		int w1,w2,w3;
		string pesel;
		string data_uro;
		int punkty;
	public:
		void pobierz(class Zawodnik* tab, int ilosc);
		void wyniki(class Zawodnik* tab,int ilosc);
		void wyswietl(class Zawodnik* tab, int ilosc);
		void zwyciesca(class Zawodnik* tab,int ilosc);	
		Zawodnik(){
			this->nazwisko;
			this->imie;
			this->klub;
			this->w1;
			this->w2;
			this->w3;
			this->pesel;
			this->data_uro;
			this->punkty;
		}
		Zawodnik(string n,string i,string k,int w4,int w5,int w6,string p,string d,int pu){
			this->nazwisko=n;
			this->imie=i;
			this->klub=k;
			this->w1=w4;
			this->w2=w5;
			this->w3=w6;
			this->pesel=p;
			this->data_uro=d;
			this->punkty=pu;
		}
		Zawodnik(string k,int w4,int w5,int w6,string p,string d,int pu){
			this->klub=k;
			this->w1=w4;
			this->w2=w5;
			this->w3=w6;
			this->pesel=p;
			this->data_uro=d;
			this->punkty=pu;
		}
		~Zawodnik(){
			cout<<"Destruction!!!"<<endl;
		}
};
void Zawodnik::wyswietl(class Zawodnik* tab, int ilosc){
	for (int i = 0; i < ilosc; i++){
		cout << "Nazwisko, imie: " << tab[i].nazwisko << " " << tab[i].imie << endl;
		cout << "Klub: "<< tab[i].klub << endl;
		cout << "Pesel: " << tab[i].pesel << endl;
		cout << "Miejsce po pierwszym wyscigu: " << tab[i].w1 << endl;
		cout << "Miejsce po drugim wyscigu: " << tab[i].w2 << endl;
		cout << "Miejsce po trzecim wyscigu: " << tab[i].w3 << endl << endl;
	}
}
void Zawodnik::wyniki(class Zawodnik* tab,int ilosc){
	for(int a=0;a<ilosc;a++){
		tab[a].punkty=0;
		int tablica[3];
		tablica[0]=tab[a].w1;
		tablica[1]=tab[a].w2;
		tablica[2]=tab[a].w3;
		for(int i=0;i<3;i++){
			if(tablica[i]==1){
				tab[a].punkty+=10;
			}
			else if(tablica[i]==2){
				tab[a].punkty+=8;
			}
			else if(tablica[i]==3){
				tab[a].punkty+=6;
			}
			else{
				tab[a].punkty+=4;
			}
		}
		cout << "Nazwisko: "<<tab[a].nazwisko<<" -- Liczba uzyskanych punktuw: "<<tab[a].punkty<<endl;
	}
}
void Zawodnik::zwyciesca(class Zawodnik* tab,int ilosc){
	int tablica[ilosc][2];
	for(int i=0;i<ilosc;i++){
		tablica[i][0]=tab[i].punkty;
		tablica[i][1]=i;
	}
	for(int a=0;a<ilosc;a++){
		for(int i=0;i<ilosc-1;i++){
			if(tablica[i][0]<tablica[i+1][0]){
				swap(tablica[i][0],tablica[i+1][0]);
				swap(tablica[i][1],tablica[i+1][1]);
			}
		}
	}
	for(int i=0;i<ilosc;i++){
		cout <<i+1<<". "<<tab[tablica[i][1]].imie <<" "<<tab[tablica[i][1]].nazwisko<<" -- Uzyskal "<<tab[tablica[i][1]].punkty<<" punktow"<<endl;
	}
}
void Zawodnik::pobierz(class Zawodnik* tab, int ilosc){
	for (int i = 0; i < ilosc; i++){
		cout << "Podaj imie: ";
		cin >> tab[i].imie;
		cout << "Podaj nazwisko: ";
		cin >> tab[i].nazwisko;
		cout << "Podaj pesel: ";
		cin >> tab[i].pesel;
		cout << "Podaj rok urodzenia: ";
		cin >> tab[i].data_uro;
		cout << "Podaj nazwe klubu zawodnika: ";
		cin >> tab[i].klub;
		cout << "Miejsce po pierwszym wyscigu: ";
		cin >> tab[i].w1;
		cout << "Miejsce po drugim wyscigu: ";
		cin >> tab[i].w2;
		cout << "Miejsce po trzecim wyscigu: ";
		cin >> tab[i].w3;
		system("cls");
	}
}
int main(int argc, char** argv) {
	Zawodnik test();
	Zawodnik test1("aaa","bbb","ccc",4,4,4,"pesel","urodziny",12);
	Zawodnik test2("akacz",1,3,3,"lesep","dziny",22);
	int n;
	cout << "Podaj liczbe zawodnikow: ";
	cin>>n;
	Zawodnik *dane=new Zawodnik[n];
	system("cls");
	dane->pobierz(dane,n);
	int x;
	while(x!=0){
		system("cls");
		cout<<"Menu"<<endl;
		cout<<"1. Wyniki poszczegolnych zawodnikow"<<endl;
		cout<<"2. Informacje o zawodnikach"<<endl;
		cout<<"3. Tabela"<<endl;
		cout<<"0. Zamkniecie aplikacji\n\n";
		cout<<"Wpisz liczbe: ";
		cin>>x;
		switch(x){
		case 1:
			system("cls");
			dane->wyniki(dane,n);
			getche();
			break;
		case 2:
			system("cls");
			dane->wyswietl(dane,n);
			getche();
			break;
		case 3:
			system("cls");
			cout<<"Kto wygral?\n"<<endl;
			getche();
			dane->zwyciesca(dane,n);
			getche();
			break;
		case 0:
			system("cls");
			cout<<"Dziekujemy za skorzystanie z naszej aplikacji, zyczymy milego dnia";
			delete dane;
			break;
		default:
			system("cls");
			cout<<"Wybrano zly numer, sprubuj ponownie";
			getche();
			break;	
		}
	}
	return 0;
}
