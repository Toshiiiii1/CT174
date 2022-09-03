# include <stdio.h>
# include <time.h>

typedef int keytype;

typedef struct{
	keytype key;
}recordtype;

void printArray(recordtype a[], int n){
    int i;
    for (i=0; i < n; i++){
        printf("%d ", a[i].key);
    }
    printf("\n");
}

void readArray(recordtype a[], int n){
    int i, temp;
    for (i=0; i < n; i++){
        scanf("%d", &temp);
        a[i].key = temp;
    }
}

void merge(recordtype a[], recordtype leftArr[], recordtype rightArr[], int nLeftArr, int nRightArr){
    int i = 0, j = 0, k = 0;

    /* vua hop 2 mang thanh 1, vua sap 
    xep cac phan tu*/
    while (i < nLeftArr && j < nRightArr){
        if (leftArr[i].key < rightArr[j].key){
            a[k].key = leftArr[i].key;
            i++;
        }
        else{
            a[k].key = rightArr[j].key;
            j++;
        }
        k++;
    }

    /* dua cac phan tu con lai vao mang*/
    while (i < nLeftArr){
        a[k].key = leftArr[i].key;
        i++;
        k++;
    }
        
    while (j < nRightArr){
        a[k].key = rightArr[j].key;
        j++;
        k++;
    }
        
}

void mergeSort(recordtype a[], int start, int end){
    if (start < end){
        int mid = (start + end)/2, i = 0, j, k, nLeftArr = (mid - start)+1, nRightArr = end - mid;
        recordtype leftArr[nLeftArr], rightArr[nRightArr];
        
        // tach doi mang
        for (j=0; j < nLeftArr; j++){
            leftArr[j].key = a[i].key;
            i++;
        }
        for (k=0; k < nRightArr; k++){
            rightArr[k].key = a[i].key;
            i++;
        }

        // tach doi moi mang con
        mergeSort(leftArr, start, mid);
        mergeSort(rightArr, mid+1, end);
        
        // gom 2 mang da sap xep thanh 1 mang
        merge(a, leftArr, rightArr, nLeftArr, nRightArr);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    recordtype a[n];
    readArray(a, n);
    printArray(a, n);
    mergeSort(a, 0, n-1);
    printArray(a, n);
	return 0;
}