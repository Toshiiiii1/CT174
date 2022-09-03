# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>

typedef int keytype;

typedef float othertype;

typedef struct{
	keytype key;
	othertype otherfields;
}recordtype;

void swap(recordtype *x, recordtype *y){
	recordtype temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int findPivot(recordtype a[], int start, int end){
	keytype firstkey = a[start].key;
	int k = start+1;
	while (k <= end && (a[k].key == firstkey)){
		k++;
	}

	if (k > end)
		return -1;
	else if (a[k].key > firstkey)
		return k;
	else
		return start;
}

int partition(recordtype a[], int start, int end, keytype pivot){
	int L = start, R = end;

	while (L < R){
		while (a[L].key < pivot){
			L++;
		}
		while (a[R].key >= pivot){
			R--;
		}

		if (L < R){
			swap(&a[L], &a[R]);
		}
	}

	return L;
}

void quickSort(recordtype a[], int start, int end){
	keytype pivot;
	int pivotIndex, k;
	pivotIndex = findPivot(a, start, end);
	
	if (pivotIndex != -1){
		pivot = a[pivotIndex].key;
		k = partition(a, start, end, pivot);
		quickSort(a, start, k-1);
		quickSort(a, k, end);
	}
}

void readArray(recordtype a[], int n){
    int i, temp;
    for (i=0; i < n; i++){
        scanf("%d", &temp);
        a[i].key = temp;
    }
}

void printArray(recordtype a[], int n){
    int i;
    for (i=0; i < n; i++){
        printf("%d ", a[i].key);
    }
    printf("\n");
}

int main(){
    int n;
    scanf("%d", &n);
    recordtype a[n];
    readArray(a, n);
    printArray(a, n);
    quickSort(a, 0, n-1);
    printArray(a, n);
	return 0;
}