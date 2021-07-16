int f() {
    return g();
}
int g() {
    return f();
}
int main() {
    f();
    g();
}