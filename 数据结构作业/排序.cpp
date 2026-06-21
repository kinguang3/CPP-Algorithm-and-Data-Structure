#include <bits/stdc++.h>
using namespace std;

// ============================================
// 题1：单链表简单选择排序
// ============================================
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

void SelectionSort(LinkList &L) {
    LNode *p = L->next;
    while (p != NULL) {
        LNode *minNode = p;
        LNode *q = p->next;
        while (q != NULL) {
            if (q->data < minNode->data) {
                minNode = q;
            }
            q = q->next;
        }
        swap(p->data, minNode->data);
        p = p->next;
    }
}

// ============================================
// 题2：双向冒泡排序（鸡尾酒排序）
// ============================================
void CocktailSort(int arr[], int n) {
    int left = 0, right = n - 1;
    int lastSwap;
    while (left < right) {
        lastSwap = left;
        for (int i = left; i < right; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                lastSwap = i;
            }
        }
        right = lastSwap;
        
        for (int i = right; i > left; i--) {
            if (arr[i] < arr[i - 1]) {
                swap(arr[i], arr[i - 1]);
                lastSwap = i;
            }
        }
        left = lastSwap;
    }
}

// ============================================
// 题3：三颜色石子重排（荷兰国旗问题）
// ============================================
void DutchFlagSort(char stones[], int n) {
    int red = 0, white = 0, blue = n - 1;
    while (white <= blue) {
        if (stones[white] == 'R') {
            swap(stones[red], stones[white]);
            red++;
            white++;
        } else if (stones[white] == 'W') {
            white++;
        } else {
            swap(stones[white], stones[blue]);
            blue--;
        }
    }
}

// ============================================
// 题4：正负值重排
// 要求：负数在前，非负数在后，至多使用一个辅助空间，O(n)时间
// ============================================
void RearrangeSign(int arr[], int n) {
    int i = 0, j = n - 1;
    while (i < j) {
        while (i < j && arr[i] < 0) i++;
        while (i < j && arr[j] >= 0) j--;
        if (i < j) swap(arr[i], arr[j]);
    }
}

// ============================================
// 题5：快速排序思想查找关键字
// 在无序数组中查找关键字等于key的记录
// ============================================
int QuickSearch(int arr[], int low, int high, int key) {
    if (low > high) return -1;
    
    int pivot = arr[low];
    int i = low, j = high;
    
    while (i < j) {
        while (i < j && arr[j] >= pivot) j--;
        arr[i] = arr[j];
        while (i < j && arr[i] <= pivot) i++;
        arr[j] = arr[i];
    }
    arr[i] = pivot;
    
    if (arr[i] == key) return i;
    else if (key < arr[i]) return QuickSearch(arr, low, i - 1, key);
    else return QuickSearch(arr, i + 1, high, key);
}

// ============================================
// 题6：计数排序
// ①顺序表定义 ②算法实现 ③比较次数 ④与简单选择排序比较
// ============================================

#define MAXSIZE 100

typedef struct {
    int key;
} Record;

typedef struct {
    Record r[MAXSIZE + 1];
    int length;
} SqList;

void CountSort(SqList &L) {
    int minKey = L.r[1].key, maxKey = L.r[1].key;
    for (int i = 2; i <= L.length; i++) {
        if (L.r[i].key < minKey) minKey = L.r[i].key;
        if (L.r[i].key > maxKey) maxKey = L.r[i].key;
    }
    
    int range = maxKey - minKey + 1;
    int *count = new int[range]();
    
    for (int i = 1; i <= L.length; i++) {
        count[L.r[i].key - minKey]++;
    }
    
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }
    
    Record *temp = new Record[L.length + 1];
    for (int i = L.length; i >= 1; i--) {
        temp[count[L.r[i].key - minKey]] = L.r[i];
        count[L.r[i].key - minKey]--;
    }
    
    for (int i = 1; i <= L.length; i++) {
        L.r[i] = temp[i];
    }
    
    delete[] count;
    delete[] temp;
}

// 简单选择排序（用于比较）
void SimpleSelectionSort(SqList &L) {
    for (int i = 1; i < L.length; i++) {
        int minIdx = i;
        for (int j = i + 1; j <= L.length; j++) {
            if (L.r[j].key < L.r[minIdx].key) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            swap(L.r[i], L.r[minIdx]);
        }
    }
}
