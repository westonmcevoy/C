# include <assert.h>
# include <stdlib.h>

void swap(int* a, int* b, int* c) {
    assert (a != NULL);
    assert (b != NULL);
    assert (c != NULL);
    int t = *c;
    *c = *b;
    *b = *a;
    *a = t;
}

int main() {
    int x = 0, y = 1, z = 2;
    swap(&x, &y, &z);
    assert (x == 2);
    assert (y == 0);
    assert (z == 1);
    return 0;
}