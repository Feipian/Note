#include <stdio.h>
#include <stdlib.h>


int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main() {
    int kase;
    scanf("%d", &kase);
    while (kase--) {
        int n,mid;
        int ans=0;
        scanf("%d", &n);
        int* nums = (int*) malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
        qsort(nums, n, sizeof(int), cmpfunc);
        mid = nums[n/2];
        for (int i = 0; i < n; i++) 
            ans+=abs(nums[i]-mid);
        printf("%d\n",ans);
        free(nums);
    }
    return 0;
}

