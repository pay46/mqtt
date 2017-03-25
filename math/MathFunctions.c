double power(double base, int exponent) {
    int ret = base;
    int i;

    if (exponent == 0)
        return 1;

    for (i = 1; i < exponent; i++) {
        ret = ret * base;
    }

    return ret;
}