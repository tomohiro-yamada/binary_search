#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
  int sum = 0;
  for(int i = 0; i < n; i++){
  int x = A[i] / m;
  sum += x;
  }
  return sum >= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = A[0];
  for(int j = 0; j < n; j++){
    if (A[j] > ub){ 
      ub = A[j];
    }
  }
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(p(mid)) {
      lb = mid;
    }else{
      ub = mid;
    }
  }
  printf("%d\n", lb);
  return 0;
}