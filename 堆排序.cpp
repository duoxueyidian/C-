#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) { int temp = *b; *b = *a; *a = temp; }

//采用循环实现heapify(元素下沉)
//arr-待排序数组的地址，start-待heapify节点的下标，end-待排序数组最后一个元素的下标
void heapify(int *arr,int start,int end) {
    //确定父节点和左子节点的数组下标
    int dad = start;
    int son = dad * 2 + 1;

    //如果子节点的下标没有超出范围，循环继续
    while (son <= end) {
        //先比较两子节点大小，选择最大的
        if ((son + 1 <= end) && (arr[son] < arr[son + 1])) son++;
        //如果父节点大于子节点代表调整完毕，直接跳出函数
        if (arr[dad] > arr[son]) return;
        //否则交换父子内容再继续子节点和孙节点比较
        swap(&arr[dad], &arr[son]);
        dad = son;
        son = dad * 2 + 1;
    }
}

//用递归实现heapify
void Heapify(int* arr, int start, int end) {
    int dad = start;
    int son = dad * 2 + 1;
    if (son > end) return;
    if ((son + 1 <= end) && arr[son] < arr[son + 1]) son++;
    if (arr[dad] < arr[son]) return;
    swap(&arr[dad], &arr[son]);
    Heapify(arr, son, end);
}

void HeapSort(int *arr, int len) {
    int ii;
    //初始化堆，从最后一个父节点开始调整
    for (ii = (len - 1) / 2; ii >= 0; ii--) heapify(arr, ii, len - 1);
    //把第一个元素和堆最后一个元素交换，然后重新调整，直到排序完毕
    for (ii = len - 1; ii > 0; ii--) {
        swap(&arr[0], &arr[ii]);
        heapify(arr, 0, ii - 1);
    }
}

int main() {
    int arr[15] = { 44, 3, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 49 };
    HeapSort(arr, 15);
    printf("Sorted array: ");
    for (int i = 0; i < 15; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}