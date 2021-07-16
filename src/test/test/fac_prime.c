int fact(int m) {
    if (m <= 0) {
        return 1;
    } else {
        return fact(m - 1) * m;
    }
}

int isqrt(int n) {
    int i;
    i = 0;
    while (i < n) {
        if (i * i <= n && (i + 1) * (i + 1) > n) {
            return i;
        }
        i = i + 1;
    }
    return -1;
}

int mod(int k1, int k2) {
    if (k1 < 0 || k2 <= 0) {
        return -1;
    } else {
        return k1 - k1 / k2 * k2;
    }
}

int is_prime(int l) {
    int j; int end;
    j = 2;
    end = isqrt(l);
    while (j <= end) {
        if (mod(l, j) == 0) {
            return 0;
        }
        j = j + 1;
    }
    return 1;
}

int main() {
    int c; int d;
    c = 2;
    d = read();
    while (c < fact(d)) {
        if (is_prime(c)) {
            print("%d", c);
        }
        c = c + 1;
    }
    return 0;
}
