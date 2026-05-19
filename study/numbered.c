#include <stdio.h>

typedef enum {
    Low = 10,
    Medium = 20,
    High = 30,
    Other
} Priority;

int main(){
    Priority n1 = Low;
    Priority n2 = Medium;
    Priority n3 = High;
    Priority n4 = Other;

    printf("Integer value for Low is %d\n",n1);
    printf("Integer value for Medium is %d\n",n2);
    printf("Integer value for High is %d\n",n3);
    printf("Integer value for Other is %d\n",n4);

    return 0;
}