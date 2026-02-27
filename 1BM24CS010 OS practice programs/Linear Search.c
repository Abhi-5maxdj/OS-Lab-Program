#include<stdio.h>
#include<stdlib.h>
void main(){
int a[10],n,p;
printf("Enter the number of elements");
scanf("%d",&n);
for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
}
printf("\nEnter the element to be found");
scanf("%d",&p);
for(int i=0;i<n;i++){
    if(a[i]==n){
        printf("\nElement found");
        exit(0);
    }
}
printf("Element not found ");
}
