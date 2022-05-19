#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include <conio.h>
#include <string.h>
#include "header2.h"
using namespace std;
fstream f;
void main()
{
	system("Color 6");
	char c, f, men, sort, val, save;
	placa_video t[15]; int n; procesor z[15]; placa_de_baza x[20]; ram v[15]; monitor b[15];
	tastatura m[15]; mouse l[15]; casti k[15]; calculator calc[15];
	cout << "Logativa introducant prenumele si numele: ";
	char nume[50]; string nume_2, save_file;
	cin.get(nume, 50);
	nume_2 = decupare_nume(nume);
	do
	{
	do
	{
		system("cls");
		cout << "\t\t\tARK WARDEN SHOP" << endl << "Buna ziua " <<nume_2<< "suntem companie de vanzare a calculatoarelor" << endl << endl;
		cout << "\tCatalog" << endl << "1 - Componente " << endl;
		cout << "2 - Periferie" << endl;
		cout << "3 - Calculatoare asamblate" << endl;
		cout << "4 - Salvarea produselor intr-un fisier" << endl;
		cout << "0 - Iesire" << endl;
		c = _getch();
		system("cls");
		switch (c)
		{
		case '1':
			do
			{
				cout << "\tComponente" << endl;
				cout << "1 - Placa Video " << endl;
				cout << "2 - Procesor" << endl;
				cout << "3 - Placa de baza" << endl;
				cout << "4 - Memoria ram" << endl;
				cout << "0 - Inapoi " << endl;
				f = _getch();
				system("cls");

				switch (f)
				{

				case '1': citire_video(t, n); afisare_video(t, n);
					cout << endl << "Meniuri" << endl;
					cout << "1 - Sortare" << endl;
					cout << "2 - Adaugare" << endl;
					cout << "3 - Excluderea" << endl;
					cout << "4 - Actualizarea unei linii" << endl;
					cout << "5 - Valoarea extrema " << endl;
					cout << "6 - Valoarea medie" << endl;
					cout << "0 - Inapoi " << endl;
					men = _getch();
					system("cls");
					switch (men)
					{
					case '1': cout << "\tSortare" << endl;
						cout << "1 - Pret mic=>mare " << endl;
						cout << "2 - Pret mare=>mic " << endl;
						sort = _getch();
						system("cls");
						switch (sort)
						{
						case '1': sortare_video_mic(t, n);  _getch(); break;
						case '2': sortare_video_mare(t, n);  _getch(); break;
						}
						break;
					case '2': cout << "\tAdaugare" << endl;
						adaugare_video(t, n); _getch(); break;
					case '3': excludere_video(t, n); _getch(); break;
					case '4': actualizare_video(t, n); _getch(); break;
					case '5':
						cout << "1 - Pret" << endl;
						cout << "2 - Memoria video" << endl;
						val = _getch();
						system("cls");
						switch (val)
						{
						case '1': extrem_video_pret(t, n); _getch(); break;
						case '2': extrem_video_memorie(t, n); _getch(); break;
						}
						break;
					case '6':
						cout << "1 - Pret" << endl;
						cout << "2 - Memoria video" << endl;
						val = _getch();
						system("cls");
						switch (val)
						{
						case '1': media_video_pret(t, n); _getch(); break;
						case '2': media_video_memorie(t, n); _getch(); break;
						}
					}
					break;
				case '2': citire_procesor(z, n); afisare_procesor(z, n);
					cout << endl << "Meniuri" << endl;
					cout << "1 - Sortare" << endl;
					cout << "2 - Adaugare" << endl;
					cout << "3 - Excluderea" << endl;
					cout << "4 - Actualizarea unei linii" << endl;
					cout << "5 - Valoarea extrema " << endl;
					cout << "6 - Valoarea medie" << endl;
					cout << "0 - Inapoi " << endl;
					men = _getch();
					system("cls");
					switch (men)
					{
					case '1': cout << "\tSortare" << endl;
						cout << "1 - Pret mic=>mare " << endl;
						cout << "2 - Pret mare=>mic " << endl;
						sort = _getch();
						system("cls");
						switch (sort)
						{
						case '1': sortare_procesor_mic(z, n);  _getch(); break;
						case '2': sortare_procesor_mare(z, n);  _getch(); break;
						}
						break;
					case '2': cout << "\tAdaugare" << endl;
						adaugare_procesor(z, n); _getch(); break;
					case '3': excludere_procesor(z, n); _getch(); break;
					case '4': actualizare_procesor(z, n); _getch(); break;
					case '5':
						cout << "1 - Pret" << endl;
						cout << "2 - Frecventa" << endl;
						val = _getch();
						system("cls");
						switch (val)
						{
						case '1': extrem_procesor_pret(z, n); _getch(); break;
						case '2': extrem_procesor_frecventa(z, n); _getch(); break;

						}
						break;
					case '6':
						cout << "1 - Pret" << endl;
						cout << "2 - Frecventa" << endl;
						val = _getch();
						system("cls");
						switch (val)
						{
						case '1': media_procesor_pret(z, n); _getch(); break;
						case '2': media_procesor_frecventa(z, n); _getch(); break;
						}
					}
					break;
				case '3': citire_placa(x, n); afisare_placa(x, n);
					cout << endl << "Meniuri" << endl;
					cout << "1 - Sortare" << endl;
					cout << "2 - Adaugare" << endl;
					cout << "3 - Excluderea" << endl;
					cout << "4 - Actualizarea unei linii" << endl;
					cout << "5 - Valoarea extrema " << endl;
					cout << "6 - Valoarea medie" << endl;
					cout << "0 - Inapoi " << endl;
					men = _getch();
					system("cls");
					switch (men)
					{
					case '1': cout << "\tSortare" << endl;
						cout << "1 - Pret mic=>mare " << endl;
						cout << "2 - Pret mare=>mic " << endl;
						sort = _getch();
						system("cls");
						switch (sort)
						{
						case '1': sortare_placa_mic(x, n);  _getch(); break;
						case '2': sortare_placa_mare(x, n);  _getch(); break;
						}
						break;
					case '2': cout << "\tAdaugare" << endl;
						adaugare_placa(x, n); _getch(); break;
					case '3': excludere_placa(x, n); _getch(); break;
					case '4': actualizare_placa(x, n); _getch(); break;
					case '5':
						cout << "1 - Pret" << endl;
						cout << "2 - Max ram" << endl;
						val = _getch();
						system("cls");
						switch (val)
						{
						case '1': 
							(x, n); _getch(); break;
						case '2': extrem_placa_memorie(x, n); _getch(); break;
						}
						break;
					case '6':
						cout << "1 - Pret" << endl;
						cout << "2 - Max ram" << endl;
						val = _getch();
						system("cls");
						switch (val)
						{
						case '1': media_placa_pret(x, n); _getch(); break;
						case '2': media_placa_memorie(x, n); _getch(); break;
						}
					}
					break;
				case '4': citire_ram(v, n); afisare_ram(v, n);
					cout << endl << "Meniuri" << endl;
					cout << "1 - Sortare" << endl;
					cout << "2 - Adaugare" << endl;
					cout << "3 - Excluderea" << endl;
					cout << "4 - Actualizarea unei linii" << endl;
					cout << "5 - Valoarea extrema " << endl;
					cout << "6 - Valoarea medie" << endl;
					cout << "0 - Inapoi " << endl;
					men = _getch();
					system("cls");
					switch (men)
					{
					case '1': cout << "\tSortare" << endl;
						cout << "1 - Pret mic=>mare " << endl;
						cout << "2 - Pret mare=>mic " << endl;
						sort = _getch();
						system("cls");
						switch (sort)
						{
						case '1': sortare_ram_mic(v, n);  _getch(); break;
						case '2': sortare_ram_mare(v, n);  _getch(); break;
						}
						break;
					case '2': cout << "\tAdaugare" << endl;
						adaugare_ram(v, n); _getch(); break;
					case '3': excludere_ram(v, n); _getch(); break;
					case '4': actualizare_ram(v, n); _getch(); break;
					case '5':
						cout << "1 - Pret" << endl;
						cout << "2 - Frecventa" << endl;
						val = _getch();
						system("cls");
						switch (val)
						{
						case '1': extrem_ram_pret(v, n); _getch(); break;
						case '2': extrem_ram_frecventa(v, n); _getch(); break;
						}
						break;
					case '6':
						cout << "1 - Pret" << endl;
						cout << "2 - Frecventa" << endl;
						val = _getch();
						system("cls");
						switch (val)
						{
						case '1': media_ram_pret(v, n); _getch(); break;
						case '2': media_ram_frecventa(v, n); _getch(); break;
						}
					}
					break;
				}
				system("cls");
			} while (f != '0');
			break;
		case '2': 
			do
			{
			cout << "\tPeriferie" << endl;
			cout << "1 - Monitor " << endl;
			cout << "2 - Tastatura" << endl;
			cout << "3 - Mouse" << endl;
			cout << "4 - Casti" << endl;
			cout << "0 - Inapoi " << endl;
			f = _getch();
			system("cls");
			switch (f)
			{
			case '1': citire_monitor(b, n); afisare_monitor(b, n);
				cout << endl << "Meniuri" << endl;
				cout << "1 - Sortare" << endl;
				cout << "2 - Adaugare" << endl;
				cout << "3 - Excluderea" << endl;
				cout << "4 - Actualizarea unei linii" << endl;
				cout << "5 - Valoarea extrema " << endl;
				cout << "6 - Valoarea medie" << endl;
				cout << "0 - Inapoi " << endl;
				men = _getch();
				system("cls");
				switch (men)
				{
				case '1': cout << "\tSortare" << endl;
					cout << "1 - Pret mic=>mare " << endl;
					cout << "2 - Pret mare=>mic " << endl;
					sort = _getch();
					system("cls");
					switch (sort)
					{
					case '1': sortare_monitor_mic(b, n);  _getch(); break;
					case '2': sortare_monitor_mare(b, n);  _getch(); break;
					}
					break;
				case '2': cout << "\tAdaugare" << endl;
					adaugare_monitor(b, n); _getch(); break;
				case '3': excludere_monitor(b, n); _getch(); break;
				case '4': actualizare_monitor(b, n); _getch(); break;
				case '5':
					cout << "1 - Pret" << endl;
					cout << "2 - Frecventa" << endl;
					val = _getch();
					system("cls");
					switch (val)
					{
					case '1': extrem_monitor_pret(b, n); _getch(); break;
					case '2': extrem_monitor_frecventa(b, n); _getch(); break;
					}
					break;
				case '6':
					cout << "1 - Pret" << endl;
					cout << "2 - Frecventa" << endl;
					val = _getch();
					system("cls");
					switch (val)
					{
					case '1': media_monitor_pret(b, n); _getch(); break;
					case '2': media_monitor_frecventa(b, n); _getch(); break;
					}
				}
				break;
			case '2': citire_tastatura(m, n); afisare_tastatura(m, n);
				cout << endl << "Meniuri" << endl;
				cout << "1 - Sortare" << endl;
				cout << "2 - Adaugare" << endl;
				cout << "3 - Excluderea" << endl;
				cout << "4 - Actualizarea unei linii" << endl;
				cout << "5 - Valoarea extrema " << endl;
				cout << "6 - Valoarea medie" << endl;
				cout << "0 - Inapoi " << endl;
				men = _getch();
				system("cls");
				switch (men)
				{
				case '1': cout << "\tSortare" << endl;
					cout << "1 - Pret mic=>mare " << endl;
					cout << "2 - Pret mare=>mic " << endl;
					sort = _getch();
					system("cls");
					switch (sort)
					{
					case '1': sortare_tastatura_mic(m, n);  _getch(); break;
					case '2': sortare_tastatura_mare(m, n);  _getch(); break;
					}
					break;
				case '2': cout << "\tAdaugare" << endl;
					adaugare_tastatura(m, n); _getch(); break;
				case '3': excludere_tastatura(m, n); _getch(); break;
				case '4': actualizare_tastatura(m, n); _getch(); break;
				case '5':
					cout << "1 - Pret" << endl;
					cout << "2 - Nr.taste" << endl;
					val = _getch();
					system("cls");
					switch (val)
					{
					case '1': extrem_tastatura_pret(m, n); _getch(); break;
					case '2': extrem_tastatura_taste(m, n); _getch(); break;
					}
					break;
				case '6':
					cout << "1 - Pret" << endl;
					cout << "2 - Nr.taste" << endl;
					val = _getch();
					system("cls");
					switch (val)
					{
					case '1': media_tastatura_pret(m, n); _getch(); break;
					case '2': media_tastatura_taste(m, n); _getch(); break;
					}
				}
				break;
			case '3': citire_mouse(l, n); afisare_mouse(l, n);
				cout << endl << "Meniuri" << endl;
				cout << "1 - Sortare" << endl;
				cout << "2 - Adaugare" << endl;
				cout << "3 - Excluderea" << endl;
				cout << "4 - Actualizarea unei linii" << endl;
				cout << "5 - Valoarea extrema " << endl;
				cout << "6 - Valoarea medie" << endl;
				cout << "0 - Inapoi " << endl;
				men = _getch();
				system("cls");
				switch (men)
				{
				case '1': cout << "\tSortare" << endl;
					cout << "1 - Pret mic=>mare " << endl;
					cout << "2 - Pret mare=>mic " << endl;
					sort = _getch();
					system("cls");
					switch (sort)
					{
					case '1': sortare_mouse_mic(l, n);  _getch(); break;
					case '2': sortare_mouse_mare(l, n);  _getch(); break;
					}
					break;
				case '2': cout << "\tAdaugare" << endl;
					adaugare_mouse(l, n); _getch(); break;
				case '3': excludere_mouse(l, n); _getch(); break;
				case '4': actualizare_mouse(l, n); _getch(); break;
				case '5':
					cout << "1 - Pret" << endl;
					cout << "2 - Nr.butoane" << endl;
					val = _getch();
					system("cls");
					switch (val)
					{
					case '1': extrem_mouse_pret(l, n); _getch(); break;
					case '2': extrem_mouse_butoane(l, n); _getch(); break;
					}
					break;
				case '6':
					cout << "1 - Pret" << endl;
					cout << "2 - Nr.butoane" << endl;
					val = _getch();
					system("cls");
					switch (val)
					{
					case '1': media_mouse_pret(l, n); _getch(); break;
					case '2': media_mouse_butoane(l, n); _getch(); break;
					}
				}
				break;
			case '4': citire_casti(k, n); afisare_casti(k, n);
				cout << endl << "Meniuri" << endl;
				cout << "1 - Sortare" << endl;
				cout << "2 - Adaugare" << endl;
				cout << "3 - Excluderea" << endl;
				cout << "4 - Actualizarea unei linii" << endl;
				cout << "5 - Valoarea extrema " << endl;
				cout << "6 - Valoarea medie" << endl;
				cout << "0 - Inapoi " << endl;
				men = _getch();
				system("cls");
				switch (men)
				{
				case '1': cout << "\tSortare" << endl;
					cout << "1 - Pret mic=>mare " << endl;
					cout << "2 - Pret mare=>mic " << endl;
					sort = _getch();
					system("cls");
					switch (sort)
					{
					case '1': sortare_casti_mic(k, n);  _getch(); break;
					case '2': sortare_casti_mare(k, n);  _getch(); break;
					}
					break;
				case '2': cout << "\tAdaugare" << endl;
					adaugare_casti(k, n); _getch(); break;
				case '3': excludere_casti(k, n); _getch(); break;
				case '4': actualizare_casti(k, n); _getch(); break;
				case '5':
					cout << "1 - Pret" << endl;
					cout << "2 - Impedanta" << endl;
					val = _getch();
					system("cls");
					switch (val)
					{
					case '1': extrem_casti_pret(k, n); _getch(); break;
					case '2': extrem_casti_impedanta(k, n); _getch(); break;
					}
					break;
				case '6':
					cout << "1 - Pret" << endl;
					cout << "2 - Impedanta" << endl;
					val = _getch();
					system("cls");
					switch (val)
					{
					case '1': media_casti_pret(k, n); _getch(); break;
					case '2': extrem_casti_impedanta(k, n); _getch(); break;
					}
				}
				break;
			}
			system("cls");
			} while (f != '0');
			break;
		case '3': 
			cout << "\tCalculatoare asamblate" << endl;
			citire_calculator(calc, n); afisare_calculator(calc, n);
			cout << endl << "Meniuri" << endl;
			cout << "1 - Sortare" << endl;
			cout << "2 - Adaugare" << endl;
			cout << "3 - Excluderea" << endl;
			cout << "4 - Actualizarea unei linii" << endl;
			cout << "5 - Valoarea extrema " << endl;
			cout << "6 - Valoarea medie" << endl;
			cout << "0 - Inapoi " << endl;
			men = _getch();
			system("cls");
			switch (men)
			{
			case '1': cout << "\tSortare" << endl;
				cout << "1 - Pret mic=>mare " << endl;
				cout << "2 - Pret mare=>mic " << endl;
				sort = _getch();
				system("cls");
				switch (sort)
				{
				case '1': sortare_calculator_mic(calc, n);  _getch(); break;
				case '2': sortare_calculator_mare(calc, n);  _getch(); break;
				}
				break;
			case '2': cout << "\tAdaugare" << endl;
				adaugare_calculator(calc, n); _getch(); break;
			case '3': excludere_calculator(calc, n); _getch(); break;
			case '4': actualizare_calculator(calc, n); _getch(); break;
			case '5':
				cout << "1 - Pret" << endl;
				cout << "2 - Memoria ram" << endl;
				val = _getch();
				system("cls");
				switch (val)
				{
				case '1': extrem_calculator_pret(calc, n); _getch(); break;
				case '2': extrem_calculator_ram(calc, n); _getch(); break;
				}
				break;
			case '6':
				cout << "1 - Pret" << endl;
				cout << "2 - Memoria ram" << endl;
				val = _getch();
				system("cls");
				switch (val)
				{
				case '1': media_calculator_pret(calc, n); _getch(); break;
				case '2': media_calculator_ram(calc, n); _getch(); break;
				}
			}
			break;
		case '4': cout << "Introdu denumirea fisierului: "; cin >> save_file;
			cout << "1 - Componente " << endl;
			cout << "2 - Periferie" << endl;
			cout << "3 - Calculatoare asamblate" << endl;
			save = _getch();
			system("cls");
			switch (save)
			{
			case '1': cout << "\tComponente" << endl;
				cout << "1 - Placa Video " << endl;
				cout << "2 - Procesor" << endl;
				cout << "3 - Placa de baza" << endl;
				cout << "4 - Memoria ram" << endl;
				f = _getch();
				system("cls");
				switch (f)
				{
				case '1': citire_video(t, n); save_video(t, n, save_file); break;
				case '2': citire_procesor(z, n); save_procesor(z, n, save_file); break;
				case '3': citire_placa(x, n); save_placa(x, n, save_file); break;
				case '4': citire_ram(v, n); save_ram(v, n, save_file); break;
				}
				break;
			case '2': cout << "\tPeriferie" << endl;
				cout << "1 - Monitor " << endl;
				cout << "2 - Tastatura" << endl;
				cout << "3 - Mouse" << endl;
				cout << "4 - Casti" << endl;
				f = _getch();
				system("cls");
				switch (f)
				{
				case '1': citire_monitor(b, n); save_monitor(b, n, save_file); break;
				case '2': citire_tastatura(m, n); save_tastatura(m, n, save_file); break;
				case '3': citire_mouse(l, n); save_mouse(l, n, save_file); break;
				case '4': citire_casti(k, n); save_casti(k, n, save_file); break;
				}
				break;
			case '3': citire_calculator(calc, n); save_calculator(calc, n, save_file); break;
			}
		}
		break;
	} while (c != '0');
}while (c != '0');
}