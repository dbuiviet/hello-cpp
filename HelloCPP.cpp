#include <iostream>
#include "include/add.h"
#include "include/multiply.h"
#include "include/Account.h"
//#include <cstdint>
//#include "stdafx.h"
#include <bitset>
using namespace std;


//forward declaration or fuction prototype, declared in other file!
//int add(int x, int y);

int g_var(5); //global variable

void doPrint()
{
    cout << "We're in doPrint()" << endl;
}

int getValueFromUser()
{
    int x;
    cout << "Enter an integer: ";
    cin >> x;
    return x;
}

void doIt(int x)
{
    int y = 4;
    std::cout << "doIt: x = " << x << " y = " << y << std::endl;
    x = 3;
    std::cout << "doIt: x = " << x << " y = " << y << std::endl;
}

bool isEqual(int x, int y)
{
    return (x == y);
}

int powerInt(int base, int exp)
{
    int result = 1;

    while(exp)
    {
        if (exp & 1)
        {
            result *= base;
            
            //for debugging purpose
            //cout << (exp & 1) << endl;
        }
        
        exp >>= 1;
        base *= base;
    }

    return result;
}

// Note that with std::bitset, our options correspond to bit indices, not bit patterns
const int option0 = 0;
const int option1 = 1;
const int option2 = 2;
const int option3 = 3;
const int option4 = 4;
const int option5 = 5;
const int option6 = 6;
const int option7 = 7;

void incrementAndPrint()
{
    static int s_value(1);  //static duration via static keyword. This line is only executed once
    ++s_value;
    std::cout << s_value << "\n";

}

