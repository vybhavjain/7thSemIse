#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
void merge(int* a, int l, int mid, int r)
{
int n1 = mid-l+1;
int n2 = r-mid;
int b[n1], c[n2];
int k = l;
int i,j;
for(i = 0; i<n1; i++)
b[i] = a[k++];
for(i = 0; i<n2; i++)
c[i] = a[k++];
k = l; 
i = 0;
j = 0;
while(i<n1 & j<n2)
{
if(b[i]<c[j])
{
a[k++] = b[i++];
}
else
{
a[k++] = c[j++];
}
}
while(i<n1)
a[k++] = b[i++];
while(j<n2)
a[k++] = c[j++];
}
void mergesort(int* a, int l, int r)
{
if(l<r)
{
int mid;
#pragma omp parallel sections
{
mid = (l+r)/2;
#pragma omp section
{
mergesort(a, l, mid);
}
#pragma omp section
{
mergesort(a, mid+1, r);
}
}
merge(a,l,mid,r);
} 
}
int main()
{
omp_set_nested(1);
int start=1;
int i,j,k;
printf("\n\nInput Size\t1\t2\t4\t8\t");
for(i = 0; i<4; i++)
{
int size = start*10;
start = size;
int a[size];
for(j = 0; j<size; j++)
{
a[j] = rand()%100000;
}
printf("\n\n%d\t",size);
for(k = 0; k<4; k++)
{
omp_set_num_threads(2*(k));
double t1 = omp_get_wtime();
mergesort(a,0,size-1);
double t2 = omp_get_wtime();
printf("%lf\t",t2-t1);
}
}
return 0;
}

