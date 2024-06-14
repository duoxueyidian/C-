#include <stdio.h>
#include <stdlib.h>

//冒泡排序
void bubblesort1(int* arr, int n) {
	if (n < 2) return;
	int itmp;
//i是排序趟数计数器
	for (int i = n-1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				itmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = itmp;
			}

		}
	}
}

//排序算法优化
void bubblesort11(int* arr, int n) {
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

//递归实现冒泡排序
void bubblesort2(int* arr, unsigned int n) {
	if (n < 2) return;
	int tempt;//用来交换两个元素
	int ifswap;//判断每趟排序是否交换过元素，0-未交换，1-交换过
	for (int ii = 0; ii < n - 1; ii++) {
		ifswap = 0;//排序前初始化一下
		if (arr[ii] > arr[ii + 1]) {
			tempt = arr[ii + 1];
			arr[ii + 1] = arr[ii];
			arr[ii] = tempt;
			ifswap = 1;//说明已经交换过
		}
	}
	if (ifswap == 0) return;
	bubblesort2(arr, --n);
}


int main() {
	int arr[15] = { 44,3,38,5,47,15,36,26,27,2,46,4,19,50,49 };
	bubblesort2(arr, 15);
	for (int i = 0; i < 15; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
} 