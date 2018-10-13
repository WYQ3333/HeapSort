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
		left = 2 * k + 1;//�����ߣ�ѭ��
		right = 2 * k + 2;
	}
}

void HeapSort(int array[], int size)
{
	//����(���򽨴�ѣ�����С��)
	int i = 0;
	for (i = (size - 2) / 2; i >= 0; i--)
	{
		AddjustDown(array, size,i);//���µ���
	}
	for (int i = 0; i < size; i++)
	{
		swap(&array[0], &array[size - 1 - i]);//ֻ�����Ѷ�Ԫ����ĩβԪ��
		AddjustDown(array, size-1-i, 0);//���µ���
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