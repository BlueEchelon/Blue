#include <iostream>
#include <cstdlib>
#include <conio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
class Zawodnik{
	private:
		string nazwisko;
		int w1,w2,w3;
	public:
		Zawodnik(string naz,int wys1,int wys2,int wys3) : nazwisko(naz),w1(wys1),w2(wys2),w3(wys3){}
		Zawodnik(int r){
			nazwisko="aha";
			w1=r;
			w2=10;
			w3=10;
		}
		friend void wyswietl(class Zawodnik a);
		friend void ktory_lepszy(class Zawodnik a,class Zawodnik b);
		friend void ktory_lepszy(class Zawodnik a,int z,int x,int c);
		friend Zawodnik operator +(class Zawodnik a,class Zawodnik b);
		
};
//przeciążenie operatora plus;
Zawodnik operator +(class Zawodnik a,class Zawodnik b){
	Zawodnik twor("monstrum",a.w1+b.w1,a.w2+b.w2,a.w3+b.w3);
	wyswietl(twor);
}
void wyswietl(class Zawodnik a){
	cout << "Nazwisko: " << a.nazwisko<< endl;
	cout << "Miejsce po pierwszym wyscigu: " << a.w1 << endl;
	cout << "Miejsce po drugim wyscigu: " << a.w2 << endl;
	cout << "Miejsce po trzecim wyscigu: " << a.w3 << endl << endl;
}
// funkcje dla innych zmiennych odpowiadających klassom
void ktory_lepszy(class Zawodnik a,class Zawodnik b){
	int suma1=0;
	int suma2=0;
	suma1=a.w1+a.w2+a.w3;
	suma2=b.w1+b.w2+b.w3;
	if(suma1<suma2){
		cout<<"Zawodnik " <<a.nazwisko<< " byl lepszy od Zawodnika "<<b.nazwisko << " o " <<suma2-suma1<<" punkty"<<endl;
	}
	else if(suma1>suma2){
		cout<<"Zawodnik " <<b.nazwisko<< " byl lepszy od Zawodnika "<<a.nazwisko << " o " <<suma1-suma2<<" punkty"<<endl;
	}
}
void ktory_lepszy(class Zawodnik a,int z,int x,int c){
	int suma1=0;
	int suma2=0;
	suma1=a.w1+a.w2+a.w3;
	suma2=z+x+c;
	if(suma1<suma2){
		cout<<"Zawodnik " <<a.nazwisko<< " byl lepszy od Zawodnika "<<"Nieznajomy" << " o " <<suma2-suma1<<" punkty"<<endl;
	}
	else if(suma1>suma2){
		cout<<"Zawodnik " <<"Nieznajomy"<< " byl lepszy od Zawodnika "<<a.nazwisko << " o " <<suma1-suma2<<" punkty"<<endl;
	}
}
int main(int argc, char** argv) {
	Zawodnik jeden("pierwszy",3,3,3);
	Zawodnik drugi("dwa",2,2,2);
	Zawodnik trzeci("trzy",1,1,1);
	// testy różnych zmiennych
	ktory_lepszy(drugi,jeden);
	ktory_lepszy(drugi,trzeci);
	ktory_lepszy(trzeci,3);
	ktory_lepszy(drugi,1,2,2);
	//test operatora
	jeden+drugi;
	trzeci+jeden;
	return 0;
}
