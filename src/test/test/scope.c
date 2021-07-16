int a; int b;
int func(int a, int b) {
    print("func a = %d, b = %d", a, b);
    if (a > b) {
        int b; b = a;
        print("func: b = %d", b);
    }
    else {
        int a; a = b;
        print("func: a = %d", a);
    }
    print("exit func : %d %d", a, b);
}
int main() {
    a = read(); b = read();
    print("main read: %d %d", a, b);
    if (a < b) {
        int b; b = a;
        print("main: min b = %d", b);
    }
    else {
        int a; a = b;
        print("main : min a = %d", a);
    }
    func(a, b);
    print("exit main :%d %d", a, b);
}