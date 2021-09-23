#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std; 
void Set(int A[][6], int k);
void Setarray(int A[][6]);
void playgame1(int A[][6], int n);
void playgame2(int A[][6], int n);
void show(int A[][6]);
int main()
{
	int A[36][6] = { 0 };
	Setarray(A);
	//show(A);
	int choice;
	cout << "\nWho first";
	cout << "\n1. Player";
	cout << "\n2. Computer";
	cout << "\n3. Exit" << endl;
	cin >> choice;
	srand(time(NULL));
	if (choice == 1)
		playgame1(A, 1);
	else if (choice == 2)
		playgame2(A, 2);
	else
		cout << "See u again";
}
void Set(int A[][6], int k)
{
	int x = k + 1;
	int y = 1;
	for (int i = k + 1; i <= k + 5; i++)
	{
		int count = 0;
		int vtx = 0;
		int vty = 0;
		for (int j = 1; j <= 5; j++)
		{
			if (A[i][j] != 0)
			{
				count++;
				vtx = i;
				vty = j;
			}
		}
		if (count == 0)
		{
			vtx = x;
			vty = y;
		}
		if ((count == 1|| count == 0) && vtx == x && vty == y)
			A[k][y] = y;
		x++; y++;
	}
}
void Setarray(int A[][6])
{
	for (int i = 34; i >= 1; i--)
	{
		for (int j = 1; j <= 5; j++)
		{
			if (i + j == 35)
			{
				A[i][j] = j;
				break;
			}
			else
				Set(A, i);
		}
	}
}
void playgame1(int A[][6], int n)
{
	int sum = 0;
	int bot = 0;
	int player = 0;
	int luot;
	int flag = 0;
	int switchh = 0;
	while (sum <= 35)
	{
		if (flag == 0)
		{
			if (n == 1)
			{
				sum = 0;
				luot = n;
				player = sum;
			}
			else
			{
				sum = rand() % 3 + 1;
				luot = n + 1;
				bot = sum;
				cout << endl << "Bot: " << bot;
				cout << endl << "Sum = " << sum;
			}
			flag = 1;
		}
		else
		{
			if (luot % 2 != 0)
			{
				cout <<endl<< "Player: ";
				cin >> player;
				if (player == bot || player < 1 || player > 5)
				{
					cout << endl << "Error, do it again";
					luot--;
				}
				else
					sum = sum + player;
				cout << endl << "Sum = " << sum;
				if (sum > 35)
				{
					cout << "\nBot win\n";
					break;
				}
				luot++;
			}
			else
			{
				int light = 0;
				if (switchh == 1 || player == 4 || player == 5)
				{
					for (int j = 1; j <= 5; j++)
					{
						if ((j != player) && (A[sum][j] != 0))
						{
							sum += A[sum][j];
							bot = j;
							light = 1;
						}
					}
					if (light == 0)
					{
						bot = rand() % 5 + 1;
						if (bot == player)
							bot = rand() % 5 + 1;
						sum = sum + bot;
					}
				}
				else if (n == 1 && switchh == 0 && (player == 1 || player == 2 || player == 3))
				{
					bot = rand() % 5 + 1;
					if (bot == player)
						bot = rand() % 5 + 1;
					sum = sum + bot;
					switchh = 1;
				}
				cout << endl << "Bot: "<< bot;
				cout << endl << "Sum = " << sum;
				if (sum > 35)
				{
					cout << "\nPlayer win\n";
					break;
				}
				luot++;
			}
		}
	}
}
void playgame2(int A[][6], int n)
{
	int sum = 0;
	int bot = 0;
	int player = 0;
	int luot;
	int flag = 0;
	while (sum <= 35)
	{
		if (flag == 0)
		{
			if (n == 1)
			{
				sum = 0;
				luot = n;
				player = sum;
			}
			else
			{
				sum = rand() % 3 + 1;
				luot = n + 1;
				bot = sum;
				cout << endl << "Bot: " << bot;
				cout << endl << "Sum = " << sum;
			}
			flag = 1;
		}
		else
		{
			if (luot % 2 != 0)
			{
				cout << endl << "Player: ";
				cin >> player;
				if (player == bot || player < 1 || player > 5)
				{
					cout << endl << "Error, do it again";
					luot--;
				}
				else
					sum = sum + player;
				cout << endl << "Sum = " << sum;
				if (sum > 35)
				{
					cout << "\nBot win\n";
					cin.get();
					break;
				}
				luot++;
			}
			else
			{
				int light = 0;
				for (int j = 1; j <= 5; j++)
				{
					if ((j != player) && (A[sum][j] != 0))	
					{
						sum += A[sum][j];
						bot = j;
						light = 1;
					}
				}
				if(light == 0)
				{
					bot = rand() % 5 + 1;
					if(bot == player)
						bot = rand() % 5 + 1;
					sum = sum + bot;
				}
				cout << endl << "Bot: " << bot;
				cout << endl << "Sum = " << sum;
				if (sum > 35)
				{
					cout << "\nPlayer win\n";
					cin.get();
					break;
				}
				luot++;
			}
		}
	}
}
void show(int A[][6])
{
		for (int i = 35; i >= 1; i--)
		{
			cout << i << "   ";
			for (int j = 1; j <= 5; j++)
				cout << A[i][j] << "   ";
			cout << endl;
		}
}
