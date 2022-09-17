#include <iostream>
#include <cmath>

using namespace std;

// ������� ���������
bool converge(double xk[10], double xkp[10], int n, double eps)
{
	double norm = 0;
	for (int i = 0; i < n; i++)
		norm += (xk[i] - xkp[i]) * (xk[i] - xkp[i]);
	return (sqrt(norm) < eps);
}

double okr(double x, double eps)
{
	int i = 0;
	double neweps = eps;
	while (neweps < 1)
	{
		i++;
		neweps *= 10;
	}
	int okr = pow(double(10), i);
	x = int(x * okr + 0.5) / double(okr);

	return x;
}

bool diagonal(double a[10][10], int n)
{
	int i, j, k = 1;
	double sum;
	for (i = 0; i < n; i++) {
		sum = 0;
		for (j = 0; j < n; j++) sum += abs(a[i][j]);
		sum -= abs(a[i][i]);
		if (sum > a[i][i]) 
		{
			k = 0; 
			cout << a[i][i] << " < " << sum << endl;
		}
		else
		{
			cout << a[i][i] << " > " << sum << endl;
		}
		

	}

	return (k == 1);

}




int main()
{
	setlocale(LC_ALL, "");

	double eps, a[10][10], b[10], x[10], p[10];
	int n, i, j, m = 0;
	int method;
	cout << "������� ������ ���������� �������: ";
	cin >> n;
	cout << "������� �������� ����������: ";
	cin >> eps;
	cout << "��������� ������� �: " << endl << endl;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			cout << "A[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
	cout << endl << endl;
	cout << "���� ������� �: " << endl << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}

	cout << endl;

	cout << "��������� ������� ��������� ������: " << endl << endl;
	for (i = 0; i < n; i++)
	{
		cout << "�[" << i + 1 << "] = ";
		cin >> b[i];
	}

	cout << endl << endl;


	/*
	��� ������, ���:
	a[n][n] - ������� �������������
	x[n], p[n] - ������� � ���������� �������
	b[n] - ������� ������ ������
	��� ������������� ������� ������������ �
	������ ���� ���������� � �������� ���������,
	����� � ������ x[n] ������� ��������� ���������
	����������� ������� ������� (��������, ��� ����)
	*/

	for (int i = 0; i < n; i++)
		x[i] = 1;

	cout << "������������ ������������: " << endl;
	if (diagonal(a, n)) {
		do
		{
			for (int i = 0; i < n; i++)
				p[i] = x[i];
			for (int i = 0; i < n; i++)
			{
				double var = 0;
				for (int j = 0; j < i; j++)
					var += (a[i][j] * x[j]);
				for (int j = i + 1; j < n; j++)
					var += (a[i][j] * p[j]);
				x[i] = (b[i] - var) / a[i][i];
			}
			m++;
		} while (!converge(x, p, n, eps));



		cout << "������� �������:" << endl << endl;
		for (i = 0; i < n; i++) cout << "x" << i << " = " << okr(x[i], eps) << "" << endl;
		cout << "��������: " << m << endl;
	}
	else {
		cout << "�� ����������� ������������ ����������" << endl;
	}


	system("pause");
	return 0;
}
