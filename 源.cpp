#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//arr-待排数组首地址，arrtmp-用于排序的临时数组的首地址
//start-待排区间第一个元素位置，end-待排区间的最后一个元素位置
void _mergesort(int* arr, int* arrtmp, int start, int end) {
    //如果区间元素少于2，递归终止
    if (start >= end) return;
    int mid = start + (end - start) / 2;//计算排序区间的中间位置

    int istart1 = start, iend1 = mid;//左区间的起始位置
    int istart2 = mid + 1, iend2 = end;//右区间的起始位置

    _mergesort(arr, arrtmp, istart1, iend1);//左区间递归
    _mergesort(arr, arrtmp, istart2, iend2);//右区间递归

    int ii = start;//arrtmp计数器
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
    _mergesort(arr, arrtmp, 0, n - 1);//调用递归函数进行排序
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