#include<stdio.h>

int main(int argc, char *argv[])                //argc means how many arguments been put in
                                                //argv save a array with all arguments
{
    // initialize variables
    char buff[255];
    FILE *fp;
    // read file
    fp = fopen(argv[1], "r");
    while( (fgets(buff, 255, fp)) != NULL)
        printf("%s\n", buff);
    return 0;
}
