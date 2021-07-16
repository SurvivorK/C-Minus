int main() {
    int i;
    int j;
    int k;
    int result;
    i = 1; j = 11; k = 39;
    result = 0;
    i = (-i) + k + (-(17 * i));
    print("%d", i);
    j = 11 * j - (k + i * i) * i;
    print("%d", j);
    k = i * (i / j) + k;
    print("%d", k);
    result = 4 * i + j / 17 + i * k;
    print("%d", result);
    return 0;
}
