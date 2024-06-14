#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int x, int y) { return x < y ? x : y; }

void MergeSort(int* arr, unsigned int n) {
    if (n < 2) return;
    int *aa = arr;//aaָ�����������
    int* bb = (int*)malloc(n * sizeof(int));//bbָ�������������
    
    int iseg;//����ֶεļ�������1,2,4,8...
    int istart;//������ʼλ�õļ�����

    //����������ѭ��
    for (iseg = 1; iseg < n; iseg *= 2) {
        //ÿ������ѡȡ�����ѭ��
        for (istart = 0; istart < n; istart += iseg * 2) {
            //��ÿ������ֳ������֣�ilow����ʼλ�ã�imid���м�λ�ã�imax�ǽ���λ��
            int ilow = istart;
            int imid = min(istart + iseg, n);
            int imax = min(istart + iseg * 2, n);

            int ii = ilow;//����������ļ�����
            int istart1 = ilow, iend1 = imid;
            int istart2 = imid, iend2 = imax;

            //�Ѵ����������������кϲ�������������
            while ((istart1 < iend1) && (istart2 < iend2))
                bb[ii++] = aa[istart1] < aa[istart2] ? aa[istart1++] : aa[istart2++];
            while (istart1 < iend1) bb[ii++] = aa[istart1++];
            while (istart2 < iend2) bb[ii++] = aa[istart2++];
        }
        //����һ�����������ָ�룬׼����һ������
        int* ptmp = aa; aa = bb; bb = ptmp;
    }
    //���aaָ��Ĳ���ԭʼ�����ָ�룬��aa�е����ݸ��Ƶ�arr��
    if (aa != arr) {
        memcpy(arr, aa, n * sizeof(int));
        bb = aa;
    }
    free(bb);
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