#ifndef SETS_H
#define SETS_H

#include <iostream>
#include <bitset>

class ArraySet
{
public:
    ArraySet();
    ArraySet ( const char* );
    ArraySet ( const ArraySet& ) = default;
    ArraySet ( ArraySet&& ) = default;
    ~ArraySet() = default;
    ArraySet& operator = ( const ArraySet& ) = default;
    ArraySet& operator = ( ArraySet&& ) = default;
    ArraySet operator & ( const ArraySet& ) const ;
    ArraySet operator | ( const ArraySet& ) const ;
    bool operator == ( const ArraySet& ) const;
    bool operator == ( const char* ) const;

    void add ( char element );
    void remove ( char element );
    void show();

    std::string to_str() const;

    enum {SET_POWER = 16};
private:
    friend std::ostream& operator << ( std::ostream& os, const ArraySet& hs );

    char array[SET_POWER + 1];
};

class ListSet
{
public:
    ListSet();
    ListSet ( const char* );
    ListSet ( const ListSet& );
    ListSet ( ListSet&& );
    ~ListSet();
    ListSet& operator = ( const ListSet& );
    ListSet& operator = ( ListSet&& );
    ListSet operator & ( const ListSet& ) const;
    ListSet operator | ( const ListSet& ) const;
    bool operator == ( const ListSet& ) const;
    bool operator == ( const char* ) const;

    void add ( char elem );
    void remove ( char elem );
    void show();

    std::string to_str() const;
private:
    friend std::ostream& operator << ( std::ostream& os, const ListSet& hs );

    struct Node {
        Node(char e) : data{e}, next{nullptr} {};

        char data;
        Node* next;
    };
    Node* head;
    Node* tail;

    Node* get_Node ( char );
};

class BitSet
{
public:
    BitSet();
    BitSet ( int );
    BitSet ( const char* );
    BitSet ( const BitSet& ) = default;
    BitSet ( BitSet&& ) = default;
    ~BitSet() = default;
    BitSet& operator = ( const BitSet& ) = default;
    BitSet& operator = ( BitSet&& ) = default;
    BitSet operator & ( const BitSet& ) const;
    BitSet operator | ( const BitSet& ) const;
    bool operator == ( const BitSet& ) const;
    bool operator == ( const char* ) const;

    void add ( char elem );
    void remove ( char elem );
    void show();
    void showBits();

    std::string to_str() const;
private:
    int ctb ( char );
    std::string bts ( int bytes ) const;
    friend std::ostream& operator << ( std::ostream& os, const BitSet& hs );

    int bit_array;
};


#endif
