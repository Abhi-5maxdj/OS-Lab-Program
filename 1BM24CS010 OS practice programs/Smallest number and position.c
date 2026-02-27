#include<stdio.h>
#include<stdlib.h>
void main(){
int a[10],n,p;
printf("Enter the number of elements");
scanf("%d",&n);
for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
}
int s=a[0];
for(int i=1;i<n;i++){
    if(s>a[i]){
        s=a[i];
    }
}
for(int i=0;i<n;i++){
    if(s==a[i]){
        printf("Element %d found at position %d",s,p);
        exit(0);
    }
}
}
