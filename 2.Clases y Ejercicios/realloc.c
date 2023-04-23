#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (void) 
{
    char *ptr;
    ptr = (char*) malloc(10);
    strcpy(ptr, "Programando");
    printf(" %s\n", ptr);
    ptr = (char *) realloc(ptr, 20);
    strcat(ptr, " en C");
    printf(" %s\n", ptr);
    free(ptr);
    return 0;
}

/*
int main(void) 
{
    int * ptr;
    ptr = malloc(100);
    if (ptr == NULL) 
    {
        printf("No se pudo obtener la memoria solicitada.");
        exit(0);
    }

    ptr = realloc(ptr,500);
    if(ptr != NULL)
       printf("Se pudo obtener la memoria solicitada.\n");
    return 0;
}
*/