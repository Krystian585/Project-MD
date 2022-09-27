#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
class Sklep
{
protected:
	string tytul;
	int cena;
	bool sprzedany;
public:
	Sklep() : tytul(""), cena(0), sprzedany(false) {}
	Sklep(string t, int c) :tytul(t), cena(c), sprzedany(false) {}
	virtual void wyswietl_tytul() = 0;
	virtual void wyswietl_cene() = 0;
	virtual void wyswietl_dane() = 0;
	void ustaw_tytul(string t) {
		this->tytul = t;
	}
	void ustaw_cene(int c) {
		this->cena = c;
	}
	bool czy_sprzedany() {
		return sprzedany;
	}
	void sprzedaj()
	{
		if (sprzedany == false)
		{
			sprzedany = true;
		}
		else {
			cout << "\nBrak na stanie";
			return;
		}
	}
	~Sklep() {}
};

class Kaseta : public Sklep
{
	static int liczba_kaset;
private:
	string autor;
	string wydawnictwo;
	unsigned int czas_trwania;
public:
	Kaseta() : autor(""), wydawnictwo(""), czas_trwania(NULL) {}
	Kaseta(string t, int c, string a, string w, int ct) : autor(a), wydawnictwo(w), czas_trwania(ct) { tytul = t, cena = c; /*liczba_kaset++;*/ }
	
	string daj_tytul() {
		return tytul;
	}
	string daj_autor() {
		return autor;
	}
	string daj_wydawnictwo() {
		return wydawnictwo;
	}
	int daj_cene() {
		return cena;
	}

	void wyswietl_tytul() {
		cout << "Tytul: " << tytul;
	}
	void wyswietl_cene() {
		cout << " Cena: " << cena;
	}
	void wyswietl_dane() {
		wyswietl_tytul(); wyswietl_cene();  cout << ", Autor: " << autor << ", Wydawnictwo: " << wydawnictwo << ", Czas Trwania: " << czas_trwania << endl;
	}

	~Kaseta() {}
};
class Plyta : public Sklep
{
private:
	string autor;
	string gatunek;
public:
	Plyta() : autor(""), gatunek("") {}
	Plyta(string t, int c, string a, string g) : autor(a), gatunek(g) { tytul = t, cena = c; }

	string daj_tytul() {
		return tytul;
	}
	string daj_autor() {
		return autor;
	}
	string daj_gatunek() {
		return gatunek;
	}
	int daj_cene() {
		return cena;
	}
	void wyswietl_tytul() {
		cout << "Tytul plyty: " << tytul;
	}
	void wyswietl_cene() {
		cout << " Cena: " << cena;
	}
	void wyswietl_dane() {
		wyswietl_tytul(); wyswietl_cene();  cout << ", Autor: " << autor << ", Gatunek: " << gatunek << endl;
	}
	~Plyta() {}
};
class Film : public Sklep
{
private:
	string rezyser;
	string lektor;
	unsigned int czas_trwania;
public:
	Film() : rezyser(""), lektor(""), czas_trwania(NULL) {}
	Film(string t, int c, string r, string l, int ct) : rezyser(r), lektor(l), czas_trwania(ct) { tytul = t, cena = c; }

	string daj_tytul() {
		return tytul;
	}
	string daj_rezyser() {
		return rezyser;
	}
	string daj_lektor() {
		return lektor;
	}
	int daj_cene() {
		return cena;
	}
	void wyswietl_tytul() {
		cout << "Tytul filmu: " << tytul;
	}
	void wyswietl_cene() {
		cout << " Cena: " << cena;
	}
	void wyswietl_dane() {
		wyswietl_tytul(); wyswietl_cene();  cout << ", Rezyser: " << rezyser << ", Lektor " << lektor << ", Czas Trwania: " << czas_trwania << endl;
	}
	~Film() {}
};
class Wysylka
{
private:
	string imie;
	string nazwisko;
	string miasto;
	string ulica;
	string numer_mieszkania;

