// 2230.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;;
}

void sort(int* arr, int left, int right) {
	if (left >= right) return;
	int pivot = *(arr + left);
	int low = left, high = right;
	while (low < high)
	{
		do {
			low++;
		} while (*(arr + low) < pivot);
		while (pivot < *(arr + high))
		{
			high--;
		}
		if (low >= high) break;
		swap((arr + low), (arr + high));
	}
	swap((arr + left), (arr + high));
	sort(arr, left, high - 1);
	sort(arr, low, right);
}

int main()
{
	int input, m;
	scanf("%d %d", &input, &m);
	int* arr = (int*)malloc(sizeof(int)*input);
	for (int i = 0; i < input; i++)
	{
		scanf("%d", (arr + i));
	}
	sort(arr, 0, input - 1);
	int f = 1, s = 0, min = arr[input-1]-arr[s];
	while (s != input)
	{
		if (f == input - 1) s++;
		if (arr[f] - arr[s] >= m)
		{
			if(min>arr[f]-arr[s])min = arr[f] - arr[s];
			s++;
		}
		f++;
	}
	printf("%d", min);
}