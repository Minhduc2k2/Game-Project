#include<iostream>
#include<ctime>
#include<cstdlib>
#include<conio.h>
#include<Windows.h>
using namespace std;
void gotoxy(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}
int dichcontro(int x, int y)
{
	if (x < 0 || x > 9 || y < 0 || y > 9)
		return 0;
	gotoxy(y * 4 + 2, x * 2 + 1);
	return 1;
}
void chon(int& x, int& y)
{
	char key;
	dichcontro(x, y);
	key = _getch();
	while (key != 13)
	{
		if (key == 72)
		{
			if (dichcontro(x - 1, y))
				x--;
		}
		else if (key == 80)
		{
			if (dichcontro(x + 1, y))
				x++;
		}
		else if (key == 75)
		{
			if (dichcontro(x, y - 1))
				y--;
		}
		else if (key == 77)
		{
			if (dichcontro(x, y + 1))
				y++;
		}
		key = _getch();
	}
}

void vebang(int a[][12], int d[][12])
{
	int i;
	cout << static_cast<char>(218);
	for (i = 0; i < 9; i++)
	{
		cout << static_cast<char>(196) << static_cast<char>(196) << static_cast<char>(196) << static_cast<char>(194);
	}
	cout << static_cast<char>(196) << static_cast<char>(196) << static_cast<char>(196);
	cout << static_cast<char>(191) << endl;
	for (i = 0; i < 9; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			cout << static_cast<char>(179) << " ";
			if (d[i][j] == 1)
				cout << "X ";
			else if (d[i][j] == 2)
				cout << "O ";
			else
				cout << "  ";
		}
		cout << endl << static_cast<char>(195);
		for (int j = 0; j < 9; j++)
			cout << static_cast<char>(196) << static_cast<char>(196) << static_cast<char>(196) << static_cast<char>(197);
		cout << static_cast<char>(196) << static_cast<char>(196) << static_cast<char>(196);
		cout << static_cast<char>(180) << endl;
	}
	for (int j = 0; j < 11; j++)
	{
		cout << static_cast<char>(179) << " ";
		if (d[i][j] == 1)
			cout << "X ";
		else if (d[i][j] == 2)
			cout << "O ";
		else
			cout << "  ";
	}
	cout << endl;
	cout << static_cast<char>(192);
	for (int i = 0; i < 9; i++)
	{
		cout << static_cast<char>(196) << static_cast<char>(196) << static_cast<char>(196) << static_cast<char>(193);
	}
	cout << static_cast<char>(196) << static_cast<char>(196) << static_cast<char>(196);
	cout << static_cast<char>(217);
}
void ketqua(int kq)
{
	if (kq == 1)
		cout << "X win";
	else if (kq == 2)
		cout << "O win";
	else
		cout << "Tie";
}
int kiemtradieukienthangX(int d[][12])
{
	int x[4] = { 1,2,3,4 };
	int y[4] = { 1,2,3,4 };
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			if (d[i][j] == 1)
			{
				int dem1 = 1;
				int dem2 = 1;
				int dem3 = 1;
				int dem4 = 1;
				for (int k = 0; k < 4; k++)
				{
					if (d[i + x[k]][j] == 1)
						dem1++;
					if (d[i][j + y[k]] == 1)
						dem2++;
					if (d[i + x[k]][j + y[k]] == 1)
						dem3++;
					if (d[i - x[k]][j + y[k]] == 1)
						dem4++;
				}
				if (dem1 == 5 || dem2 == 5 || dem3 == 5 || dem4 == 5)
					return 1;
			}
	}
	return 0;
}
int kiemtradieukienthangO(int d[][12])
{
	int x[4] = { 1,2,3,4 };
	int y[4] = { 1,2,3,4 };
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			if (d[i][j] == 2)
			{
				int dem1 = 1;
				int dem2 = 1;
				int dem3 = 1;
				int dem4 = 1;
				for (int k = 0; k < 4; k++)
				{
					if (d[i + x[k]][j] == 2)
						dem1++;
					if (d[i][j + y[k]] == 2)
						dem2++;
					if (d[i + x[k]][j + y[k]] == 2)
						dem3++;
					if (d[i - x[k]][j + y[k]] == 2)
						dem4++;
				}
				if (dem1 == 5 || dem2 == 5 || dem3 == 5 || dem4 == 5)
					return 1;
			}
	}
	return 0;
}
int kiemtradieukienhoa(int d[][12])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			if (d[i][j] == 0)
				return 0;
	}
	return 1;
}
void choigame(int a[][12], int d[][12])
{
	int x = 0, y = 0;
	vebang(a, d);
	int luot = 0;
	while (1)
	{
		chon(x, y);
		if (luot % 2 == 0)
		{
			if (d[x][y] == 0)
				d[x][y] = 1;
			else
				luot--;
		}
		else
		{
			if (d[x][y] == 0)
				d[x][y] = 2;
			else luot--;
		}
		luot++;
		gotoxy(0, 0);
		vebang(a, d);
		if (kiemtradieukienthangX(d) == 1)
		{
			gotoxy(25, 25);
			ketqua(1);
			break;
		}
		if (kiemtradieukienthangO(d) == 1)
		{
			gotoxy(25, 25);
			ketqua(2);
			break;
		}
		if (kiemtradieukienhoa(d) == 1)
		{
			gotoxy(25, 25);
			ketqua(0);
			break;
		}
	}
}

int main()
{
	int a[12][12] = { 0 };
	int d[12][12] = { 0 };
	choigame(a, d);
	//_getch();
}