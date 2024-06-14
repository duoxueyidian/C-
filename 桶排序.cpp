#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//ð�������㷨
void bubblesort(int* arr, int n) {
	if (n < 2) return;
	int ifswap;//ÿ�������Ƿ񽻻���Ԫ�أ�0-δ������1-������
	int itmp;//����Ԫ��ʱ���м����
	//i����������������
	for (int i = n - 1; i > 0; i--) {
		ifswap = 0;
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				itmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = itmp;
				ifswap = 1;
			}

		}
		if (ifswap == 0) return;
	}
}

//Ͱ����
void bucketsort(int* arr, unsigned int len) {
	int bucket[5][5];//����5��Ͱ
	int bucketsize[5];//ÿ��ͰԪ�ظ���������

	//��ʼ��Ͱ��Ͱ������
	memset(bucket, 0, sizeof(bucket));
	memset(bucketsize, 0, sizeof(bucketsize));

	//��arr�����ݷ���Ͱ�У��ٶ�ÿ��Ͱð������
	for (int ii = 0; ii < len; ii++) bucket[arr[ii] / 10][bucketsize[arr[ii] / 10]++] = arr[ii];
	for (int jj = 0; jj < 5; jj++) bubblesort(bucket[jj], bucketsize[jj]);

	//��ÿ��Ͱ�е�������䵽arr��
	int kk = 0;
	for (int ii = 0; ii < 5; ii++) {
		int jj = 0;
		while (jj < bucketsize[ii]) arr[kk++] = bucket[ii][jj++];
	}
}


int main() {
	int arr[] = { 21,3,30,44,15,36,6,10,9,19,25,48,5,23,47 };
	int len = sizeof(arr) / sizeof(int);
	printf("%-15s: ","Unsorted Array");
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
	bucketsort(arr, len);
	printf("%-15s: ", "Sorted Array");
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}