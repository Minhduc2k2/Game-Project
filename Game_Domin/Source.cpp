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
struct point
{
	int x;
	int y;
};
void taobaimin(int k, int d[][12])
{
	int x, y;
	srand((unsigned)time(NULL));
	for(int i = 0; i < k; i++)
	{
		x = rand() % 10 + 1;
		y = rand() % 10 + 1;
		if (d[x][y] == 0)
		{
			d[x][y] = 1;
		}
	}
}
void xuat(int a[][12])
{
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)
			cout << a[i][j];
		cout << endl;
	}
}
void taomangmatdo(int d[][12], int m[][12], int k)
{
	int dx[8] = { -1,-1,-1,0,0,1,1,1 };
	int dy[8] = { -1,0,1,-1,1,-1,0,1 };
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)
			if (d[i][j] == 1)
				for (k = 0; k < 8; k++)
					m[i + dx[k]][j + dy[k]]++;
	}
}
void vebang(int t[][12], int m[][12])
{
	cout << static_cast<char>(218);
	cout << static_cast<char>(196);
	for (int i = 1; i <= 10; i++)
	{
		cout << static_cast<char>(196) << static_cast<char>(196);
	}
	cout << static_cast<char>(191) << endl;
	for (int i = 1; i <= 10; i++)
	{
		cout << static_cast<char>(179);
		cout << " ";
		for (int j = 1; j <= 10; j++)
			if (t[i][j] == 1)
				cout << m[i][j];
			else
			{ 
				char ch =  177;
				cout << ch << " ";
			}		
		cout << static_cast<char>(179) << endl;
	}
	cout << static_cast<char>(192);
	for (int i = 1; i <= 10; i++)
	{
		cout << static_cast<char>(196) << static_cast<char>(196);
	}
	cout << static_cast<char>(196);
	cout << static_cast<char>(217);
}
int dichcontro(int x, int y)
{
	if (x < 1 || x > 10 || y < 1 || y > 10)
		return 0;
	gotoxy(y*2, x+1);
	return 1;
}
void chon(int& x, int& y)
{
	char key = _getch();
	dichcontro(x, y);
	while (key != 13)
	{
		if (key == 72)
			if (dichcontro(x - 1, y))
				x--;
		if (key == 80)
			if (dichcontro(x + 1, y))
				x++;
		if (key == 77)
			if (dichcontro(x, y+ 1))
				y++;
		if (key == 75)
			if (dichcontro(x, y - 1))
				y--;
		key = _getch();
	}
}
void loang(int x, int y, int t[][12], int m[][12], int d[][12])
{
	int visit[12][12] = { 0 };
	int l = 1, r = 1;
	int dx[8] = { -1,-1,-1,0,0,1,1,1 };
	int dy[8] = { -1,0,1,-1,1,-1,0,1 };
	point p[150];
	p[l].x = x;
	p[l].y = y; 
	while (l <= r)
	{
		x = p[l].x;
		y = p[l].y;
		t[x][y] = 1;
		if (m[x][y] == 0)
		{
			for (int i = 0; i < 8; i++)
			{
				x = p[l].x + dx[i];
				y = p[l].y + dy[i];
				if(x >= 1 && x <= 10 && y >= 1 && y <= 10)
					if (visit[x][y] == 0 && t[x][y] == 0)
					{
						r++;
						p[r].x = x;
						p[r].y = y;
						visit[x][y] = 1;
					}
			}
		}
		l++;
	}
}
void choigame(int d[][12], int m[][12])
{
	int t[12][12] = { 0 };
	int x = 1;
	int y = 1;
	vebang(t, m);
	chon(x, y);
	loang(x, y, t, m, d);
}
int main()
{
	int d[12][12] = { 0 };
	int m[12][12] = { 0 };
	int k; // tong so min co tren map
	cout << "\nNhap tong so min ";
	cin >> k;
	taobaimin(k, d);
	xuat(d);
	cout << "\n\n";
	taomangmatdo(d, m, k);
	xuat(m);
	cout << "\n\n";
	choigame(d, m);
	return 0;
}