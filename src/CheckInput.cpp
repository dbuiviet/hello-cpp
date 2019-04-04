#include <iostream>

double getDouble()
{
    while(true) //loop until valid input
    {
        std::cout << "Enter a double: ";
        double x;
        std::cin >> x;

        if(std::cin.fail())
        {
            std::cin.clear();   //put std::cin back to normal mode
            std::cin.ignore(32767, '\n');
            std::cout << "Oops, bad input. Please try again!" << std::endl;
        }
        else
        {
            std::cin.ignore(32767, '\n');   //remove any extra input until new line feed
            return x;
        }
        
    }
}

char getOperator()
{
    while(true)
    {
        std::cout << "Enter one of the following: +, -, * or /: ";
        char op;
        std::cin >> op;

        if(std::cin.fail())
        {
            std::cin.clear();   //put std::cin back to normal mode
            std::cin.ignore(32767, '\n');
            std::cout << "Oops, bad input. Please try again!" << std::endl;
        }
        else
        {
            std::cin.ignore(32767, '\n');
            if (op == '+' || op == '-' || op == '*' || op == '/')
                return op;
            else
            {
                std::cout << "Wrong operator entered. Please try again!" << std::endl;
            }
            
        }
        
    }
}


void printResult(double x, char op, double y)
{
    if (op == '+')
        std::cout << x << " + " << y << " = " << x + y << std::endl;
    else if (op == '-')
        std::cout << x << " - " << y << " = " << x - y << std::endl;
    else if (op == '*')
        std::cout << x << " * " << y << " = " << x * y << std::endl;
    else if (op == '/')
        std::cout << x << " / " << y << " = " << x / y << std::endl;
    else
    {
        /* code */
        std::cout << "Something went wrong, please check your inputs" << std::endl;
    }
    
}

// int main()
// {
//     double x = getDouble();
//     char op = getOperator();
//     double y = getDouble();

//     printResult(x, op, y);


//     return 0;
// }