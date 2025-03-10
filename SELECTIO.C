#include<stdio.h>
#include<conio.h>

int main() {
    int arr[8];
    int i, j, minIndex, temp;
    clrscr();

    printf("Enter the elements in array : ");
    for(i=0;i<6;i++)
    {
	scanf("%d",&arr[i]);
    }
    printf("Original array: \n");
    for (i = 0; i < 6; i++) {
	printf("%d ", arr[i]);
    }
    printf("\n");

    for(i=0;i<6-1;i++)
    {
	minIndex = i;
	for(j=i+1;j<6;j++)
	{
	    if(arr[j]<arr[minIndex])
	    {
		minIndex = j;
	    }
	}
	if(i!=minIndex)
	{
	    temp = arr[i];
	    arr[i] = arr[minIndex];
	    arr[minIndex]=temp;
	}
    }

    printf("Sorted array: \n");
    for (i = 0; i < 6; i++) {
	printf("%d ", arr[i]);
    }
    printf("\n");
    getch();
    return 0;
}
