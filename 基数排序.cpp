#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUCKETS_COUNT 10

int arrmax(int* arr, unsigned int len) {
	int imax = arr[0];
	for (int ii = 1; ii < len; ii++) if (arr[ii] > imax) imax = arr[ii];
	return imax;
}

void _radixsort(int* arr, unsigned int len, unsigned int exp) {
	int ii=0;
	int* result = (int*)malloc(len * sizeof(int));//���Ͱ���ռ����ݵ���ʱ����
	if (result == NULL) {
		printf("���ݷ���ʧ�ܣ�\n");
		exit(EXIT_FAILURE);
	}
	int buckets[BUCKETS_COUNT] = { 0 };//��ʼ��10��Ͱ

	//����arr�������ݳ��ֵĴ���������buckets��
	for (ii = 0; ii < len; ii++) buckets[(arr[ii] / exp) % 10]++;
	
	//����buckets��Ԫ�ص�ֵ���������ֵ����arr��Ԫ����result��λ��
	for (ii = 1; ii < 10; ii++) buckets[ii] += buckets[ii - 1];

	//��arr�е�Ԫ����䵽result��
	for (ii = len - 1; ii >= 0; ii--) {
		result[buckets[(arr[ii] / exp) % 10] - 1] = arr[ii];
		buckets[(arr[ii] / exp) % 10]--;
	}

	//������õ����鸴�Ƶ�arr��
	memcpy(arr, result, len * sizeof(int));
	free(result);
}

void radixsort(int* arr, unsigned int len) {
	if (len < 2) return;
	int imax = arrmax(arr, len);
	int exp;//����ָ����iexp=1:����λ����iexp=10:��ʮλ����...
	for (exp = 1; imax / exp > 0; exp *= 10) _radixsort(arr, len, exp);
}

int main(int argc, char* argv[]) {
	int arr[] = { 144,203,738,905,347,215,836,26,527,602,946,504,219,750,848 };
	int len = sizeof(arr) / sizeof(int);

	printf("%-15s: ", "Unsorted Array");
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
	radixsort(arr, len);
	printf("%-15s: ", "Sorted Array");
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}