#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) { int temp = *b; *b = *a; *a = temp; }

//����ѭ��ʵ��heapify(Ԫ���³�)
//arr-����������ĵ�ַ��start-��heapify�ڵ���±꣬end-�������������һ��Ԫ�ص��±�
void heapify(int *arr,int start,int end) {
    //ȷ�����ڵ�����ӽڵ�������±�
    int dad = start;
    int son = dad * 2 + 1;

    //����ӽڵ���±�û�г�����Χ��ѭ������
    while (son <= end) {
        //�ȱȽ����ӽڵ��С��ѡ������
        if ((son + 1 <= end) && (arr[son] < arr[son + 1])) son++;
        //������ڵ�����ӽڵ���������ϣ�ֱ����������
        if (arr[dad] > arr[son]) return;
        //���򽻻����������ټ����ӽڵ����ڵ�Ƚ�
        swap(&arr[dad], &arr[son]);
        dad = son;
        son = dad * 2 + 1;
    }
}

//�õݹ�ʵ��heapify
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
    //��ʼ���ѣ������һ�����ڵ㿪ʼ����
    for (ii = (len - 1) / 2; ii >= 0; ii--) heapify(arr, ii, len - 1);
    //�ѵ�һ��Ԫ�غͶ����һ��Ԫ�ؽ�����Ȼ�����µ�����ֱ���������
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