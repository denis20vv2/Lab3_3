#include <cstdlib>
#include <malloc.h>
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");

	int** M1; int** M2; int** M3;
	int n, m;
	cout << "Введите размер матриц M1 и M2" << endl;
	cin >> n >> m;
	M1 = (int**)malloc(n * sizeof(int));
	M2 = (int**)malloc(m * sizeof(int));
	M3 = (int**)malloc((m*n) * sizeof(int));
	
	for (int i = 0; i < n; i++)
	{
		M1[i] = (int*)malloc(n * sizeof(int));
	}

	for (int i = 0; i < m; i++)
	{
		M2[i] = (int*)malloc(m * sizeof(int));
	}

	for (int i = 0; i < m*n; i++)
	{
		M3[i] = (int*)malloc((m*n) * sizeof(int));
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int temp = rand() % 2;
			M1[i][j] = temp;
			M1[j][i] = temp;
			if (i == j)M1[i][j] = 0;
		}
		
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int temp = rand() % 2;
			M2[i][j] = temp;
			M2[j][i] = temp;
			if (i == j)M2[i][j] = 0;
		}
	}

	int mas[100][2];
	int k=0, l = 0;
	for (int i=0;i<n*m;i++)
	{
		if (i % n == 0) 
		{
			k++; l = 0;
		}
		mas[i][0] = k-1;                // n 
		mas[i][1] = l;                // m
		l++;
	}

	for (int i = 0; i < n*m; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << " " << mas[i][j];
		}cout << endl;
	}

	cout << "M1:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << " " << M1[i][j];
		}cout << endl;
	}


	cout << "M2:" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << " " << M2[i][j];
		}cout << endl;

	}



	int a1, a2, b1, b2;
	for (int i = 0; i < m * n; i++)
	{
		for (int j = 0; j < m * n; j++)
		{
			
				a1 = mas[i][1];  // n    
				b1 = mas[i][0];  // n  a1  b1  
				a2 = mas[j][1];  // 
				b2 = mas[j][0];  //    a2  b2 
				if (a1 == a2 && b1 != b2)
				{
					M3[i][j] = M2[b1][b2];
				}
				else {
					if (b2 == b1 && a1 != a2)
					{
						M3[i][j] = M1[a1][a2];
					}
					else {
						if (b2 == b1 && a1 == a2)
						{
							M3[i][j] = 0;
						}
						else {
							if (b2 != b1 && a1 != a2)
							{
								M3[i][j] = 0;
							}
						}
					}
				}
			}
	}

	cout << "M3:" << endl;
	for (int i = 0; i < m*n; i++)
	{
		for (int j = 0; j < m*n; j++)
		{
			cout << " " << M3[i][j];
		}cout << endl;

	}
}

