#include <iostream>
#include <vector>
//#include "stdafx.h"
using namespace std;


//������� �������
const int maxV = 1000;
int i, j, n;
int GR[maxV][maxV];
//�������� ������-��������
void FU(int D[][maxV], int V)
{
	int k;
	for (i = 0; i < V; i++) D[i][i] = 0;

	for (k = 0; k < V; k++)
		for (i = 0; i < V; i++)
			for (j = 0; j < V; j++)
				if (D[i][k] && D[k][j] && i != j)
					if (D[i][k] + D[k][j] < D[i][j] || D[i][j] == 0)
						D[i][j] = D[i][k] + D[k][j];

	for (i = 0; i < V; i++)
	{
		for (j = 0; j < V; j++) cout << D[i][j] << "\t";
		cout << endl;
	}
}
void main()
{
	setlocale(LC_ALL, "Rus");
	cout << "���������� ������ � ����� > "; cin >> n;
	cout << "������� ������� ����� �����:\n";
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
		{
			cout << "GR[" << i + 1 << "][" << j + 1 << "] > ";
			cin >> GR[i][j];
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
		{
			cout << GR[i][j] << " ";
		}
		cout << endl;
	}
	cout << "������� ���������� �����:" << endl;
	FU(GR, n);
	system("pause>>void");
}

