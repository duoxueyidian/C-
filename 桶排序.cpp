#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//冒泡排序算法
void bubblesort(int* arr, int n) {
	if (n < 2) return;
	int ifswap;//每趟排序是否交换过元素，0-未交换，1-交换过
	int itmp;//交换元素时的中间变量
	//i是排序趟数计数器
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

//桶排序
void bucketsort(int* arr, unsigned int len) {
	int bucket[5][5];//分配5个桶
	int bucketsize[5];//每个桶元素个数计数器

	//初始化桶和桶计数器
	memset(bucket, 0, sizeof(bucket));
	memset(bucketsize, 0, sizeof(bucketsize));

	//把arr的数据放入桶中，再对每个桶冒泡排序
	for (int ii = 0; ii < len; ii++) bucket[arr[ii] / 10][bucketsize[arr[ii] / 10]++] = arr[ii];
	for (int jj = 0; jj < 5; jj++) bubblesort(bucket[jj], bucketsize[jj]);

	//把每个桶中的数据填充到arr中
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