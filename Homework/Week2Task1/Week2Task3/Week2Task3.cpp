/*�������� ������� ���������� ������� (�������� ���������� - �����).
void sort(int * a, int size) { � }
*/

#include <iostream>;

using namespace std;

void sort(int* a, int size) // ���������� ���������
{
	int max = 0;
	
	for (int i = 0; i < size; i++) // ����� ������������� �������� ������� �
	{
		if (a[i] > max)
			max = a[i];
	}

	int* tmp = new int[max + 1];

	for (int i = 0; i < max + 1; i++)
	{
		tmp[i] = 0;
	}

	for (int i = 0; i < size; i++) // ������ � ���������� ����� � ������ tmp. ���� � a ���� 4 ������, �� � tmp[a[2]] ����� 4
	{
		tmp[a[i]]++;
	}

	int k = 0;

	for (int i = 0; i < max + 1; i++) // ���� ����������
		for (int j = 0; j < tmp[i]; j++)
		{
			a[k] = i;
			k++;
		}
}

int main()
{
	int a[3]{ 5,3,1 };

	sort(a, 3);

	for (int i = 0; i < 3; i++)
	{
		cout << a[i];
	}

	return 0;
}