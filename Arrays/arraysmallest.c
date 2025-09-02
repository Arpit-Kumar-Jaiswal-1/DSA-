#include <stdio.h>
#include <stdlib.h>
int mini(int *arr, int n){
  int *prr=arr;
  int min = *prr;
  for(int i=1;i<n;i++){
       if(*(prr+i) < min){
            min = *(prr + i);
       }

  }




    return min;
}
int main(){
    printf("Enter the size of arr u wanna enter ");
    int n;
    scanf("%d",&n);
    int *arr=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",(arr+i));
    }
    int m=mini(arr,n);

 printf("Minimum element is %d",m);

free(arr);



    return 0;
}