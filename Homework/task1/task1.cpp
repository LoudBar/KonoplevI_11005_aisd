//���������, ������� ��������� ����� �����(����� cin � cout) : 
//�������� ���������� �����, ����� ���� �����.����� ������� �� �����. 

#include <iostream>;

using namespace std;

void sum()
{
	int a, n;
	int b = 0;

	cout << "Enter the amount of numbers ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a;
		b += a;
	}

	cout << "The sum is " << b;
}

int main()
{
	sum();
	return 0;
}