#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib> // Include for system()

using namespace std;

class Register
{
private:
    string name;
    string email;
    string phoneNum;
    string Password;

public:
    void signUp()
    {
        cout << "\tName\n";
        getline(cin, name);

        cout << "\tEmail\n";
        getline(cin, email);

        cout << "\tPhone Number\n";
        getline(cin, phoneNum);

        cout << "\tPassword\n";
        getline(cin, Password);
    }

    // Public getter for email, password, phone number and name
    const string getEmail() const
    {
        return email;
    }

    const string getPassword() const
    {
        return Password;
    }

    const string getName() const
    {
        return name;
    }

    const string getPhoneNum() const
    {
        return phoneNum;
    }
};

void insertData(const Register &user)
{
    ofstream outFile("userData.csv", ios::app); // Open file in append mode
    if (!outFile.is_open())
    {
        cout << "Error opening file." << endl;
        return;
    }

    // Check if file is empty to add header
    if (outFile.tellp() == 0)
    {
        outFile << "Name,Email,Phone Number,Password" << endl;
    }

    // Write data to the file in CSV format
    outFile << user.getName() << "," << user.getEmail() << "," << user.getPhoneNum() << "," << user.getPassword() << endl;

    outFile.close(); // Close the file
}

bool login(const string &email, const string &password)
{
    ifstream inFile("userData.csv");
    if (!inFile.is_open())
    {
        cout << "Error opening file." << endl;
        return false;
    }

    string line;
    getline(inFile, line); // Skip the header line
    while (getline(inFile, line))
    {
        stringstream ss(line);
        string storedName, storedEmail, storedPhoneNum, storedPassword;
        getline(ss, storedName, ',');
        getline(ss, storedEmail, ',');
        getline(ss, storedPhoneNum, ',');
        getline(ss, storedPassword);

        if (storedEmail == email && storedPassword == password)
        {
            cout << "\nLogin Successful!\n"
                 << endl;
            inFile.close();
            return true;
        }
    }

    cout << "Login Failed. Incorrect email or password." << endl;
    inFile.close();
    return false;
}

float Add(float x, float y)
{
    return x + y;
}

float subtract(float x, float y)
{
    return x - y;
}

float multiply(float x, float y)
{
    return x * y;
}

float divide(float x, float y)
{
    return x / y;
}

int factorial(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
    }
    return fact;
}

double power(double base, int exponent)
{
    return pow(base, exponent);
}

double squareRoot(int num)
{
    return sqrt(num);
}

int main()
{
    cout << "1. New User\n2. Existing User" << endl;
    char choice;
    cin >> choice;
    cin.ignore(); // Clear the input buffer

    if (choice == '1')
    {
        char signupChoice;
        cout << "Do you want to SignUP(Yes = 'y' or 'Y' & No = 'n' or 'N')" << endl;
        cin >> signupChoice;
        cin.ignore(); // Clear the input buffer

        if (signupChoice == 'y' || signupChoice == 'Y')
        {
            Register useRegister;
            useRegister.signUp();
            insertData(useRegister);

// Clear the screen after signup
#ifdef _WIN32
            system("cls");
#endif
        }
        else
        {
            cout << "Exiting..." << endl;
            return 0;
        }
    }
    else if (choice == '2')
    {
        string email, password;
        cout << "\tEmail\n";
        cin >> email;

        cout << "\tPassword\n";
        cin >> password;

        if (!login(email, password))
            return 0; // Exit if login fails
    }
    else
    {
        cout << "Invalid choice. Exiting..." << endl;
        return 0;
    }

    // User logged in, now execute the calculator
    float num1, num2;
    char check[2];
    char opr;
    do
    {
        {
            cout << "Enter the operation to perform: \nAdd = '+'\nSubtract = '-'\nMultiply = '*'\nDivide = '/'\nFactorial = 'f'\nExponential = 'e'\nSquare Root = 'r'\n";
            cin >> opr;
            cin.ignore(); // Ignore newline character left in input buffer
            if (opr == '+')
            {
                cout << "Enter first number: ";
                cin >> num1;
                cout << "Enter second number: ";
                cin >> num2;
                float result = Add(num1, num2);
                cout << "Sum of " << num1 << " & " << num2 << " is " << result << endl;
            }
            if (opr == '-')
            {
                cout << "Enter first number: ";
                cin >> num1;
                cout << "Enter second number: ";
                cin >> num2;
                float result = subtract(num1, num2);
                cout << "Difference of " << num1 << " & " << num2 << " is " << result << endl;
            }
            if (opr == '*')
            {
                cout << "Enter first number: ";
                cin >> num1;
                cout << "Enter second number: ";
                cin >> num2;
                float result = multiply(num1, num2);
                cout << "Product of " << num1 << " & " << num2 << " is " << result << endl;
            }
            if (opr == '/')
            {
                cout << "Enter first number: ";
                cin >> num1;
                cout << "Enter second number: ";
                cin >> num2;
                float result = divide(num1, num2);
                cout << "Division of " << num1 << " & " << num2 << " is " << result << endl;
            }
            if (opr == 'f')
            {
                cout << "Enter the number to find factorial: ";
                cin >> num1;
                int result = factorial(num1);
                cout << "Factorial of " << num1 << " is " << result << endl;
            }
            if (opr == 'e')
            {
                double base;
                int exponent;

                cout << "Enter the base: ";
                cin >> base;

                cout << "Enter the exponent: ";
                cin >> exponent;

                double result = power(base, exponent);
                cout << "Result: " << result << endl;
            }
            if (opr == 'r')
            {
                int num1;
                cout << "Enter the number to find the square root: ";
                cin >> num1;
                double result = squareRoot(num1);
                cout << "Square Root of " << num1 << " is " << result << endl;
            }
        }

        cout << "Do you want to continue again (if yes press 'y' or 'Y' and no 'n' or 'N'): ";
        cin >> check;
        cin.ignore(); // Ignore newline character left in input buffer
    } while (check[0] == 'y' || check[0] == 'Y');

    return 0;
}
