#include <iostream>
#include <string>
#include "../include/add.h"
#include "../include/multiply.h"
#include "../include/Account.h"
//#include <cstdint>
//#include "stdafx.h"
#include <bitset>
#include <cstdlib> //needed for exit(), std::srand() and rand()
#include <ctime>    //for std::time()
#include <iterator>
#include <array>
#include <algorithm>    //for std::sort
using namespace std;

#include "../include/plog/Log.h"   //include the logger header


//forward declaration or fuction prototype, declared in other file!
//int add(int x, int y);

int g_var(5); //global variable

void doPrint()
{
    cout << "We're in doPrint()" << endl;
}

int getValueFromUser()
{
    LOGD << "getValueFromUser() called";
    //input validation
    while(true)
    {
        int x;
        cout << "Enter an integer: ";
        cin >> x;

        //check for failed extraction
        if(std::cin.fail())
        {
            std::cin.clear();   //clear 'extraction' buffer
            std::cin.ignore(32767,'\n');    //remove any extraneous input
            std::cout << "Oops, that input is invalid.  Please try again.\n";
        }
        else
        {
            std::cin.ignore(32767,'\n');
            return x;
        }
    }
    
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

// Define a new enumeration named Color
enum Color
{
    // Here are the enumerators
    // These define all the possible values this type can hold
    // Each enumerator is separated by a comma, not a semicolon
    COLOR_BLACK, //assigned to 0
    COLOR_RED,  //assigned to 1
    COLOR_BLUE, //assigned to 2
    COLOR_GREEN, //assigned to 3
    COLOR_WHITE, //assigned to 4
    COLOR_CYAN, //assigned to 5
    COLOR_YELLOW, //assigned to 6
    COLOR_MAGENTA  //assigned to 7
}; // however the enum itself must end with a semicolon

//to make enumaration specific typed
enum class Fruit
{
    BANANA,
    APPLE,
    ORANGE
};

void printColor(Color color)
{
    /*
    if (color == COLOR_BLACK)
        std::cout << "Black in enum Color is assigned to " << color << endl;
      
    else if (color == COLOR_RED)
        std::cout << "Red in enum Color is assigned to " << color << endl;
       
    else if (color == COLOR_BLUE)
        std::cout << "Blue in enum Color is assigned to " << color << endl;
         
    else if (color == COLOR_GREEN)
        std::cout << "Green in enum Color is assigned to " << color << endl;
    
    else if (color == COLOR_WHITE)
        std::cout << "White in enum Color is assigned to " << color << endl;
        
    else if (color == COLOR_CYAN)
        std::cout << "Cyan in enum Color is assigned to " << color << endl;

    else if (color == COLOR_YELLOW)
        std::cout << "Yellow in enum Color is assigned to " << color << endl;

    else if (color == COLOR_MAGENTA)
        std::cout << "Magenta in enum Color is assigned to " << color << endl;
         
    else
        std::cout << "Who knows!";
    */

    switch(color)
    {
        case COLOR_BLACK:
            std::cout << "Black in enum Color is assigned to " << color << endl;

        case COLOR_RED:
            std::cout << "Red in enum Color is assigned to " << color << endl;

        case COLOR_BLUE:
            std::cout << "Blue in enum Color is assigned to " << color << endl;

        case COLOR_GREEN:
            std::cout << "Green in enum Color is assigned to " << color << endl;

        case COLOR_WHITE:// Do whatever here
            std::cout << "White in enum Color is assigned to " << color << endl;

        case COLOR_CYAN:
            std::cout << "Cyan in enum Color is assigned to " << color << endl;

        case COLOR_YELLOW:
            std::cout << "Yellow in enum Color is assigned to " << color << endl;

        case COLOR_MAGENTA:
            std::cout << "Magenta in enum Color is assigned to " << color << endl;

        default:
            std::cout << "Who knows!";
    }
}

struct Employee
{
        /* data */
    string name;
    short id;
    int age;
    double wage;
};

//nested struc
struct Company
{
    Employee CEO;
    int numberOfEmployees;
};

void printEmployeeInfo(Employee employee)
{
    std::cout << "Name:   " << employee.name << "\n";
    std::cout << "ID:   " << employee.id << "\n";
    std::cout << "Age:  " << employee.age << "\n";
    std::cout << "Wage: " << employee.wage << "\n";
}

enum class ErrorCode
{
    ERROR_SUCCESS = 0,
    ERROR_NEGATIVE_NUMBER = -1
};

ErrorCode checkValue(int value)
{
    // if value is a negative number
    if (value < 0)
       // early return an error code
        return ErrorCode::ERROR_NEGATIVE_NUMBER;
 
    //value = powerInt(value, 2); //square up value
 
    return ErrorCode::ERROR_SUCCESS;
}

//assuming (max-min) <= RAND_MAX
int getRandomNumber(int min, int max)
{
    std::cerr << "getRandomNumber() called" << endl;
    static const double fraction = 1.0 / (RAND_MAX + 1.0);  // static used for efficiency, so we only calculate this value once
    // evenly distribute the random number across our range
    return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}

namespace Animal
{
    enum AnimalNames
    {
        CHICKEN,
        DOG,
        CAT,
        ELEPHANT,
        DUCK,
        SNAKE,
        MAX_ANIMALS
    };
    
}; // Animal

// Note: You need to specify the array size in the function declaration
// to pass reference as variable to function
void printElements(int (&arr)[4])
{
  int length{ sizeof(arr) / sizeof(arr[0]) }; // we can now do this since the array won't decay
  
  for (int i{ 0 }; i < length; ++i)
  {
    std::cout << arr[i] << std::endl;
  }
}

//main() starting..
int main()
{
    plog::init(plog::debug,"Logfile.txt"); //initialize the logger and write output to Logfile.txt
    LOGD << "The main() called";
    /* code */
    //std::srand(5323);   //set initial seed value to 5323
    std::srand(static_cast<unsigned int>(std::time(nullptr)));  //set initial seed value to time value of clock

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

    /*
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
    */

    Color paint(COLOR_WHITE);    
    printColor(paint);

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

    //cout << "account1: " << account1.getName() << " has balance of $" << account1.getBalance() << endl;
    //cout << "account2: " << account2.getName() << " has balance of $" << account2.getBalance() << endl;
    account1.displayAccount();
    account2.displayAccount();    
    
    cout << "Enter a deposit for " << account1.getName() << " : ";    
    long depositAmount1(0);
    cin >> depositAmount1;   
    cout << "Adding $" << depositAmount1 << " to " << account1.getName() << endl;
    account1.deposit(depositAmount1);
    
    cout << "Enter a deposit for " << account2.getName() << " : ";    
    long depositAmount2(0);
    cin >> depositAmount2;
    cout << "Adding $" << depositAmount2 << " to " << account2.getName() << endl;
    account2.deposit(depositAmount2);    

    //cout << "account1: " << account1.getName() << " has balance of $" << account1.getBalance() << endl;
    //cout << "account2: " << account2.getName() << " has balance of $" << account2.getBalance() << endl;
    account1.displayAccount();
    account2.displayAccount();

    Account newAccount{"",0};
    cout << "Initial name for new account: " << newAccount.getName() << endl;
    std::cin.ignore(32767, '\n'); //it's a way to ignore new line '\n'!!!
    std::cout << "Enter name for new account: ";
    std::string theName;
    std::getline(std::cin, theName);    
    newAccount.setName(theName);
    cout << "New account name has " << theName.length() << " characters" << endl;
    cout << "Enter deposit for " << newAccount.getName() << " : ";
    long depositAmount3(0);
    cin >> depositAmount3;
    newAccount.deposit(depositAmount3);
    cout << "Adding $" << depositAmount3 << " to " << newAccount.getName() << endl;
    newAccount.displayAccount();

    Fruit myFavFruit = Fruit::BANANA;
    if (myFavFruit == Fruit::BANANA)
        cout << "Good choice! Banana is good for health" << endl;
    else
    {
        cout << "Orange and Apple are good too!" << endl;
    }

    //typedef is meaningful for code maintenance (making complex types simple) and platform independent
    typedef int testScore_t;
    //then we can use descriptive name of typedef to declare function type and return value
    //in C++11 compatible, we can use another way of type alias
    using gradeScore_t = double;    //clearer to remember    
   

    //struct initilization
    Employee Joe{"Joe", 1, 32, 5000.0};
    Employee Jack{"Jack", 2, 30};

    Jack.wage += 4500;

    if (Joe.wage > Jack.wage)
        cout << "Joe makes more than Jack" << endl;
    
    //today is Joe's birthday
    ++Joe.age;

    printEmployeeInfo(Joe);
    printEmployeeInfo(Jack);

    Company myCompany{{"David", 0, 40, 60000.0}, 3};
    cout << "The CEO info: " << endl;
    printEmployeeInfo(myCompany.CEO);
    cout << "My company has " << myCompany.numberOfEmployees << " employess" << endl;

    //exit(0);
    std::cout << "Enter a positive number: ";
    int posNum;
    std::cin >> posNum;
 
    while (checkValue(posNum) == ErrorCode::ERROR_NEGATIVE_NUMBER)
    {
        std::cout << "You entered a negative number! Please re-enter a positive number: ";
        std::cin >> posNum;
    }

    /*
    //statement label
    tryAgain:
        std::cout << "Oops, You entered a negative number! Please re-enter a positive, non-zero number: ";
        std::cin >> posNum;

    if (posNum <= 0)
        goto tryAgain; //avoid goto statement because of 'spaghetti code'
    */
    
    std::cout << "The square value of " << posNum << " is: " << powerInt(posNum,2) << endl;

    /*
    int outer = 1;
    while (outer <= 5)
    {
        // loop between 1 and outer
        int inner = 5;
        while (inner >= outer)
        {
            std::cout << inner << " ";
            --inner;
        }
 
        // print a newline at the end of each row
        std::cout << "\n";
        ++outer;
    }
    */

    int outer = 1;
    while (outer <= 5)
    {
        int inner = 5;
        while ((inner - outer) > 0)
        {
            std::cout << " " << " ";            
            --inner;
        }

        while (inner >= 1)
        {
            std::cout << inner << " ";
            --inner;
        }
            
            
        // print a newline at the end of each row
        std::cout << "\n";
        ++outer;
    }

     // selection must be declared outside do/while loop, otherwise it will be
     //destroyed after the 'do' block ends
    int selection;
 
    do
    {
        std::cout << "Please make a selection: \n";
        std::cout << "1) Addition\n";
        std::cout << "2) Subtraction\n";
        std::cout << "3) Multiplication\n";
        std::cout << "4) Division\n";
        std::cin >> selection;
    }
    while (selection != 1 && selection != 2 &&
        selection != 3 && selection != 4);
 
    // do something with selection here
    // such as a switch statement
 
    std::cout << "You selected option #" << selection << "\n";

    // Print 100 random numbers
    /*
    for (int count=1; count <= 100; ++count)
    {
        //range from 0 to RAND_MAX
        std::cout << std::rand() << "\t";
 
        // If we've printed 5 numbers, start a new row
        if (count % 5 == 0)
            std::cout << "\n";
	}
    */

    std::cout << "Let's roll a dice!\n";    
    std::cout << "Your rolled number is: " << getRandomNumber(1,6) << endl;

    int animalArray[Animal::AnimalNames::MAX_ANIMALS] = {2,4,4,4,2,0};

    std::cout << "A elephant has " << animalArray[Animal::AnimalNames::ELEPHANT] << " legs" << endl;
    std::cout << "A duck has " << animalArray[Animal::AnimalNames::DUCK] << " legs" << endl;
    std::cout << "A snake has " << animalArray[Animal::AnimalNames::SNAKE] << " legs" << endl;

    //int scores[] = { 84, 92, 76, 81, 56 };
    std::array<int,5> scores = {84, 92, 76, 81, 56};
    //const int numStudents = std::size(scores); // requires C++17 and <iterator> header
    //const int numStudents = sizeof(scores)/sizeof(scores[0]);
    const int numStudents = scores.size();    

    int totalScore = 0;
    for (int student = 0; student < numStudents; student++)
        totalScore += scores[student];

    double avgScore = static_cast<double>(totalScore) /numStudents;
    std::cout << "The average score of the class is: " << avgScore << endl;

    int value = 5;
    std::cout << value << '\n'; // print the value of variable x
    std::cout << &value << '\n'; // print the memory address of variable x
    std::cout << *&value << '\n'; /// print the value at the memory address of variable x

    int *ptr = &value; // initialize ptr with address of variable value
    std::cout << &value << '\n'; // print the address of variable value
    std::cout << ptr << '\n'; // print the address that ptr is holding

    std::cout << sizeof(ptr) << endl;
    std::cout << sizeof(*ptr) << endl;

    int arr[]{ 99, 20, 14, 80 };
    
    printElements(arr);

    std::array<int,5> myArray = {9, 5, 7, 1, 3};
    std::sort(myArray.begin(), myArray.end());  //sort forward
    //std::sort(myArray.rend(), myArray.rbegin()); //sort backward

    for (const auto &element : myArray)
    {
        std::cout << element << ' ';
    }

    std::vector<int> vArray = {0, 1, 2};
    vArray.resize(5);   //set new size to 5
    for (const auto &element : vArray)
    {
        std::cout << element << ' ';    // print 0, 1, 2, 0, 0
    }

    std::vector<bool> bArray = {true, false, true, false, true};
    for (const auto &element : bArray)
    {
        std::cout << element << ' ';    // print 1, 0, 1, 0, 1
    }
    
    return 0;
}

