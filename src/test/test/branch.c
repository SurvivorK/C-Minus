int main() {
    int x1; int y1; int x2; int y2;
    int u1; int v1; int u2; int v2;
    int l1; int r1; int t1; int b1;
    int l2; int r2; int t2; int b2;
    x1 = read();
    y1 = read();
    x2 = read();
    y2 = read();
    u1 = read();
    v1 = read();
    u2 = read();
    v2 = read();
    if (x1 == x2 || y1 == y2 || u1 == u2 || v1 == v2) {
        print("%d", -1);
    } else {
        if (x1 < x2) {
            l1 = x1;
            r1 = x2;
        } else {
            l1 = x2;
            r1 = x1;
        }
        if (y1 < y2) {
            t1 = y2;
            b1 = y1;
        } else {
            t1 = y1;
            b1 = y2;
        }
        if (u1 < u2) {
            l2 = u1;
            r2 = u2;
        } else {
            l2 = u2;
            r2 = u1;
        }
        if (v1 < v2) {
            t2 = v2;
            b2 = v1;
        } else {
            t2 = v1;
            b2 = v2;
        }

        if (l2 >= r1 || r2 <= l1 || b2 >= t1 || t2 <= b1) {
            print("%d", 0);
        } else {
            print("%d", 1);
        }
    }
    return 0;
}
