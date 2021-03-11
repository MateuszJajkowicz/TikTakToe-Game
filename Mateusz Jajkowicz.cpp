#include "stdafx.h"
#include "iostream"
#include "stdlib.h"
#include "conio.h"
#include "windows.h"

using namespace std;
int ruch = 1;
bool TaktykaObronna = false;

int x = 2, y = 2;
char ZnakGracza;
char ZnakKomp;
void menu();

char tab[3][3] = { { '  ' ,' ' ,'  ' },
{ '  ' ,' ' ,'  ' },
{ '  ' ,' ' ,'  ' },
};

bool KtoZaczyna = true;

void czysc()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			tab[i][j] = ' ';
		}
	}
}

void gotoxy(int x, int y)
{
	COORD wsp;
	wsp.X = x;
	wsp.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), wsp);
}


void RuchGracza()
{
	int xtab, ytab;
	bool koniec = false;
	do
	{
		unsigned char znak = _getch();
		switch (znak)
		{
		case 13:
			switch (x)
			{
			case 0:
				xtab = 0;
				break;
			case 2:
				xtab = 1;
				break;
			case 4:
				xtab = 2;
				break;
			}

			switch (y)
			{
			case 0:
				ytab = 0;
				break;
			case 2:
				ytab = 1;
				break;
			case 4:
				ytab = 2;
				break;
			}


			if (tab[xtab][ytab] == ' ')
			{
				tab[xtab][ytab] = ZnakGracza;
				cout << ZnakGracza;
				koniec = true;
			}

			break;

		case 224:
			znak = _getch();
			switch (znak)
			{
			case 72:

				if (y - 2<0)
				{
					y = 4;
				}
				else
				{
					y = y - 2;
				}

				gotoxy(x, y);

				break;
			case 80:
				if (y + 2>4)
				{
					y = 0;
				}
				else
				{
					y = y + 2;
				}

				gotoxy(x, y);


				break;
			case 75:

				if (x - 2<0)
				{
					x = 4;
				}
				else
				{
					x = x - 2;
				}
				gotoxy(x, y);




				break;
			case 77:
				if (x + 2>4)
				{
					x = 0;
				}

				else
				{
					x = x + 2;

				}
				gotoxy(x, y);
				break;
			}
		}
	} while (koniec == false);

}


void ZaznaczPole(int xtab, int ytab)
{
	int x, y;
	tab[xtab][ytab] = ZnakKomp;
	switch (xtab)
	{
	case 0:
		x = 0;
		break;
	case 1:
		x = 2;
		break;
	case 2:
		x = 4;
		break;
	}

	switch (ytab)
	{
	case 0:
		y = 0;
		break;
	case 1:
		y = 2;
		break;
	case 2:
		y = 4;
		break;
	}
	gotoxy(x, y);
	cout << ZnakKomp;
}



