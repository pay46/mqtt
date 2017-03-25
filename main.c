#include <stdio.h>
#include <stdlib.h>
#include "config.h"


#ifdef USE_MYMATH
#include "math/MathFunctions.h"
#else
#include <math.h>
#endif

int main(int argc, char **argv) {

    if (argc < 3) {
        printf("Usage: %s base exponent \n", argv[0]);
        return 1;
    }

    double base = atof(argv[1]);
    int exponent = atoi(argv[2]);

#ifdef USE_MYMATH
    printf("使用了我们的数学函数\n");
    double result = power(base, exponent);
#else
    printf("使用了c标准的数学函数\n");
    double result = pow(base, exponent);
#endif
    
    printf("%g ^ %d = %g\n", base, exponent, result);

    return 0;
}
