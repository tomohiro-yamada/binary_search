#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
  int notLergerThanM = n;
  int j;
  for(int i = 0; i < n-1; i += j){
    int smallSum = A[i];
    int count = 0;
    for(j = 1; i + j < n && smallSum + A[i+j] <= m; j++){
       smallSum += A[i+j];
       count ++;
    }
    notLergerThanM -= count;
  }
  return notLergerThanM <= k;
}
    

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  int max = A[0];
  for(int q = 0; q < n; q++){
    if(max < A[q]){
      max = A[q];
    }
  }
  int sum = 0;
  for(int l = 0; l < n; l++){
    sum += A[l];
  }
  lb = max-1;
  ub = sum;
  while(ub - lb > 1){
    int mid = (ub +  lb) / 2;
    if(p(mid)){	
      ub = mid;
    }else{
      lb = mid;
    }
  }
    printf("%d\n", ub);
    return 0;
}
  
