#include <stdio.h>
#include <stdlib.h>
int multiply(int **prr,int rows, int cols){
    int **k =(int **)malloc(rows*(sizeof(int* )));
    for(int i=0;i<rows;i++){
        k[i]=(int *)malloc(cols*sizeof(int));
  }

    
for(int i=0; i< rows ;i++){
    for(int j=0; j< cols;j++){
         for(int k=0;;i++)
    }
    
}
    

 


    return **prr;
}




int main(){
printf("Enter the number of rows and colums u wanna Enter \n");
int rows;
int cols;
scanf("%d",&rows);
scanf("%d",&cols);
int **arr=(int **)malloc(rows*(sizeof(int**)));
if(arr=NULL){
    printf("Memopry Allocation failed \n");
    return 1;
}
for(int i=0;i<rows;i++){
   arr[i]=(int *)malloc(cols*(sizeof(int)));
   if(arr[i]==NULL){
    printf("Memory Allocation  failed \n");
    return 1;

   }
   
}
printf("Enter the elements in the array \n");
for(int i=0;i<rows;i++){
    for(int j=0; j< cols;j++){
        scanf("%d",&arr[i][j]);
    }
}
printf("Matrix is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }


for(int i=0;i<rows;i++){
    free(arr[i]);
}

free(arr);





    return 0;
}