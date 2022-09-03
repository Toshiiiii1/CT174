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

void selectionSort(recordtype a[], int n){
	int i, j, lowindex;
	keytype lowkey;
	for (i=0; i <= n-2; i++){
		lowkey = a[i].key;
		lowindex = i;
		for (j=i+1; j <= n-1; j++){
			if (a[j].key < lowkey){
				lowkey = a[j].key;
				lowindex = j;
			}
		}

		swap(&a[i], &a[lowindex]);
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
    selectionSort(a, n);
    printArray(a, n);
	return 0;
}