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
	int b, w, r;//�ֱ�������졢���졢����ָ��
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
			Swap(f, w, b);//����������ĵ�:��Ϊb��ʱ���õĳ�ֵΪ0��++b���ܷ��ڽ���������ǰ�棬����Ϊ-1�����
		}
		else
		{
			//�Ӻ���ǰ�ҵ���һ�����Ǻ����λ��
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