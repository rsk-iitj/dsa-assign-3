#include<stdio.h>


#define HEAP_CAPACITY 100

void create_array(int size_array,int inp_array[])
{
	int data;
	for(int i=0;i<size_array;i++)
	{
		//printf("/n Enter the integer value for %d position-:",i);
		scanf(" %d",&data);
		inp_array[i]=data;
	}
}

int returnParent(int i) {

 	return (i-1)/2;

}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}


int leftNode(int i) {
    return (2*i + 1);
}

int rightNode(int i) {
    return (2*i + 2);
}



void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
       printf("%d ",arr[i]);
    printf("\n");
}

void heapify(int heap[],int heap_size,int i)
{
    int largest = i;
    int l = leftNode(i);
    int r = rightNode(i);

    if(l < heap_size && heap[l] > heap[largest] )
       largest=l;
    if(r < heap_size && heap[r]>heap[largest])
       largest=r;
    if(largest != i)
    {
        swap(&heap[i], &heap[largest]);
        heapify(heap,heap_size,largest);
    }
}
void buildHeap(int arr[], int n)
{
    int startIdx = (n / 2) - 1;
    for (int i = startIdx; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

void heapSort(int arr[], int array_len)
{

    buildHeap(arr,array_len);
    for (int i = array_len - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]); 
        heapify(arr, i, 0);
    }
}


int main(int argc, char const *argv[])
{
	/* code */
	int size_array;
	scanf("%d",&size_array);
	int inp_array[size_array];
	create_array(size_array,inp_array);
	heapSort(inp_array,size_array);
    printArray(inp_array,size_array);

}

