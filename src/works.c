#include <stdio.h>

int n;
int k;
int A[100000];
int B[100000];

int p(int m){
  int notLergerThanM = n;
  for(int j = 0; j < n; j++){
    B[j] = A[j];
  }
  for(int i = 0; i < n-1; i++){
    if(B[i] + B[i+1] <= m){
      B[i+1] = B[i+1] + B[i];
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
  lb = max;
  ub = sum + 1;
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
    return 0;
  }else{
    printf("%d\n", ub);
    return 0;
  }
}
  