//
// Created by wcy on 6/22/21.
//
int mod(int i, int j) {
    return i - i / j * j;
}

int quick_power_mod(int x, int y, int k) {
    int res; res = 1;
    if (x <= 0 || y <= 0 || k <= 0) {
        return -1;
    } else {
        x = mod(x, k);
        while (y != 0) {
            if (mod(y, 2) == 1) {
                res = mod(res * x, k);
            }
            y = y / 2;
            x = mod(x * x, k);
        }
        return res;
    }
}
int main() {
    int a; int b; int c; int cnt;
    a = read();
    b = read();
    c = read();
    print("%d", quick_power_mod(a, b, c));
    return 0;
}