	vector<Kaseta>* sprzedane_kasety = new vector<Kaseta>[13];
	vector<Plyta>* sprzedane_plyty = new vector<Plyta>[13];
	vector<Film>* sprzedane_filmy = new vector<Film>[13];


public:
	Wysylka() : imie(""), nazwisko(""), miasto(""), ulica(""), numer_mieszkania("") {}
	Wysylka(string i, string n, string m, string u, string nm) : imie(i), nazwisko(n), miasto(m), ulica(u), numer_mieszkania(nm) {}
	void wyswietl_dane() {
		cout << "\nImie: " << imie << " Nazwisko: " << nazwisko << " Miasto: " << miasto << " Ulica: " << ulica << " Numer Mieszkania: " << numer_mieszkania << endl;
	}
	void wyswietl_sprzedaz()
	{
		cout << "\nsprzedane rzeczy, adresy wysylek: " << "\n" << miasto << " " << ulica << endl;

		for (int i = 0; i < sprzedane_kasety->size(); i++)
		{
			sprzedane_kasety->at(i).wyswietl_dane();
		}
		for (int i = 0; i < sprzedane_plyty->size(); i++)
		{
			sprzedane_plyty->at(i).wyswietl_dane();
		}
		for (int i = 0; i < sprzedane_filmy->size(); i++)
		{
			sprzedane_filmy->at(i).wyswietl_dane();
		}
	}
	void sprzedaj(Kaseta& k) {
		if (k.czy_sprzedany() == true) {
			return;
		}
		else {
			sprzedane_kasety->push_back(k),
				k.sprzedaj();
		}
	}
	void sprzedaj(Plyta& p) {
		if (p.czy_sprzedany() == true) {
			return;
		}
		else {
			sprzedane_plyty->push_back(p),
				p.sprzedaj();
		}
	}
	void sprzedaj(Film& f) {
		if (f.czy_sprzedany() == true) {
			return;
		}
		else {
			sprzedane_filmy->push_back(f), f.sprzedaj();
		}
	}
	~Wysylka() {}

};
class Dzialalnosc
{
	vector<Kaseta>* kasety = new vector<Kaseta>[13];
	vector<Plyta>* plyty = new vector<Plyta>[13];
	vector<Film>* filmy = new vector<Film>[13];
	vector<Wysylka>* wysylki = new vector<Wysylka>[13];
public:
	Dzialalnosc() {}
	void dodaj_kasete(Kaseta& k) {
		kasety->push_back(k);
	}
	void dodaj_plyte(Plyta& p) {
		plyty->push_back(p);
	}
	void dodaj_film(Film& f) {
		filmy->push_back(f);
	}
	void dodaj_wysylke(Wysylka& w) {
		wysylki->push_back(w);
	}
	void wyswietl_stan()
	{
		cout << "\nStan: \n";

		for (int i = 0; i < kasety->size(); i++)
		{
			kasety->at(i).wyswietl_dane();
		}

		for (int i = 0; i < plyty->size(); i++)
		{
			plyty->at(i).wyswietl_dane();
		}
		for (int i = 0; i < filmy->size(); i++)
		{
			filmy->at(i).wyswietl_dane();
		}
	}
	void pokaz_wysylki()
	{
		cout << "\nWysylki:";
		for (int i = 0; i < wysylki->size(); i++)
			wysylki->at(i).wyswietl_dane();
	}
	~Dzialalnosc() {}
};



int main() {
	Dzialalnosc d1;
	Kaseta kas1("Eminem", 100, "Encore", "dsds", 90);
	Kaseta kas2("Metalica", 110, "load", "dddddd", 100);
	Plyta plyt1("Kasia Kowalska", 50, "Kasia Kowalska", "Pop");
	Plyta plyt2("Wszystko sie moze zdarzyc", 20, "Anita Lipnicka", "Pop");
	Film f1("pewnego razu", 45, "Krawczyk", "polski", 120);
	Film f2("pewnego razu 2", 55, "Krawczyk", "polski", 100);
	Wysylka wys1("Tadeusz", "Norek", "Warszawa", "Karolkowa", "3/4");
	Wysylka wys2("Karol", "Krawczyk", "Radom", "Listopadowa", "33/5");

	d1.dodaj_kasete(kas1);
	d1.dodaj_kasete(kas2);
	d1.dodaj_plyte(plyt1);
	d1.dodaj_plyte(plyt2);
	d1.dodaj_film(f1);
	d1.dodaj_film(f2);
	d1.wyswietl_stan();

	d1.pokaz_wysylki();
	wys1.sprzedaj(f1);
	d1.dodaj_wysylke(wys1);
	wys2.sprzedaj(f2);
	d1.dodaj_wysylke(wys2);
	d1.pokaz_wysylki();
	d1.wyswietl_stan();
	wys1.wyswietl_sprzedaz();
	wys2.wyswietl_sprzedaz();
	d1.pokaz_wysylki();
	system("pause");


}