#include <stdio.h>

typedef enum{
    OK = 0,
    FileNotFound = 1,
    AccessDenied = 2
} ErrorCode;

int main(){
    ErrorCode code = AccessDenied;

    switch(code){
        case OK:
            printf("Created successfully/Response Ok");
        break;

        case FileNotFound:
            printf("Trying to access a file which is not there");
        break;

        case AccessDenied:
            printf("Tried to access a file with no permissions");
        break;

        default:
            printf("Invalide error code!");
    }

    return 0;
}