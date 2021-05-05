#include <iostream>;
#include <vector>;
#include <algorithm>;

using namespace std;

int *task1(int x)
{
	int* arr = new int[3];
	for (int i = 0; i < 3; i++) arr[i] = 0;

	while (x != 0) {

		if (x - 10 >= 0) { arr[2]++; x -= 10; }
		else if (x - 5 >= 0) { arr[1]++; x -= 5; }
		else if (x - 1 >= 0) { arr[0]++; x -= 1; }
	
	}
	return arr;
	delete[] arr;
}

bool compareByValue(int* a, int* b) {
    return a[1] > b[1];
}

int floor(int x, int* a)  {

    if (a[x] == 1) {
        a[x] = 0;
        return x;
    }
    else while (x >= 0 & a[x] != 1) --x;
        
    if (x >= 0) {
        a[x] = 0;
        return x;
    }
    return -1;
}

int* deadlineCounter(vector<int*> a) {

    sort(a.begin(), a.end(), compareByValue);

    int* ans = new int[5];
    int* forFloor = new int[5]{ 1, 1, 1, 1, 1 };

    for (int i = 0; i < 5; i++) {

        int* p = a[i];
        ans[floor(p[2] - 1, forFloor)] = p[0];
    }
    return ans;
}


int main()
{

	int* arr = task1(26);

    cout << "< -------------------------------------- Task 1 -------------------------------------- >" << endl;

	for (int i = 0; i < 3; i++) cout << arr[i] << endl;

    vector<int*> v;

    int* t1 = new int[3]{ 1, 4, 5 };
    int* t2 = new int[3]{ 2, 10, 5 };
    int* t3 = new int[3]{ 3, 12, 1 };
    int* t4 = new int[3]{ 4, 8, 4 };
    int* t5 = new int[3]{ 5, 1, 5 };

    v.push_back(t1);
    v.push_back(t2);
    v.push_back(t3);
    v.push_back(t4);
    v.push_back(t5);

    int* ans = deadlineCounter(v);


    cout << "< -------------------------------------- Task 2 -------------------------------------- >" << endl;

    for (int i = 0; i < 5; i++) cout << ans[i] << " ";

	return 0;
}