int main()
{
    /* code */

    cout << "Starting main()" << endl;

    cout << "Hello CPP" << endl;
    /*cout << "Enter a number:";
    int x;
    cin >> x;
    cout << "You just entered " << x << endl;
    */
    //doPrint();

    /*int x = getValueFromUser();
    int y = getValueFromUser();

    cout << "Sum of those is: " << x+y << endl;
    */

    //int8_t myint = 65;
    int16_t myint = 65;
    cout << myint << endl;

    cout << "Ending main()" << endl;

    int x = 1;
    int y = 2;
    std::cout << "main: x = " << x << " y = " << y << std::endl;
    doIt(x);
    std::cout << "main: x = " << x << " y = " << y << std::endl;

    cout << "The sum of 3 and 4 is: " << basicMath::add(3,4) << endl;
    cout << "The multiply of 3 and 4 is: " << basicMath::multiply(3,4) << endl;

    std::cout << "bool:\t\t" << sizeof(bool) << " bytes" << std::endl;
    std::cout << "char:\t\t" << sizeof(char) << " bytes" << std::endl;
    std::cout << "wchar_t:\t" << sizeof(wchar_t) << " bytes" << std::endl;
    std::cout << "char16_t:\t" << sizeof(char16_t) << " bytes" << std::endl; // C++11, may not be supported by your compiler
    std::cout << "char32_t:\t" << sizeof(char32_t) << " bytes" << std::endl; // C++11, may not be supported by your compiler
    std::cout << "short:\t\t" << sizeof(short) << " bytes" << std::endl;
    std::cout << "int:\t\t" << sizeof(int) << " bytes" << std::endl;
    std::cout << "long:\t\t" << sizeof(long) << " bytes" << std::endl;
    std::cout << "long long:\t" << sizeof(long long) << " bytes" << std::endl; // C++11, may not be supported by your compiler
    std::cout << "float:\t\t" << sizeof(float) << " bytes" << std::endl;
    std::cout << "double:\t\t" << sizeof(double) << " bytes" << std::endl;
    std::cout << "long double:\t" << sizeof(long double) << " bytes" << std::endl;


    int x1 = 7;
    int y1 = 4;
    std::cout << "int / int = " << x1 / y1 << "\n";
    std::cout << "double / int = " << static_cast<double>(x1) / y1 << "\n";
    std::cout << "int / double = " << x1 / static_cast<double>(y1) << "\n";
    std::cout << "double / double = " << static_cast<double>(x1) / static_cast<double>(y1) << "\n";
    //cout << "x1 % y1 = " << x1%y1 << endl;

    /*
    int count = 1;

    while (count <= 100)
    {
        cout << count << " ";

        if (count%20 == 0)
            cout << "\n";

        //count = count + 1;
        count++;
    }
    */

    std::cout << "Enter an integer: ";
    int a;
    std::cin >> a;
 
    std::cout << "Enter another integer: ";
    int b;
    std::cin >> b;

    /*if (isEqual(a,b))
    {
        std::cout << a << " and " << b << " are equal" << std::endl;    
    }
    else
        std::cout << a << " and " << b << " are not equal" << std::endl;
    */

    cout << a << " powered by " << b << " is: " << powerInt(a,b) << endl;

    std::bitset<8> bits(0x2); // we need 8 bits, start with bit pattern 0000 0010
    bits.set(option4); // set bit 4 to 1 (now we have 0001 0010)
    bits.flip(option5); // flip bit 5 (now we have 0011 0010)
    bits.reset(option5); // set bit 5 back to 0 (now we have 0001 0010)
 
    std::cout << "Bit 4 has value: " << bits.test(option4) << '\n';
    std::cout << "Bit 5 has value: " << bits.test(option5) << '\n';
    std::cout << "All the bits: " << bits << '\n';

    /*
        // Define a bunch of physical/emotional states
	const unsigned char isHungry = 1 << 0; // 0000 0001
	const unsigned char isSad = 1 << 1; // 0000 0010
	const unsigned char isMad = 1 << 2; // 0000 0100
	const unsigned char isHappy = 1 << 3; // 0000 1000
	const unsigned char isLaughing = 1 << 4; // 0001 0000
	const unsigned char isAsleep = 1 << 5; // 0010 0000
	const unsigned char isDead = 1 << 6; // 0100 0000
	const unsigned char isCrying = 1 << 7; // 1000 0000
 
	unsigned char me = 0; // all flags/options turned off to start
	me |= isHappy | isLaughing; // I am happy and laughing
	me &= ~isLaughing; // I am no longer laughing
 
	// Query a few states (we'll use static_cast<bool> to interpret the results as a boolean value rather than an integer)
	std::cout << "I am happy? " << static_cast<bool>(me & isHappy) << '\n';
	std::cout << "I am laughing? " << static_cast<bool>(me & isLaughing) << '\n';
    */

    const unsigned int lowMask = 0xF; // bit mask to keep low 4 bits (hex for 0000 0000 0000 1111)
 
    std::cout << "Enter an integer: ";
    int num;
    std::cin >> num;
 
    num &= lowMask; // remove the high bits to leave only the low bits
 
    std::cout << "The 4 low bits have value: " << num << '\n';


    const unsigned int redBits = 0xFF000000;
    const unsigned int greenBits = 0x00FF0000;
    const unsigned int blueBits = 0x0000FF00;
    const unsigned int alphaBits = 0x000000FF;
 
    std::cout << "Enter a 32-bit RGBA color value in hexadecimal (e.g. FF7F3300): ";
    unsigned int pixel;
    std::cin >> std::hex >> pixel; // std::hex allows us to read in a hex value
 
    // use bitwise AND to isolate red pixels, then right shift the value into the range 0-255
    unsigned char red = (pixel & redBits) >> 24;
    unsigned char green = (pixel & greenBits) >> 16;
    unsigned char blue = (pixel & blueBits) >> 8;
    unsigned char alpha = pixel & alphaBits;
 
    std::cout << "Your color contains:\n";
    std::cout << static_cast<int>(red) << " of 255 red\n";
    std::cout << static_cast<int>(green) << " of 255 green\n";
    std::cout << static_cast<int>(blue) << " of 255 blue\n";
    std::cout << static_cast<int>(alpha) << " of 255 alpha\n";

    int g_var = 10; //local variable, assigned value = 10
    g_var++; //increment local variable
    ::g_var--; //decrement global variable

    std::cout << "local variable: " << g_var << endl;
    std::cout << "global variable: " << ::g_var << endl;

    incrementAndPrint();
    incrementAndPrint();    //value of s_value is whatever we left it previously
    incrementAndPrint();

    Account account1{"Viet Dung", 1000};
    Account account2{"Tuong Phi", 100};

    cout << "account1: " << account1.getName() << " has balance of $" << account1.getBalance() << endl;
    cout << "account2: " << account2.getName() << " has balance of $" << account2.getBalance() << endl;

    cout << "Enter a deposit for " << account1.getName() << " : ";
    int depositAmount1(0);
    cin >> depositAmount1;
    cout << "Adding $" << depositAmount1 << " to " << account1.getName() << endl;
    account1.deposit(depositAmount1);

    cout << "Enter a deposit for " << account2.getName() << " : ";
    int depositAmount2(0);
    cin >> depositAmount2;
    cout << "Adding $" << depositAmount2 << " to " << account2.getName() << endl;
    account2.deposit(depositAmount2);

    cout << "account1: " << account1.getName() << " has balance of $" << account1.getBalance() << endl;
    cout << "account2: " << account2.getName() << " has balance of $" << account2.getBalance() << endl;

    return 0;
}

