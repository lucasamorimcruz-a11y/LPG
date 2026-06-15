#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
void forma_direta (){
    int var2 = 123;
    cout << var2 << '\n';
}
void forma_indireta (){
    int var2;
    int *var1 = &var2;
    *var1 = 123;
    cout << *var1 << '\n';
}
void forma_indireta_ponteiro_pra_ponteiro(){
    int var2;
    int *var1 = &var2;
    int **var3 = &var1;
    **var3 = 123;
    cout << **var3 << '\n';
}
int main(){
    forma_direta();
    forma_indireta();
    forma_indireta_ponteiro_pra_ponteiro();
    return 0;
}