#include <stdio.h>
#include <stdlib.h>

int selection(int *arr, int i, int j){
   if(i >  j){
     return 0;

   }
   int min =i ;
   int k=i;
  while(k<=j){
     if(*(arr+k) <*(arr+min)){
        min = k;
     }
     k++;


  }
   int temp=*(arr+i);
   *(arr+i)=*(arr+min);
    *(arr + min)=temp;

  
return selection(arr, i+1,j);


}




int main(){
  printf("Enter the Number of elements u wanna enter");
  int n;
  scanf("%d",&n);
  int *arr=(int *)malloc(n*sizeof(int));
  for(int i=0; i< n;i++){
    scanf("%d",(arr +i));
  }  
  selection( arr , 0,n-1 );
printf("Sorted array:\n");
int *p = arr;
for(int i = 0; i < n; i++) {
    printf("%d ", *(p + i));
}



    return 0;
}