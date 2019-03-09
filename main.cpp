/**@file main.cpp
 * To instantiate object of stack class and do postfix calculation
 * @author Kanchan Ghimire
 * @date September 26,2016
 */

#include <iostream>
#include "myStack.h"
using namespace std;

int main()
{
    myStack myStackObj;     //instantiating an object of stack class

    double temp_var = 0;    //default value of temp_var is 0
    double var1 = 0;        //default value of var1 is 0
    double var2 = 0;        //default value of var2 is 0
    double sum = 0;         //default value of sum is 0
    double diff = 0;        //default value of diff is 0
    double mult = 0;        //default value of mult is 0
    double div = 0;         //default value of div is 0
    bool error = false;     //default value of error is false
    string input_str = "";  //default value of input_str is an empty string

    //while loop
    while(true)
    {
        error = false;        // resets variable error to false while looping through each time

        //clearing the stack
        while(!myStackObj.isEmpty())
        {
            myStackObj.pop();
        }

        //Prompt for the user
        cout << "Hello User! Please enter a postfix expression you want to calculate, with spaces in between and "
                "the expression not longer than 50 characters, Exit to quit" << endl;

        //Read a string (line) that is user input and store it in variable input_str
        getline(cin,input_str);

        //Exits or breaks the loop if the user gives exit as the input
        if(input_str == "exit" || input_str == "Exit" || input_str == "EXIT")
        {
            break;
        }

        else if (input_str.length() <= 100)
        {
            for(int i = 0; i < input_str.length(); i++)
            {
                //using switch selection statements to handle numbers 0-9, '+', '-', '*' and '/'
                switch(input_str[i]) {

                    case '0':
                    case '1':
                    case '2':
                    case '3':
                    case '4':
                    case '5':
                    case '6':
                    case '7':
                    case '8':
                    case '9':
                        temp_var = input_str[i] - '0';

                        //checking for multiple digits
                        if(input_str[i + 1 != ' '])
                        {
                            i++;
                        }
                        while (input_str[i] != ' ')
                        {
                            temp_var = (temp_var * 10) + (input_str[i] - '0');
                            if(input_str[i + 1 != ' '])
                            {
                                i++;
                            }
                        }

                        myStackObj.push(temp_var);  //calling the push function
                        break;

                    //Implement summation (takes two numbers from the top of the stack, add them and put the result in the stack)
                    case '+':
                        if(!myStackObj.isEmpty())   //checking for underflow
                        {
                            var1 = myStackObj.pop();     // returning and removing a double from the top of the stack
                            if(!myStackObj.isEmpty())   //checking for underflow
                            {
                                var2 = myStackObj.pop(); // returning and removing a double from the top of the stack
                                sum = var2 + var1;       //add those two numbers returned from the stack
                                myStackObj.push(sum);    //calling the push function, sending the result from above
                                break;
                            }
                        }
                        else
                        {
                            error = true;     //reporting error (underflow)
                            break;
                        }

                    //Implement subtraction
                    case '-':
                        if(!myStackObj.isEmpty())    //checking for underflow
                        {
                            var1 = myStackObj.pop();  // returning and removing a double from the top of the stack
                            if(!myStackObj.isEmpty())  //checking for underflow
                            {
                                var2 = myStackObj.pop(); // returning and removing a double from the top of the stack
                                diff = var2 - var1;      //subtraction between those two numbers returned from stack
                                myStackObj.push(diff);   //calling the push function, sending the result from above
                                break;
                            }
                        }
                        else
                        {
                            error = true;   //reporting error (underflow)
                            break;
                        }

                    case '*':
                        if(!myStackObj.isEmpty())   //checking for underflow
                        {
                            var1 = myStackObj.pop();    // returning and removing a double from the top of the stack
                            if(!myStackObj.isEmpty())   //checking for underflow
                            {
                                var2 = myStackObj.pop();  // returning and removing a double from the top of the stack
                                mult = var2 * var1;       //multiplication between those two numbers returned from stack
                                myStackObj.push(mult);    //calling the push function, sending the result from above
                                break;
                            }
                        }
                        else
                        {
                            error = true;     //reporting error (underflow)
                            break;
                        }

                    case '/':
                        if(!myStackObj.isEmpty())     //checking for underflow
                        {
                            var1 = myStackObj.pop();   // returning and removing a double from the top of the stack
                            if(!myStackObj.isEmpty())   //checking for underflow
                            {
                                var2 = myStackObj.pop(); // returning and removing a double from the top of the stack
                                div = var2 / var1;       //division between those two numbers returned from stack
                                myStackObj.push(div);    //calling the push function, sending the result from above
                                break;
                            }
                        }
                        else
                        {
                            error = true;    //reporting error (underflow)
                            break;
                        }

                    case ' ':
                        break;              //skips whitespace

                    default:
                        error = true;      //reporting error if user input was invalid input
                        break;
                }
            }
        }

        //if there are no errors and stack contains one element (double) after the calculation, show the result
        if(!error && myStackObj.getSize() == 1)
        {
            double ans = myStackObj.pop();
            cout << "The result of the postfix calculation is: " << ans <<endl;
        }
            //else report error to the user
        else
        {
            cout << "error! " << endl;
        }
    }


}