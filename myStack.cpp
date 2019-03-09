/**@file myStack.cpp
 * A Class representing a stack of doubles
 * @author Kanchan Ghimire
 * @date September 26,2016
 */

#include "myStack.h"
#include <string>
using namespace std;



//Method that will add the given_item to the top of the stack
void myStack::push(double given_item)
{
    stk.push(given_item);
}

//Method that will remove and return the top item from the stack
double myStack::pop()
{
    if(stk.size() != 0)   //checking for underflow
    {
        double item = stk.top();
        stk.pop();
        return item;
    }
}

//Method that will return true if the stack is empty and false if it is not
bool myStack::isEmpty()
{
   if(stk.empty())
       return true;
   else
       return false;
}


//Method that will print the total number of items in the stack, and a list of all the items, from bottom to top
string myStack::toString()
{
    string outstring = "";
    string items_stk = "";

    int stk_size = stk.size();                        //size of stack
    double myArray[stk_size] = {};                    //create an array the size of the stack

    //populate array with the items of the stack, which also deletes items from the stack
    for (int i = 0; i < stk_size; i++)
    {
        double item = stk.top();
        stk.pop();
        myArray[i] = item;
    }

    //looping through array to store the items of the array in a string variable items_stk
    for (int j = stk_size - 1; j >= 0; j--)
    {
        items_stk += to_string(myArray[j]) + "\n";
    }

    //repopulating stack with the order as it was before we popped items and stored in an array
    for(int k = stk_size - 1; k >= 0; k--)
    {
       stk.push(myArray[k]);
    }

    //concatenate to outstring the total number of items and a list of all items from bottom to top
    outstring = outstring + "The total number of items in the stack is: " + to_string(stk_size) + "\n" + "The list of items : " + "\n" + items_stk;
    return outstring;
}

//Method that will return the size of the stack
int myStack:: getSize()
{
    return stk.size();
}