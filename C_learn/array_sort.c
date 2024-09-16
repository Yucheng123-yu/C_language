#include<stdio.h>

int array[] = {3,1,4,9,1,5,2,6,9};
int size = sizeof(array)/sizeof(array[0]);

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void print_array(int array[],int low,int high)
{
    for(int i=low;i<high;i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
}
void subsort(int array[],int low,int high) 
{
    if(low<high){// high = i-1的时候，确保high>=0，否则low = 0,high=-1,死循环
        int pref = low;
        int i = low + 1;
        int j = low + 1;
        while(j<=high){
            if(array[j]<array[pref])
            {
                swap(array,i,j);
                print_array(array, low, high);
                i++;
            }
            j++;
        }
        swap(array,low,i-1);
        printf("a---");
        print_array(array, low, high);
        subsort(array,low,i-2);
        subsort(array,i,high);
    }
    
}

int main()
{
    
    print_array(array, 0 , size);
    // swap(array,1,5);
    // print_array(array,size);
    subsort(array,0,size-1);// high访问越界
    print_array(array, 0, size);
    return 0;
}