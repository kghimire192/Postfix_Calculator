/**@file myStack.h
 * A Class representing a stack of doubles
 * @author Kanchan Ghimire
 * @date September 26,2016
 */

#ifndef PROJECT1_MYSTACK_H
#define PROJECT1_MYSTACK_H

#include <stack>
#include <string>

using namespace std;

class myStack
{
  private:
    /**A stack that stores doubles */
    stack<double> stk;

  public:
    /**
     * Insert/ add a double in stack
     * @param given_num  the number (double) to be stored in stack
     */
    void push(double given_num);

    /**
     * Remove and return a double from the stack
     * @return a double from stack
     */
    double pop();

    /**
     * Check to see if the stack is full or not
     * @return a True/False value
     */
    bool isEmpty();

    /**
     * To print the total number of items in the stack, and a list of all the items, from bottom to top
     * @return a string representing items in the stack
     */
    string toString();

    /**
     * Get the size of the stack
     * @return an int representing the size of the stack
     */
    int getSize();
};



#endif //PROJECT1_MYSTACK_H
