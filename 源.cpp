#include <stdio.h>
#include <stdlib.h>

//ð������
void bubblesort1(int* arr, int n) {
	if (n < 2) return;
	int itmp;
//i����������������
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

//�����㷨�Ż�
void bubblesort11(int* arr, int n) {
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

//�ݹ�ʵ��ð������
void bubblesort2(int* arr, unsigned int n) {
	if (n < 2) return;
	int tempt;//������������Ԫ��
	int ifswap;//�ж�ÿ�������Ƿ񽻻���Ԫ�أ�0-δ������1-������
	for (int ii = 0; ii < n - 1; ii++) {
		ifswap = 0;//����ǰ��ʼ��һ��
		if (arr[ii] > arr[ii + 1]) {
			tempt = arr[ii + 1];
			arr[ii + 1] = arr[ii];
			arr[ii] = tempt;
			ifswap = 1;//˵���Ѿ�������
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