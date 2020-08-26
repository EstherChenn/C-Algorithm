#include <stdio.h>
//#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#define maxSize 100

void Swap(char s[], int i, int j)
{
	char tmp;

	tmp = s[i];
	s[i] = s[j];
	s[j] = tmp;
}

void FlagSort(char f[])
{
	int b, w, r;//分别代表蓝旗、白旗、红旗指针
	char* tmp = f;
	b = -1;
	w = 0;
	r = strlen(f) - 1;

	while (w <= r)
	{
		if (f[w] == 'W')
			++w;
		else if (f[w] == 'B')
		{
			++b;
			Swap(f, w, b);//曾经做错过的点:因为b当时设置的初值为0，++b不能放在交换操作的前面，若改为-1则可以
		}
		else
		{
			//从后往前找到第一个不是红旗的位置
			while (r >= w && f[r] == 'R')
				--r;

			if (r >= w)
			{
				Swap(f, w, r);
			}
		}
	}
}


int main()
{
	char f[maxSize] = "WRBWRBWWBBRRWRWBBWRRWRBBWB";
	FlagSort(f);
	puts(f);
	return 0;
}