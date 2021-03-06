#include "pch.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct a {
	int old;
	char name[100];
}a;

void sort(a* arr, int start, int end)
{
	if (end == start) return;
	int mid = (end + start) / 2;
	if (end - start > 1)
	{
		sort(arr, start, mid);
		sort(arr, mid + 1, end);
	}
	int left = start, right = mid + 1;
	int length = end - start + 1;
	a* tarr = (a*)calloc(length, sizeof(a));
	int index = 0;
	while (index != length)
	{
		if (left > mid) {
			tarr[index++] = arr[right++];
		}
		else if (right > end)
		{
			tarr[index++] = arr[left++];
		}
		else {
			if (arr[left].old <= arr[right].old)
			{
				tarr[index++] = arr[left++];
			}
			else {
				tarr[index++] = arr[right++];
			}
		}
	}
	for (index = 0; index < length; index++)
	{
		arr[start + index] = tarr[index];
	}
	free(tarr);
}

int main()
{
	int input, i;
	scanf("%d", &input);
	a* arr = (a*)malloc(sizeof(a)*input);
	for (i = 0; i < input; i++)
	{
		scanf("%d %s", &(arr[i].old), arr[i].name);
	}
	sort(arr, 0, input - 1);
	for (i = 0; i < input; i++)
	{
		printf("%d %s\n", arr[i].old, arr[i].name);
	}
	free(arr);
}