#ifndef SETS_H
#define SETS_H

#include <iostream>
#include <bitset>

class ArraySet{
public:
    ArraySet();
    ArraySet(char*);
    ArraySet(const ArraySet&) = default;
    ArraySet(ArraySet&&) = default;
    ~ArraySet() = default;
    ArraySet& operator = (const ArraySet&) = default;
    ArraySet& operator = (ArraySet&&) = default;

    ArraySet operator & (const ArraySet&) const ;
    ArraySet operator | (const ArraySet&) const ;

    void add(char element);
    void remove(char element);
    void show();
private:
    friend std::ostream& operator << (std::ostream &os, const ArraySet& hs);

    enum {SET_POWER = 16};
    char array[SET_POWER + 1];
};

class ListSet{
public:
    ListSet();
    ListSet(char*);
    ListSet(const ListSet&) = default;
    ListSet(ListSet&&) = default;
    ~ListSet();
    ListSet& operator = (const ListSet&) = default;
    ListSet& operator = (ListSet&&) = default;

    ListSet operator & (const ListSet&) const;
    ListSet operator | (const ListSet&) const;

    void add(char elem);
    void remove(char elem);
    void show();
private:
    friend std::ostream& operator << (std::ostream &os, const ListSet& hs);

    struct Node {
        char data;
        Node* next;
        Node* prev;
    };
    Node* head;
    Node* tail;

    Node* get_Node(char);
};

class BitSet{
public:
    BitSet();
    BitSet(int);
    BitSet(char*);
    BitSet(const BitSet&) = default;
    BitSet(BitSet&&) = default;
    ~BitSet() = default;
    BitSet& operator = (const BitSet&) = default;
    BitSet& operator = (BitSet&&) = default;
    BitSet operator & (const BitSet&) const;
    BitSet operator | (const BitSet&) const;

    void add(char elem);
    void remove(char elem);
    void show();
private:
    int ctb(char);
    const char* bts(int bytes) const;
    friend std::ostream& operator << (std::ostream &os, const BitSet& hs);

    int bit_array;
};


#endif
