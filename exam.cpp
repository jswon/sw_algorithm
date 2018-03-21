#include <iostream>
#include <string>

using namespace std;

int main()
{
	char sample[1000];

	int case_number;
	int x;

	for (int test_number = 0; test_number < 10; test_number++)
	{
		cin >> case_number;

		int score[101] = { 0, };

		for (int i = 0; i < 1000; i++)
		{
			cin >> x;
			score[x]++;
		}

		int f = 0;
		int idx = 0;
		for (int j = 0; j < 101; j++)
		{
			if (score[j] > f)
			{
				idx = j;
				f = score[j];
			}
		}

		printf("#%d %d \n", case_number, idx);
	}

	return 0;
}
