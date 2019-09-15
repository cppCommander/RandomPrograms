#include <iostream>
#include <vector>
#include <string>

using namespace std;

int * stos;
int rozmiar = 0;
int rozmiarAktualny = 0;
int licznik = 0;

void tworz_stos(int x, int n) {
	stos = new int[n];
	for (int i = 0; i < n; ++i) {
		stos[i] = x;
	}
	rozmiarAktualny = n;
	rozmiar = n;
}

void na_stos(int a) {
	if (licznik == rozmiar) {
		int * temp;
		temp = new int[rozmiar + 1];
		for (int i = 0; i < rozmiarAktualny; ++i) {
			temp[i] = stos[i];
		}
		stos = temp;
		stos[licznik] = a;
		rozmiarAktualny++;
		rozmiar++;
		licznik++;

	}
	else {
		stos[licznik] = a;
		rozmiarAktualny++;
		licznik++;
	}
}

void ze_stosu() {
	rozmiarAktualny--;
}

void tworz_stos(int n) {
	stos = new int[n];
	for (int i = 0; i < n; ++i) {
		stos[i] = 0;
	}
	rozmiar = n;
}

void czyt_stos() {
	for (int i = 0; i < rozmiarAktualny; ++i) {
		cout << stos[i] << " ";
	}
}

void usun_stos() {
	delete stos;
}


void czyt_stos2() {
	for (int i = 0; i < rozmiarAktualny; ++i) {
		cout << stos[i];
	}
}


void reverse(int x) {

	int temp = 0;
	while (x > 10) {
		temp = x % 10;
		na_stos(temp);
		x = x / 10;
	}
	if (x < 10) {
		temp = x;
		na_stos(temp);
	}
}

int main()
{
	bool b1 = true;
	int liczba;
	while (b1) {
		liczba = 0;
		rozmiar = 0;
		licznik = 0;
		rozmiarAktualny = 0;
		cout << "Jesli chcesz odwrocic liczbe wpisz: 1" << endl;
		cout << "Jesli chcesz utworzyc stos wpisz: 2" << endl;
		cout << "Jesli chcesz wyjsc wpisz: 0" << endl;
		cin >> liczba;
		while (cin.fail() || liczba > 2 || liczba < 0)
		{
			cin.clear();
			cin.ignore();
			cout << "Niepoprawna wartosc" << endl;
			cin >> liczba;
		}
		if (liczba == 1) {
			tworz_stos(1);
			cout << "Podaj liczbe, ktora chcesz odwrocic" << endl;
			cin >> liczba;
			if (liczba != 2147483647) {
				reverse(liczba);
				cout << "Oto odwrocona liczba: ";
				czyt_stos2();
				usun_stos();
				cout << endl;
			}
			else {
				cout << "Liczba jest za dluga na integer" << endl;
			}
		}
		if (liczba == 2) {
			int x;
			int n;
			int v1;
			bool b2 = true;
			cout << "Podaj wartosc" << endl;
			cin >> x;
			cout << "Podaj liczbe n" << endl;
			cin >> n;
			rozmiarAktualny = n;
			tworz_stos(n);
			for (int i = 0; i < n; i++) {
				stos[i] = x;
			}
			czyt_stos();
			cout << endl;
			while (b2) {
				cout << "Jesli chcesz wyrzucic liczbe ze stosu wybierz 3" << endl;
				cout << "Jesli chcesz wrocic do menu wybierz 0" << endl;
				cin >> v1;
				if (v1 == 3 && rozmiar > 0) {
					ze_stosu();
					czyt_stos();
					cout << endl;
				}
				if (v1 == 0) {
					b2 = false;
				}
			}
			usun_stos();
			cout << endl;
		}
		if (liczba == 0) {
			b1 = false;
		}
	}
}
