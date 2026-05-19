#include<stdio.h>

typedef enum{
    Red,
    Yellow,
    Green
} Light;

int main(){
    Light current = Red;

    switch (current) {
        case Red:
            printf("Stop");
        break;

        case Yellow:
            printf("Ready");
        break;

        case Green:
            printf("Go");
        break;

        default: 
            printf("Invalid");
    }

    return 0;
}