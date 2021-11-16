#include <iostream>
using namespace std;

int getBit(int num, int pos)
{
    return ((num & (1 << pos)) != 0);
}

int setBit(int num, int pos)
{
    return (num | (1 << pos));
}

int clearBit(int num, int pos)
{
    int mask = ~(1 << pos);
    return (num & mask);
}

int updateBit(int num, int pos, int value)
{
    int mask = ~(1 << pos);
    num = (num & mask);
    return num | (value << pos);
}

int main()
{
    cout << "Bit Manipulation: " << endl;

    int pos = 1;
    int num = 5;
    cout << "Bit at pos: " << pos << " of " << num << " is " << getBit(num, pos) << endl;

    cout << "Bit at pos: " << pos << " of " << num << " is "
         << "set now, New number is " << setBit(num, pos) << endl;

    cout << "Bit at pos: " << pos << " of " << num << " is "
         << "cleared now, New number is " << clearBit(num, pos) << endl;

    int value = 1;
    cout << "Bit at pos: " << pos << " of " << num << " is "
         << "updated to " << value << ", New value is: " << updateBit(num, pos, value) << endl;

    return 0;
}
