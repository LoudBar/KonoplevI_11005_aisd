/*Программа, которая вычисляет корень квадратного уравнения:
Вводятся три числа a, b и c. Вывести все имеющиеся корни, либо написать, что корней нет.
Используйте функцию sqrt из библиотеки math.h. Только вещественные корни (комплексные не надо).
*/

#include <iostream>;
#include <math.h>;

using namespace std;

void equation()
{
	int a, b, c, d, x1, x2;

	cout << "Enter coefficients of the equation" << '\n';

	cin >> a >> b >> c;

	d = sqrt(b * b - 4 * a * c);

	if (d < 0)
	{
		cout << "This equation has no roots";
		exit(1);
	}

	x1 = (b + d) / 2 * a;
	x2 = (b - d) / 2 * a;

	cout << "First root is " << x1 << '\n' << "Second root is " << x2;

}

int main()
{
	equation();

	return 0;
}
