#include <stdio.h>

int fibo (int n){
    if (n == 1 || n == 2){
        printf("1");
        return 1;
    }
    else {
        int ans1 = fibo (n-1);
        int ans2 = fibo (n-2);
        
    }
}

int main(){
    int n; 
    printf("Digite número:\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        fibo (n);
    }
    return 0;

}