
#include <stdio.h>

int main(){
    int years;
    char brand[10];
    printf("mete valores\n");
    scanf("%d", &years);
    printf("tenes %d years\n", years);
    printf("mete valores de nuevo\n");
    scanf("%s", &brand);
    printf("los nuevos valores %s", brand);
    return 0;
}
