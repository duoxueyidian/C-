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
	int* result = (int*)malloc(len * sizeof(int));//存放桶中收集数据的临时数组
	if (result == NULL) {
		printf("内容分配失败！\n");
		exit(EXIT_FAILURE);
	}
	int buckets[BUCKETS_COUNT] = { 0 };//初始化10个桶

	//遍历arr，将数据出现的次数储存在buckets中
	for (ii = 0; ii < len; ii++) buckets[(arr[ii] / exp) % 10]++;
	
	//调整buckets各元素的值，调整后的值就是arr中元素在result的位置
	for (ii = 1; ii < 10; ii++) buckets[ii] += buckets[ii - 1];

	//将arr中的元素填充到result中
	for (ii = len - 1; ii >= 0; ii--) {
		result[buckets[(arr[ii] / exp) % 10] - 1] = arr[ii];
		buckets[(arr[ii] / exp) % 10]--;
	}

	//将排序好的数组复制到arr中
	memcpy(arr, result, len * sizeof(int));
	free(result);
}

void radixsort(int* arr, unsigned int len) {
	if (len < 2) return;
	int imax = arrmax(arr, len);
	int exp;//排序指数，iexp=1:按个位排序，iexp=10:按十位排序...
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