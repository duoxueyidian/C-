#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//arr-���������׵�ַ��arrtmp-�����������ʱ������׵�ַ
//start-���������һ��Ԫ��λ�ã�end-������������һ��Ԫ��λ��
void _mergesort(int* arr, int* arrtmp, int start, int end) {
    //�������Ԫ������2���ݹ���ֹ
    if (start >= end) return;
    int mid = start + (end - start) / 2;//��������������м�λ��

    int istart1 = start, iend1 = mid;//���������ʼλ��
    int istart2 = mid + 1, iend2 = end;//���������ʼλ��

    _mergesort(arr, arrtmp, istart1, iend1);//������ݹ�
    _mergesort(arr, arrtmp, istart2, iend2);//������ݹ�

    int ii = start;//arrtmp������
    while (istart1 <= iend1 && istart2 <= iend2)
        arrtmp[ii++] = arr[istart1] < arr[istart2] ? arr[istart1++] : arr[istart2++];
    while (istart1 <= iend1)
        arrtmp[ii++] = arr[istart1++];
    while (istart2 <= iend2)
        arrtmp[ii++] = arr[istart2++];
    memcpy(arr + start, arrtmp + start, (end - start + 1) * sizeof(int));
}

void MergeSort(int* arr, unsigned int n) {
    if (n < 2) return;
    int *arrtmp=(int*)malloc(n*sizeof(int));
    _mergesort(arr, arrtmp, 0, n - 1);//���õݹ麯����������
    free(arrtmp);
}

int main() {
    int arr[15] = { 44, 3, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 49 };
    MergeSort(arr, 15);
    printf("Sorted array: ");
    for (int i = 0; i < 15; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}