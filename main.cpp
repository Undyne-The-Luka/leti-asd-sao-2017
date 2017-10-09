#include <time.h>
#include <iostream>
#include "Sets.h"
#include "Logger.h"


char* set_gen();

int main(int argc, char **argv) {
    using namespace std;

    srand(time(NULL));

    char st_A [ArraySet::SET_POWER + 1] {"012"};
    char st_B [ArraySet::SET_POWER + 1] {"1356"};
    char st_C [ArraySet::SET_POWER + 1] {"2895"};
    char st_D [ArraySet::SET_POWER + 1] {"0126985"};

    ArraySet A {st_A};
    ArraySet B {st_B};
    ArraySet C {st_C};
    ArraySet D {st_D};
    ArraySet E {};

    cout << "Input: " << endl;
    cout << A << endl
    << B << endl
    << C << endl
    << D << endl;

    E = A | (B & C & D);

    cout << "Result: " << endl;
    cout << E << endl;

    char choice = 0;
    cout << "Generate, input from keyboard or run benchmark? (G\\K\\B) ";
    cin >> choice;

    if (choice == 'G' || choice == 'g') {
        A = set_gen();
        B = set_gen();
        C = set_gen();
        D = set_gen();
    }
    else if (choice == 'K' || choice == 'k') {
        cout << "Type hexadecimal numbers in one string, without duplicates." << endl;
        cout << "Set A: ";
        cin >> st_A;
        cout << "Set B: ";
        cin >> st_B;
        cout << "Set C: ";
        cin >> st_C;
        cout << "Set D: ";
        cin >> st_D;
    }
    else if (choice == 'B' || choice == 'b') {
        enum {REPEAT_NUM = 10000};

        ArraySet arr_A {st_A};
        ArraySet arr_B {st_B};
        ArraySet arr_C {st_C};
        ArraySet arr_D {st_D};
        ArraySet arr_E {};

        unsigned long start_time = clock();
        for (int z = 0; z < REPEAT_NUM; z++) {
            arr_E = arr_A | (arr_B & arr_C & arr_D);
        }
        unsigned long finish_time = clock();
        double arr_time = (finish_time - start_time)/* / static_cast<double>(REPEAT_NUM)*/;


        ListSet list_A {st_A};
        ListSet list_B {st_B};
        ListSet list_C {st_C};
        ListSet list_D {st_D};
        ListSet list_E {};

        start_time = clock();
        for (int z = 0; z < REPEAT_NUM; z++) {
            list_E = list_A | (list_B & list_C & list_D);
        }
        finish_time = clock();
        double list_time = (finish_time - start_time)/* / static_cast<double>(REPEAT_NUM)*/;


        BitSet bits_A {st_A};
        BitSet bits_B {st_B};
        BitSet bits_C {st_C};
        BitSet bits_D {st_D};
        BitSet bits_E {};

        start_time = clock();
        for (int z = 0; z < REPEAT_NUM; z++) {
            bits_E = bits_A | (bits_B & bits_C & bits_D);
        }
        finish_time = clock();
        double bits_time = (finish_time - start_time) /*/ static_cast<double>(REPEAT_NUM)*/;

        cout << "Array time: " << arr_time << endl;
        cout << "Lists clocks: " << list_time << endl;
        cout << "Bits clocks: " << bits_time << endl;
        return 0;
    }

    // ARRAYS
    ArraySet arr_A {st_A};
    ArraySet arr_B {st_B};
    ArraySet arr_C {st_C};
    ArraySet arr_D {st_D};
    ArraySet arr_E {arr_A | (arr_B & arr_C & arr_D)};

    cout << "Sets as arrays: " << endl;
    cout << "Input: " << endl;
    arr_A.show();
    arr_B.show();
    arr_C.show();
    arr_D.show();

    cout << "Result: " << endl;
    arr_E.show();

    // LIST
    ListSet list_A {st_A};
    ListSet list_B {st_B};
    ListSet list_C {st_C};
    ListSet list_D {st_D};
    ListSet list_E {list_A | (list_B & list_C & list_D)};

    cout << "Sets as lists: " << endl;
    cout << "Input: " << endl;
    list_A.show();
    list_B.show();
    list_C.show();
    list_D.show();

    cout << "Result: " << endl;
    list_E.show();

    // BIT ARRAY
    BitSet bits_A {st_A};
    BitSet bits_B {st_B};
    BitSet bits_C {st_C};
    BitSet bits_D {st_D};
    BitSet bits_E {bits_A | (bits_B & bits_C & bits_D)};

    cout << "Sets as bits: " << endl;
    cout << "Input: " << endl;
    bits_A.show();
    bits_B.show();
    bits_C.show();
    bits_D.show();

    cout << "Result: " << endl;
    bits_E.show();

    return 0;
}


char* set_gen()
{
    char* A = new char[ArraySet::SET_POWER + 1];
    char mask[] = "0123456789ABCDEF";
    int j = 0;
    for (int i = 0; i < 15; i++)
        if (rand() % 2 == 1)
            A[j++] = mask[i];
        A[j] = '\0';

    return A;
}
