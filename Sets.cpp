#include "Sets.h"
#include <iostream>


// === ARRAY ===

ArraySet::ArraySet()
{
    array[0] = '\0';
};

ArraySet::ArraySet(char* str)
{
    int i {0};
    for(; i < SET_POWER && str[i] != '\0'; ++i)
        array[i] = str[i];
    array[i] = '\0';
};

ArraySet ArraySet::operator & (const ArraySet& another) const
{
    ArraySet new_set{};

    for (int i = 0; array[i] != '\0'; i++)
        for(int j = 0; another.array[j] != '\0'; j++)
            if (array[i] == another.array[j])
                new_set.add(array[i]);

    return new_set;
};

ArraySet ArraySet::operator | (const ArraySet& another) const
{
    ArraySet new_set{};

    for (int i = 0; i < array[i] != '\0'; i++)
    {
        int j = 0;
        for(; another.array[j] != '\0'; j++)
            if (array[i] == another.array[j])
                break;
            if (another.array[j] == '\0')
                new_set.add(array[i]);

    }
    for (int i = 0; another.array[i] != '\0'; ++i)
    {
        new_set.add(another.array[i]);
    }

    return new_set;
};

void ArraySet::add(char element)
{

}

void ArraySet::remove(char element)
{
}

void ArraySet::show()
{
    std::cout << array << std::endl;
}


// === LIST ===
ListSet::ListSet() : head{nullptr}, tail{nullptr} {};

ListSet::ListSet(char* str) : head(nullptr), tail(nullptr)
{
    for(int i = 0; str[i] != '\0'; i++)
    {
        add(str[i]);
    }
};

ListSet::~ListSet()
{
    while(head)
    {
        auto fordel = head;
        head = head->next;
        delete fordel;
    };
};


ListSet ListSet::operator&(const ListSet& other_set) const
{
    ListSet new_set{};

    for (auto cur = head; cur; cur = cur->next)
    {
        for(auto cur2 = other_set.head; cur2; cur2 = cur2->next)
            if (cur->data == cur2->data)
                new_set.add(cur->data);
    }

    return new_set;
};

ListSet ListSet::operator|(const ListSet& other_set) const
{
    ListSet new_set{};

    for (auto cur = head; cur; cur = cur->next)
    {
        auto cur2 = other_set.head;
        for(; cur2; cur2 = cur2->next)
            if (cur->data == cur2->data)
                break;
            if (!cur2)
                new_set.add(cur->data);
    }
    for (auto cur2 = other_set.head; cur2; cur2 = cur2->next)
    {
        new_set.add(cur2->data);
    }

    return new_set;
};


void ListSet::add(char element)
{
    if (!get_Node(element))
    {
        if (tail)
        {
            tail->next = new Node{element, tail};
            tail = tail->next;
        }
        else
        {
            head = new Node{element, head};
            tail = head;
        }
    }
};

void ListSet::remove(char element)
{
};

void ListSet::show()
{
    for (auto i = head; i != nullptr; i = i->next)
        std::cout << i->data << " ";
    std::cout << std::endl;
}


ListSet::Node* ListSet::get_Node(char elem_data)
{
    for (auto i = head; i != nullptr; i = i->next)
    {
        if (elem_data == i->data)
            return i;
    }
    return nullptr;
};

// === BITS ===


BitSet::BitSet() : bit_array{0x0} {};

BitSet::BitSet(int i) : bit_array{i} {};


BitSet::BitSet(char* str)
{
    for (int i = 0; str[i] != '\0'; ++i)
        add(str[i]);
}

BitSet BitSet::operator&(const BitSet& another) const
{
    return bit_array & another.bit_array;
}

BitSet BitSet::operator|(const BitSet& another) const
{
    return bit_array | another.bit_array;
}

void BitSet::add(char ch)
{
    bit_array |= ctb(ch);
};

void BitSet::remove(char ch)
{
    bit_array &= ~ctb(ch);
};

int BitSet::ctb(char ch)
{
    int bytes = 0x0;

    if (ch >= '0' && ch <= '9')
        bytes = 0x1 << (ch - '0');
    else if (ch >= 'A' && ch <= 'F')
        bytes = 0x400 << (ch - 'A');
    else if (ch >= 'a' && ch <= 'f')
        bytes = 0x400 << (ch - 'a');

    return bytes;
}

const char* BitSet::bts(int bytes) const
{
    std::string str{};
    char cur_hex_digit {'0'};
    while (bytes)
    {
        if (cur_hex_digit == '9' + 1)
            cur_hex_digit = 'A';
        else if (cur_hex_digit == 'F' + 1)
            break;

        if (bytes & 0b1)
            str+=cur_hex_digit;

        cur_hex_digit++;
        bytes>>= 1;
    }

    return str.c_str();
};

void BitSet::show()
{
    std::cout << bts(bit_array) << std::endl;
}

std::ostream& operator << (std::ostream &os, const ArraySet& hs)
{
    return os << hs.array;
}

std::ostream& operator << (std::ostream &os, const ListSet& hs)
{
    for (auto i = hs.head; i != nullptr; i = i->next)
        os << i->data;
    return os;
}

std::ostream& operator << (std::ostream &os, const BitSet& hs)
{
    return os << hs.bts(hs.bit_array);
}
