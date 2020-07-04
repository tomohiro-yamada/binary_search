#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
  int notLergerThanM = n;
  for(int j = 0; j < n-1; j++){
    if(A[j] + A[j+1] <= m){
      A[j+1] = A[j+1] + A[j];
      notLergerThanM --;
    }
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
  if(max > sum / k){
    lb = max;
  }else{
    lb = sum / k;
  }
  ub = sum;
  while(ub - lb > 1){
    int mid = (ub +  lb) / 2;
    if(p(mid)){	
      ub = mid;
    }else{
      lb = mid;
    }
  }
  if(p(lb)){
    printf("%d\n", lb);
  }else{
    printf("%d\n", ub);
  }
  return 0;
}
  