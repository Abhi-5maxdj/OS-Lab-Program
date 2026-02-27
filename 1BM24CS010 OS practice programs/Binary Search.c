#include<stdio.h>
#include<stdlib.h>
void main(){
int a[10],n,p,m,h,l=0;
printf("Enter the number of elements");
scanf("%d",&n);
for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
}
printf("\nEnter the element to be found");
scanf("%d",&p);
h=n-1;
while(l<=h){
    m=(int)(l+h)/2;
    if(a[m]==p){
        printf("\nElement found");
        exit(0);
    }
    if(a[m]<p){
        h=m-1;
    }
    if(a[m]>p){
        l=m+1;
    }
}
printf("Element not found");
}
