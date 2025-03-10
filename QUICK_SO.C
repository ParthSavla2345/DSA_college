#include <stdio.h>
#include <conio.h>


int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    int j, temp;

    for (j = low; j <= high - 1; j++) {
	if (arr[j] <= pivot) {
	    i++;

	    temp = arr[i];
	    arr[i] = arr[j];
	    arr[j] = temp;
	}
    }

    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}


void quickSort(int arr[], int low, int high) {
    int pi;
    if (low < high) {
	pi = partition(arr, low, high);

	quickSort(arr, low, pi - 1);
	quickSort(arr, pi + 1, high);
    }
}


void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
	printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[8];
    int n, i;

    clrscr();


    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: \n", n);
    for (i = 0; i < n; i++) {
	scanf("%d", &arr[i]);
    }

    printf("Original array: \n");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);


    printf("Sorted array: \n");
    printArray(arr, n);

    getch();
    return 0;
}
