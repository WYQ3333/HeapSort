#include<stdio.h>
#include<Windows.h>

void swap(int *p, int *q)
{
	int *tmp = *p;
	*p = *q;
	*q = tmp;
}

void AddjustDown(int array[], int size, int k)
{
	int left = 2 * k + 1;
	int right = 2 * k + 2;
	while (left < size)
	{
		int max = left;
		if (right < size)
		{
			if (array[right]>array[left])
				max = right;
		}
		if (array[k]>array[max])
			break;
		swap(&array[k], &array[max]);
		k = max;
		left = 2 * k + 1;//往下走，循环
		right = 2 * k + 2;
	}
}

void HeapSort(int array[], int size)
{
	//建堆(升序建大堆，降序建小堆)
	int i = 0;
	for (i = (size - 2) / 2; i >= 0; i--)
	{
		AddjustDown(array, size,i);//向下调整
	}
	for (int i = 0; i < size; i++)
	{
		swap(&array[0], &array[size - 1 - i]);//只交换堆顶元素与末尾元素
		AddjustDown(array, size-1-i, 0);//向下调整
	}
}


void test()
{
	int array[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int size = sizeof(array) / sizeof(array[0]);
	HeapSort(array, size);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
}

int main()
{
	test();
	system("pause");
	return 0;
}