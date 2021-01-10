#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<time.h>
#include<math.h>
#include<float.h>

#define K 4

int num_threads;
long num_points,cluster_count[K];
long datapoints[100][2];
int cluster[K][2]={{75,25},{25,25},{25,75},{75,75}};

void populate_points(){
    long i;
    #pragma omp parallel
    for(i=0;i<num_points;i++){
        datapoints[i][0]=rand()%100;
        datapoints[i][1]=rand()%100;
        printf("%ld\t%ld\n",datapoints[i][0],datapoints[i][1]);
    }
    for(i=0;i<4;i++)
        cluster_count[i]=0;
}

double get_distance(int x1, int y1, int x2, int y2) {
    int dx=x2-x1,dy=y2-y1;
    return ((double)sqrt(dx*dx+dy*dy));
}

void classify_points() {
    long i; int j, cluster_index; double cur_dist=0, min_dist=999;
    #pragma omp parallel for private(cluster_index, j , i, cur_dist, min_dist)
    for(i=0;i<num_points;i++){
        cluster_index=-1;
        cur_dist=0,min_dist=999;
        for(j=0;j<K;j++){
            cur_dist=get_distance(datapoints[i][0],datapoints[i][1],cluster[j][0],cluster[j][1]);
            if(cur_dist<min_dist){
                min_dist=cur_dist;
                cluster_index=j;    
            }
        }
  printf("%ld %ld belongs to %d %d \n", datapoints[i][0],datapoints[i][1],cluster[cluster_index][0],cluster[cluster_index][1]);
                cluster_count[cluster_index]++;
        
    }
}

void main(){
    printf("Max threads:%d\n",omp_get_max_threads());
    printf("Enter number of points:");
    scanf("%ld",&num_points);
    populate_points();
    double t1=omp_get_wtime();
    classify_points();
    double t2=omp_get_wtime();
    printf("Time taken %lf\n",t2-t1);
    int i=0;
    printf("Counts\n");
    while(i<4)
        printf("%d->%ld\n",i,cluster_count[i++]);
}

