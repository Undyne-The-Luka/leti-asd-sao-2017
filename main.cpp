#include <iostream>
#include "Sets.h"

int main(int argc, char **argv) {
    using namespace std;

    cout << "=== === ===" << endl;
    cout << "Sets as linked lists: " << endl;

    ListSet<char> sA{A};
    ListSet<char> sB{B};
    ListSet<char> sC{C};
    ListSet<char> sD{D};
    cout << "Input: " << endl;
    sA.show();
    sB.show();
    sC.show();
    sD.show();

    ListSet<char> sE = sA.unite_with(sB.cross_with(sC).cross_with(sD));
    cout << "Result: " << endl;
    sE.show();

    cout << "=== === ===" << endl;
    cout << "Sets as binary arrays: " << endl;

    HexSet setA{A};
    HexSet setB{B};
    HexSet setC{C};
    HexSet setD{D};
    cout << "Input: " << endl;
    cout << setA << endl
    << setB << endl
    << setC << endl
    << setD << endl;

    HexSet setE{setA | (setB & setC & setD)};
    cout << "Result: " << endl << setE << endl;

    return 0;
}
