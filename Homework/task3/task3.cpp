/*����� �������������� ��������� �� ��������� 2 (2^p < x):
�������� ����� x, ������� ���������� ����� p, �����, ��� 2 � ������� p ������ x (���������� ��������� ������� ������).
*/

#include <iostream>;
#include <cmath>;

using namespace std;

void log()
{
	int x;
	int p = 2;

	cin >> x;

	while (pow(2, p) < x)
	{
		p++;
	}
	cout << "The answer is " << p;
}

int main()
{
	log();

	return 0;
}
