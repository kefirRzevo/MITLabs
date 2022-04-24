#include <stdio.h>
#include <stdlib.h>


struct time
{
    size_t h;
    size_t min;
    size_t sec;
};

int main()
{
    char file_path[] = "Timur_and_Sasha.txt";
    FILE* fp = fopen(file_path, "r");
    FILE* ot = fopen("out.txt", "w");

    while(!feof(fp))
    {
        size_t freq = 0;
        size_t p    = 0;
        double P1 = 0;
        double P2 = 0;
        time t = {};
        fscanf(fp, "2022-04-04.%zu:%zu:%zu%*zu Hz%*zu W%lf mbar%lf mbar\n", &t.h, &t.min, &t.sec, &P1, &P2);
        fprintf(ot, "\t%zu\t%G\t%G\n", t.h * 3600 + t.min * 60 + t.sec - 10*3600 - 36*60 - 6, P1, P2);
    }
    return 0;
}