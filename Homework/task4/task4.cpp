/*������� ���������� ������ ����� � ����������� �������:
int power(int x, unsigned p);
������� � ������� ��� ����� x � p, ��������� ��� ��� ��� �������.
 */

#include <iostream>;

using namespace std;

int power(int x, unsigned p)
{
	for (int i = 0; i < p - 1; i++)
	{
		x *= x;
	}

	cout << "Answer is " << x;

	return 0;
}

int main()
{
	int x, p;

	cout << "Enter number and power" << '\n';
	cin >> x >> p;

	power(x, p);

	return 0;
}