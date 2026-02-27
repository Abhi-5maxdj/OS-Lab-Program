#include <stdio.h>

int main() {
    int arr[10],n,p;
    printf("Enter the number of elements");
    scanf("%d",&n);
for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
}

int duplicateFound = 0;

for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
        if (arr[i] == arr[j]) {
            duplicateFound = 1;
            break;
        }
    }
    if (duplicateFound) {
        break;
    }
}

    if (duplicateFound) {
        printf("Array contains duplicates.\n");
    } else {
        printf("Array does not contain duplicates.\n");
    }

    return 0;
}
