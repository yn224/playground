#include <iostream>
using namespace std;

int main( void ) {
    int* a = (int*) malloc( 8 * sizeof(int) );
    int* b = (int*) malloc( 8 * sizeof(int) );
    for ( int i = 0; i < 8; i++ ) {
        a[i] = (i % 2 == 0) ? 1 : 2;
        b[i] = (i % 2 == 0) ? 2 : 1;
    }

    for ( int i = 0; i < 8; i++ ) {
        cout << a[i] << " ";
    }
    cout << endl;
    for ( int i = 0; i < 8; i++ ) {
        cout << b[i] << " ";
    }
    cout << endl;

    int res = 0;
    for ( int i = 0; i < 8; i++ ) {
        res += a[i] * b[i];
    }
    cout << "res: " << res << endl;

    free(a);
    free(b);
    return 0;
}