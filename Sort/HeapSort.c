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

void pushDown(recordtype a[], int first, int last){
    // Min Heap
    int r = first;
    while (r <= (last-1)/2){
        if (last == 2*r+1){
            if (a[r].key > a[last].key)
                swap(&a[r], &a[last]);
            r = last;    
        }
        
        else if ((a[r].key > a[2*r+1].key) && (a[2*r+1].key <= a[2*r+2].key)){
            swap(&a[r], &a[2*r+1]);
            r = 2*r+1;
        }

        else if ((a[r].key > a[2*r+2].key) && (a[2*r+1].key > a[2*r+2].key)){
            swap(&a[r], &a[2*r+2]);
            r = 2*r+2;
        }
        
        else
            r = last;

    }
}

void heapSort(recordtype a[], int n){
    int i;
    for (i = (n-2)/2; i >= 0; i--){
        pushDown(a, i, n-1);
    }
    for (i = n-1; i >= 2; i--){
        swap(&a[0], &a[i]);
        pushDown(a, 0, i-1);
    }
    swap(&a[0], &a[1]);
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
    heapSort(a, n);
    printArray(a, n);
	return 0;
}