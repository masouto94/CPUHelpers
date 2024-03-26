
#include <stdio.h>

int main(){
    int years;
    char brand;
    printf("mete valores\n");
    scanf("%d", &years);
    fflush(stdin);
    printf("tenes %d years\n", years);
    printf("mete valores de nuevo\n");
    scanf("%c", &brand);
    fflush(stdin);
    printf("los nuevos valores %c", brand);
    printf("mete valores de nuevo\n");
    scanf("%c", &brand);
    fflush(stdin);
    printf("los nuevos valores %c", brand);
    return 0;
}
