#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int one = INT_MAX;
    float two = FLT_MAX;
    double three = DBL_MAX;

    printf("Integer:\t%d bytes,\tmaximum is\t%d\n", sizeof(int), one);
    printf("Float:\t%d bytes,\tmaximum is\t%f\n", sizeof(float), two);
    printf("Double:\t%d bytes,\tmaximum is\t%f\n", sizeof(double), three);


    return 0;
}
