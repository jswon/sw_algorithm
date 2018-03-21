// SW Expert Academy, 1213
// Boyer moore Algorithm.

#include <iostream>
#include <string>

using namespace std;

int findNumPattern(string pattern, string sentence)
{
	int ptn_size = pattern.size();
	int ptn_end = pattern.size() - 1;
	int pos = ptn_end;
	
	int sum = 0;
	bool flag = false;

	while (!(pos > sentence.size())) {
		if (sentence[pos] == pattern[ptn_end])
		{
			int cnt = 0;

			for (int i = ptn_size - 1; i >= 0; i--)
			{
				if (sentence[pos + i - ptn_size + 1] != pattern[i])
				{
					pos += ptn_size - i;
					break;
				}
				else cnt++;
			}

			if (cnt == ptn_size)
			{
				sum++;
				pos += ptn_size;
			}
		}
		else if (sentence[pos] != pattern[ptn_end])
		{
			flag = true;
			for (int i = ptn_size - 1; i >= 0; i--)
			{
				if (sentence[pos] == pattern[i])
				{
					pos += ptn_size - 1 - i;
					flag = false;
					break;
				}
			}

			if (flag) 
			{
				pos += ptn_size;
				flag = false;
			}

		}
		else if (sentence.size() - 1 - pos < ptn_size)
			pos += sentence.size() - 1 - pos;
	}
	return sum;
}

int main()
{
	for (int test_case = 0; test_case < 10; test_case++)
	{
		int test_id;
		scanf("%d", &test_id);

		string pattern;
		cin >> pattern;

		string sentence;
		cin >> sentence;

		int sum = 0;
		sum = findNumPattern(pattern, sentence);

		printf("#%d %d\n", test_id, sum);
	}

	return 0;
}