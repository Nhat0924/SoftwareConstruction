/* 
* FILE NAME: Nhat_Nguyen_nhn0001.cpp
* AUTHOR: Nhat Nguyen - nhn0001
* Version: 4/18/2023
* Edit using C++ online compiler/VS Code and compile using g++ in Linux bash shell/AU server.
*/

#include <iostream>
using namespace std;

#define fix1
//#define fix2
int main(void) 
    {
    int num_elems;

    cout << "How many numbers? ";
    cin >> num_elems;

    // Fix 1: use a while loop to bound check the array and prevent users from inputting 
    // too much data
    #ifdef fix1
    int tests[10];
    int test;
    while (num_elems > 10) {
        cout << "\nNumber of elements must be less than 10.\n" << endl;
        cout << "How many numbers? ";
        cin >> num_elems;
    }
    for (int i = 0; i < num_elems; i++) 
        {
            cout << "Please type a number: ";
            cin >> test;
            tests[i] = test;
        }
    #endif

    /* Fix 2: create a dynamic array using new and delete and allow the users to decide the size*/
    #ifdef fix2
    int* tests = new int[num_elems];
    int test;

    for (int i = 0; i < num_elems; i++) 
        {
            cout << "Please type a number: ";
            cin >> test;
            tests[i] = test;
        }
    delete[] tests;
    #endif

    return 0;
}