#include<stdio.h>
#include<omp.h>
#include<stdlib.h>

void merge(int a[] , int x1 , int y1 , int x2 , int y2)
{
    int p = x1, q = x2, k = 0, temp[1000], i, j;
    while(p <= y1 && q <= y2) {
        if(a[p] < a[q])
            temp[k++] = a[p++];
        else
            temp[k++] = a[q++];
    }

    while( p <= y1 )
        temp[k++] = a[p++];
    while( q <= y2 )
        temp[k++] = a[q++];
    for(i = x1 , j = 0; i <= y2; i++,j++ )
        a[i] = temp[j];
}

void mergesort(int a[],int p ,int q){
  int mid = 0;
  if(p < q){
      mid = (p + q)/2;
      #pragma omp parallel sections
      {
        #pragma omp section
        {
            printf("Process handing left recursion is %d\n",omp_get_thread_num());
            mergesort(a,p,mid);
        }
        #pragma omp section
        {
            printf("Process handing right recursion is %d\n",omp_get_thread_num());
            mergesort(a,mid+1,q);
        }
      }
    merge(a,p,mid,mid+1,q);
  }
}

int main(){
  int n = 0, i=0;
  printf("Enter the number of elements for sorting\n");
  scanf("%d",&n);

  int a[n];
  for(i = 0; i < n; i++ ){
    a[i] = rand()%100;
  }

  printf("Unsorted array is\n");
  for(i = 0; i < n; i++ ){
    printf("%d\n",a[i]);
  }

  mergesort(a,0,n-1);
  printf("Sorted array is\n");
  for(i = 0; i < n; i++ )
    printf("%d\n",a[i]);
  return 0;
}
