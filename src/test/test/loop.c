int main() {
    int k;
    int line; int cnt;
    int m; int n;
    int numtor; int denomtor;
    numtor = 1;
    denomtor = 1;
    k = read();

    if (k <= 0) {
        print("%d", -1);
        return 0;
    }

    while (cnt < k) {
        line = line + 1;
        cnt = cnt + line;
    }
    m = k - (cnt - line);
    n = line;
    print("%d", n);
    print("%d", m);

    cnt = 0;
    while (cnt < m) {
        numtor = numtor * n;
        n = n - 1;
        cnt = cnt + 1;
    }
    while(m > 0) {
        denomtor = denomtor * m;
        m = m - 1;
    }
    print("%d", numtor / denomtor);
    return 0;
}
