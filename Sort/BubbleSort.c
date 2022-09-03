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

void bubbleSort(recordtype a[], int n){
	int i, j;
	for (i = n-1; i >=1; i--){
		for (j=0; j < i; j++){
			if (a[j].key > a[j+1].key){
				swap(&a[j], &a[j+1]);
			}
		}
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
    bubbleSort(a, n);
    printArray(a, n);
	return 0;
}