bool Wygraj()
{
	int suma = 0;
	int PustePole = 0;
	for (int i = 0; i < 3; i++)
	{
		int suma = 0;
		for (int j = 0; j < 3; j++)
		{
			if (tab[i][j] == ZnakKomp)
				suma++;
			else
				if (tab[i][j] == ' ')
					PustePole = j;
		}
		if (suma == 2 && tab[i][PustePole] == ' ')
		{
			ZaznaczPole(i, PustePole);
			return true;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		int suma = 0;
		for (int j = 0; j < 3; j++)
		{
			if (tab[j][i] == ZnakKomp)
				suma++;
			else
				if (tab[j][i] == ' ')
					PustePole = j;
		}
		if (suma == 2 && tab[PustePole][i] == ' ')
		{
			ZaznaczPole(PustePole, i);
			return true;
		}
	}


	if (tab[0][0] == ZnakKomp && tab[2][2] == ZnakKomp && tab[1][1] == ' ' || tab[0][2] == ZnakKomp && tab[2][0] == ZnakKomp && tab[1][1] == ' ')
	{
		ZaznaczPole(1, 1);
		return true;
	}
	if (tab[1][1] == ZnakKomp)
	{
		if (tab[0][0] == ZnakKomp && tab[2][2] == ' ')
		{
			ZaznaczPole(2, 2);
			return true;
		}
		if (tab[2][2] == ZnakKomp && tab[0][0] == ' ')
		{
			ZaznaczPole(0, 0);
			return true;
		}
		if (tab[2][0] == ZnakKomp && tab[0][2] == ' ')
		{
			ZaznaczPole(0, 2);
			return true;
		}
		if (tab[0][2] == ZnakKomp && tab[2][0] == ' ')
		{
			ZaznaczPole(2, 0);
			return true;
		}
	}
	return false;

}


bool Obron()
{
	int suma = 0;
	int PustePole = 0;
	for (int i = 0; i < 3; i++)
	{
		int suma = 0;
		for (int j = 0; j < 3; j++)
		{
			if (tab[i][j] == ZnakGracza)
				suma++;
			else
				if (tab[i][j] == ' ')
					PustePole = j;
		}
		if (suma == 2 && tab[i][PustePole] == ' ')
		{
			ZaznaczPole(i, PustePole);
			return true;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		int suma = 0;
		for (int j = 0; j < 3; j++)
		{
			if (tab[j][i] == ZnakGracza)
				suma++;
			else
				if (tab[j][i] == ' ')
					PustePole = j;
		}
		if (suma == 2 && tab[PustePole][i] == ' ')
		{
			ZaznaczPole(PustePole, i);
			return true;
		}
	}
	if (tab[0][0] == ZnakGracza && tab[2][2] == ZnakGracza && tab[1][1] == ' ' || tab[0][2] == ZnakGracza && tab[2][0] == ZnakGracza && tab[1][1] == ' ')
	{
		ZaznaczPole(1, 1);
		return true;
	}
	if (tab[1][1] == ZnakGracza)
	{
		if (tab[0][0] == ZnakGracza && tab[2][2] == ' ')
		{
			ZaznaczPole(2, 2);
			return true;
		}
		if (tab[2][2] == ZnakGracza && tab[0][0] == ' ')
		{
			ZaznaczPole(0, 0);
			return true;
		}
		if (tab[2][0] == ZnakGracza && tab[0][2] == ' ')
		{
			ZaznaczPole(0, 2);
			return true;
		}
		if (tab[0][2] == ZnakGracza && tab[2][0] == ' ')
		{
			ZaznaczPole(2, 0);
			return true;
		}
	}
	return false;



}


bool RuchKomp()
{
	if (KtoZaczyna == false && (tab[0][0] == ZnakGracza || tab[2][2] == ZnakGracza || tab[0][2] == ZnakGracza || tab[2][0] == ZnakGracza) && ruch == 1)
		TaktykaObronna = true;
	if (KtoZaczyna == true && (tab[0][1] == ZnakGracza || tab[2][1] == ZnakGracza || tab[1][0] == ZnakGracza || tab[1][2] == ZnakGracza) && ruch == 2)
		TaktykaObronna = true;
	if (TaktykaObronna == true)
	{

		if (tab[1][1] == ' ')
		{
			ZaznaczPole(1, 1);
			ruch++;
			return true;
		}

		if (tab[2][1] == ' ')
		{
			ZaznaczPole(2, 1);
			return true;
		}
		else
		{
			if (tab[0][1] == ' ')
			{
				ZaznaczPole(0, 1);
				return true;
			}
			else
			{
				if (tab[1][0] == ' ')
				{
					ZaznaczPole(1, 0);
					return true;
				}
				else
				{
					if (tab[1][2] == ' ')
					{
						ZaznaczPole(1, 2);
						return true;
					}
				}
			}
		}
	}
	else
	{
		ruch++;
		if (tab[0][0] == ' ')
		{
			ZaznaczPole(0, 0);
			return true;
		}
		else
		{
			if (tab[0][2] == ' ')
			{
				ZaznaczPole(0, 2);
				return true;
			}
			else
			{
				if (tab[2][0] == ' ')
				{
					ZaznaczPole(2, 0);
					return true;
				}
				else
				{
					if (tab[2][2] == ' ')
					{
						ZaznaczPole(2, 2);
						return true;
					}
				}
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (tab[i][j] == ' ')
			{
				ZaznaczPole(i, j);
				return true;
			}
		}

	}
	return false;
}



char Wynik()
{
	float suma = 0;
	bool FULL = true;
	for (int i = 0; i < 3; i++)
	{
		suma = 0;
		for (int j = 0; j < 3; j++)
		{
			suma += tab[i][j];
		}
		if (suma / 120 == 3)
		{
			return 'x';
		}
		else
		{
			if (suma / 111 == 3)
			{
				return 'o';
			}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		suma = 0;
		for (int j = 0; j < 3; j++)
		{
			suma += tab[j][i];
		}
		if (suma / 120 == 3)
		{
			return 'x';
		}
		else
		{
			if (suma / 111 == 3)
			{
				return 'o';
			}
		}
	}

	suma = tab[0][0] + tab[1][1] + tab[2][2];
	if (suma / 120 == 3)
	{
		return 'x';
	}
	else
	{
		if (suma / 111 == 3)
		{
			return 'o';
		}
	}
	suma = tab[2][0] + tab[1][1] + tab[0][2];
	if (suma / 120 == 3)
	{
		return 'x';
	}
	else
	{
		if (suma / 111 == 3)
		{
			return 'o';
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (tab[i][j] == ' ')
			{
				FULL = false;
			}
		}
	}
	if (FULL)
		return 'r';
	return ' ';
}



void win(char wynik)
{
	gotoxy(0, 13);
	switch (wynik)
	{
	case'x':
		if (ZnakGracza == 'x')
			cout << "Wygral GRACZ [x]" << endl;
		else
			cout << "Wygral KOMPUTER [x]" << endl;
		system("pause");
		system("cls");
		menu();
	case 'o':
		if (ZnakGracza == 'o')
			cout << "Wygral GRACZ [o]" << endl;
		else
			cout << "Wygral KOMPUTER [o]" << endl;
		system("pause");
		system("cls");
		menu();
	case 'r':
		cout << "REMIS" << endl;
		system("pause");
		system("cls");
		menu();
	}
}


void plansza()
{
	cout << " " << char(-77) << " " << char(-77) << " " << endl;
	cout << char(-60) << char(-59) << char(-60) << char(-59) << char(-60) << endl;
	cout << " " << char(-77) << " " << char(-77) << " " << endl;
	cout << char(-60) << char(-59) << char(-60) << char(-59) << char(-60) << endl;
	cout << " " << char(-77) << " " << char(-77) << " " << endl;
}




void rozpoczecie()
{
	char znak;
	cout << "wybierz znak o lub x:" << endl;
	do
	{
		cin >> znak;
	} while (znak != 'x' && znak != 'o');

	if (znak == 'x')
	{
		ZnakGracza = 'x';
		ZnakKomp = 'o';
	}

	else
	{
		ZnakGracza = 'o';
		ZnakKomp = 'x';
	}


	cout << "Kto ma zaczynac? g/k" << endl;

	do
	{
		cin >> znak;
	} while (znak != 'g' && znak != 'k');

	if (znak == 'g')
	{
		KtoZaczyna = false;
	}

	else
	{
		KtoZaczyna = true;
	}




	system("cls");
	czysc();
	plansza();

	gotoxy(x, y);

	if (KtoZaczyna)
	{
		do
		{
			if (Wygraj() == false)
			{
				if (Obron() == false)
				{
					RuchKomp();
				}
			}
			if (Wynik() == ZnakKomp)
			{
				win(ZnakKomp);
				break;
			}
			if (Wynik() == 'r')
			{
				win('r');
				break;
			}
			RuchGracza();
			if (Wynik() == ZnakGracza)
			{
				win(ZnakGracza);
				break;
			}
		} while (Wynik() == ' ');
	}
	else
	{
		do
		{
			RuchGracza();
			if (Wynik() == ZnakGracza)
			{
				win(ZnakGracza);
				break;
			}
			if (Wynik() == 'r')
			{
				win('r');
				break;
			}
			if (Wygraj() == false)
			{
				if (Obron() == false)
				{
					RuchKomp();
				}
			}
			if (Wynik() == ZnakKomp)
			{
				win(ZnakKomp);
				break;
			}
		} while (Wynik() == ' ');
	}
	ruch = 1;
	TaktykaObronna = false;
	gotoxy(0, 14);
	system("pause");
	czysc();


}



void zasady()
{
	system("cls");
	cout << "         Sterowanie:" << endl;
	cout << "          Strzalki" << endl;
	cout << "      ------------------" << endl;
	cout << "       Zatwierdzanie:" << endl;
	cout << "           ENTER\n\n" << endl;

	system("pause");
	system("cls");
}


void menu()
{
	system("cls");
	char wybor;
	cout << "\t   Menu:   " << endl;
	cout << "      1.Rozpocznij gre  " << endl;
	cout << "         2.Zasady   " << endl;
	cout << "       Wybierz opcje:" << endl;
	cout << "\t     ";
	cin >> wybor;

	if (wybor != '1' && wybor != '2')
	{
		cout << "    Nie ma takiej opcji.\n\n";
		system("pause");
		system("cls");
		menu();
	}


	switch (wybor)
	{
	case '1':
		system("cls");
		rozpoczecie();
		menu();

	case '2':
		zasady();
		menu();
	}
}




int main()
{
	menu();



	return 0;
}

