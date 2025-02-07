
#include<iostream>
#include<string>

using namespace std;


void f(int x) {std::cout << ++x;}
void g(int &x) {std::cout << ++x;}


void buildMatrix(int **matrix, int m, int n){
 int init = 10;
 matrix = new int*[m];
 for(int i = 0; i < m; i++)
 matrix[i] = new int[n];
}
void deleteMatrix(int **matrix, int m){
 for (int i=0;i<m;i++)
 delete [] matrix[i];
 delete [] matrix;
}

int main(){

    cout << "Main ran" << endl;


/*

Homework 1
CMSC 341 - Section 4, 5, 6 - Spring 2025
Due Date Feb 16, 2025, 11:59 PM
1 – Assume the following piece of code is part of a program.
a - Briefly (in one or two sentences) explain what will happen if we try to run the
program and why. (4 points)
string * data[10];
for (int i=0;i<10;i++)
*data[i] = “”;
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

//The problem with code is we cant dereference an uninitialzied point i.e. *data[i]=""
//because it does not point to allocated memory. First, we have to allocate memory
//by using "new" before derefrening.

int i = 1;
cout << "SOLUTION # " << i << "\n\n\n";
i++;
string * data[10];


for(int ix = 0; ix < 10; ix++){

    cout << "Allocating mem" << endl;
    data[ix] = new string("");

}

//in case of double pointer

string ** myData = new string*[10]; // created an array of string pointers 10 of them

//now allocate memory to each of the pointer what you want in those ptrs

for(int i  = 0; i < 10; i++ ){


    myData[i] = new string[5]; //here 5  is the number of coloums means how many items you want for each row ptr

}

for(int i  = 0; i < 10; i++ ){
for(int j = 0; j < 5; j++){

    myData[i][j] = "nulls";
        cout <<  myData[i][j] << endl;
}


}


cout << myData[0][0] << endl;
/*
2 - Assume the following piece of code is part of a program.
a - Briefly (in one or two sentences) explain what will happen if we try to run the
program and why. (4 points)
b - Briefly explain how we can fix the code. (2 points)
int **theStructure = new int*[20];
for (int i=0; i<20; i++){
for (int j=0; j<10; j++){
theStructure[ i ][ j ] = 0;
}
}

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

*/
cout << "SOLUTION # " << i << "\n\n\n";
i++;

int **theStructure = new int*[20];//this part did the row allocation


for (int i=0; i<20; i++){

       theStructure[i] = new int[10];//this part of code was missing becasuse we were not allocating memory to integer pointers
                                     //this line of code did the coloumn allocaiton

for (int j=0; j<10; j++){

        theStructure[ i ][ j ] = 0; //here we are assignment values to 2d array this will assign all
                                   //col and rows of array to zero
}
}

cout <<  theStructure[0][0];

// Error: We are trying to assign a value to a 2D array location that does not exist.
// The memory for integer pointers (`theStructure[i]`) has been allocated,
// but the memory for the actual integer arrays (`theStructure[i][j]`) has not been allocated.
// This leads to undefined behavior.
/*
3 – Briefly explain how differently the following two functions act? (5 points)
void f(int x) {std::cout << ++x;}
void g(int &x) {std::cout << ++x;}

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

*/
cout << "SOLUTION # " << i << "\n\n\n";
i++;

int y = 10;
int z = 10;
f(y);
cout << "\n\n";
cout << y << "this is for pass by val" << endl;
cout << "\n\n";
g(z);
cout << "\n\n";
cout << z << " this is for pass by ref" << endl;
//in f funciton the parameter is pass by value. The function is dealing with the copy of parameter.
//any changes made to the parameter inside the function would not modify the orignal parameter
//in g function the parameter is passed by ref, the function is dealing with the orignal argument
//any changes made to the argument would modify the orignal argument


/*
4 – The following program allocates memory in one function and deallocates it in another
function.
a - Briefly (in one or two sentences) explain what will happen if we try to run the
program and why. (5 points)
b - Briefly explain how we can fix the code. We are not allowed to change the structure
of this program. Memory must be allocated in the buildMatrix function and deallocated in
the deleteMatrix function. We are not allowed to modify the matrix data structure. The
matrix data structure must remain a 2D structure.(5 points)
void buildMatrix(int **matrix, int m, int n){
 int init = 10;
 matrix = new int*[m];
 for(int i = 0; i < m; i++)
 matrix[i] = new int[n];
}
void deleteMatrix(int **matrix, int m){
 for (int i=0;i<m;i++)
 delete [] matrix[i];
 delete [] matrix;
}
int main(){
 int **array;
 buildMatrix(array, 2, 2);
 deleteMatrix(array, 2);
 return 0;
}
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

*/

cout << "SOLUTION # " << i << "\n\n\n";
i++;

int **array;
 buildMatrix(array, 2, 2);
 deleteMatrix(array, 2);


/*
5 - The following class declarations present the interface of a linked list class. Write the
implementation of the functions append(...) and removeTail(). Note: a correct algorithm is
required in your code, but fully compiling code is not expected. Throw “std::runtime_error”
exceptions to handle special cases. The “runtime_error” class is defined in the include file
<stdexcept>. You can simply throw runtime_error(“your message”). (30 points)
class Node { // a node in a linked list
public:
 Node():m_next(nullptr),m_elem(""){};
private:
 string m_elem; // element value
 Node* m_next; // next item in the list
 // provides LinkedList access
 friend class LinkedList;
};
class LinkedList { // a linked list
public:
 LinkedList(); // empty list constructor
 ~LinkedList(); // destructor
 // empty() checks if list is empty
 bool empty() const;
 // front() returns the front (head) member
 const string& front() const;
 // tail() returns the last member
 const string& tail() const;
 // append() inserts a node at the tail of list
 void append(const string& toInsert);
 // removeTail() removes the last member of the list
 void removeTail();
 // printList() prints all members in order from head to tail
 void printList();
 //overloaded assignment operator makes an exact copy of rhs
 const LinkedList& operator=(const LinkedList& rhs);
private:
 Node* m_head; // pointer to the head of list
};
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

*/


/*
6 - List the test cases required to test the append(...) function in the LinkedList class mentioned
above. (10 points)

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

*/

/*
7 - List the test cases required to test the removeTail() function in the LinkedList class mentioned
above. (10 points)
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

*/

/*
8 - Implement a testing function for the function removeTail(). All required operations can be
executed in your function and the main function will call your function. Your function returns a
boolean value for passing or failing. Specify which case from question 7 your function is testing.
Note: a correct algorithm is required in your code, but fully compiling code is not expected. You
can use the functions provided by the class interface above. If required, you can catch exceptions
thrown in your implementation of the function removeTail(). (10 points)

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

*/


/*
9 – For the LinkedList class mentioned above implement an overloaded assignment operator.
The assignment operator must create an exact deep copy of the rhs object. An exact copy means
the order of the nodes in both lists will be the same. You are not allowed to call other functions
from the class or the constructor. To write an efficient function all remove or insert operations
must happen at the head of the list not at the tail. (15 points)

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

*/

}
