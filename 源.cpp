#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int x, int y) { return x < y ? x : y; }

void MergeSort(int* arr, unsigned int n) {
    if (n < 2) return;
    int *aa = arr;//aa指向待排序数组
    int* bb = (int*)malloc(n * sizeof(int));//bb指向已排序的数组
    
    int iseg;//区间分段的计数器，1,2,4,8...
    int istart;//区间起始位置的计数器

    //排序趟数的循环
    for (iseg = 1; iseg < n; iseg *= 2) {
        //每趟排序选取区间的循环
        for (istart = 0; istart < n; istart += iseg * 2) {
            //把每个区间分成两部分，ilow是起始位置，imid是中间位置，imax是结束位置
            int ilow = istart;
            int imid = min(istart + iseg, n);
            int imax = min(istart + iseg * 2, n);

            int ii = ilow;//已排序数组的计数器
            int istart1 = ilow, iend1 = imid;
            int istart2 = imid, iend2 = imax;

            //把待排序左右两边数列合并到已排序数组
            while ((istart1 < iend1) && (istart2 < iend2))
                bb[ii++] = aa[istart1] < aa[istart2] ? aa[istart1++] : aa[istart2++];
            while (istart1 < iend1) bb[ii++] = aa[istart1++];
            while (istart2 < iend2) bb[ii++] = aa[istart2++];
        }
        //交换一下两个数组的指针，准备下一趟排序
        int* ptmp = aa; aa = bb; bb = ptmp;
    }
    //如果aa指向的不是原始数组的指针，把aa中的内容复制到arr中
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