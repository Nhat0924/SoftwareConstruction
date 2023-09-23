/* 
* FILE NAME: project3_Nguyen_nhn0001.cpp
* AUTHOR: Nhat Nguyen - nhn0001
* Version: 3/22/2023
* Edit using C++ online compiler/VS Code and compile using g++ in Linux bash shell/AU server.
* Format using Dr. Li's project 3 hints and sample codes
* Learned how to use vector array from GeeksforGeeks
* Source: https://www.geeksforgeeks.org/vector-in-cpp-stl/
* Learned about built-in sort functions from Nathan Hunter and GreatLearning
* Source: https://www.mygreatlearning.com/blog/sort-function-in-cpp/
*/  
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
  using namespace std;

 
/* declare your user-defined functions */ 
  
/* do not forget to describe each function */ 

/*
* A function that takes in a string that represents the input file name.
* Return: a vector array containing the elements of the input file.
*/
vector < int >read_file (string);

/*
* A function that writes each element of the vector array to an output file.
*/
void write_file (string, vector < int >);

/*
* A function that merge the elements of two vector arrays.
* Return: a vector array containing the elements merged together from the two vectors.
*/
vector < int >merge (vector < int >, vector < int >);

/*
* A function that sort the elements of a vector array.
* Return: a vector array containing the elements sorted.
*/
vector < int >sort (vector < int >);

/* learn how to use vector array from GeeksforGeeks
* Source: https://www.geeksforgeeks.org/vector-in-cpp-stl/
*/

int
main ()
{
  
/* declare variables */ 
string file1, file2, file3;
  
int data1, data2;
  
vector < int >array1, array2;
  
ifstream InStream1, InStream2;
  
vector < int >output;
  
vector < int >output_sorted;
  
 
/* user friendly interfaces - title */ 
cout << "*** Welcome to Nhat's sorting program ***" << endl;
  
/* Get and display file one. */ 
cout << "Enter the first input file name: ";
  
cin >> file1;
  
// Pass file name as an array of chars to open()
InStream1.open ((char *) file1.c_str ());
  
//checking file
if (InStream1.fail ())
{
      
cout << "Error: Cannot open input file." << endl;
      
exit (1);
    
}
  
// Print the list of numbers in file 1
array1 = read_file (file1);
  
cout << "The list of " << array1.size () 
   << " numbers in file " << file1 << " is:" << endl;
  
InStream1 >> data1;
  
while (!InStream1.eof ())
{
      
cout << data1 << endl;
      
InStream1 >> data1;
    
}
  
 
InStream1.close ();
  
//-------------------------------------------------------
/* Get and display file two. */ 
cout << "\nEnter the second input file name: ";
  
cin >> file2;
  
//Pass file name as an array of chars to open()
InStream2.open ((char *) file2.c_str ());
  
//checking file
if (InStream2.fail ())
{
      
cout << "Error: Cannot open input file." << endl;
      
exit(1);
    
}
  
// Print the list of numbers in file 2
array2 = read_file (file2);
  
cout << "The list of " << array2.size () 
   << " numbers in file " << file2 << " is:" << endl;
  
 
InStream2 >> data2;
  
while (!InStream2.eof ())
{
      
cout << data2 << endl;
      
InStream2 >> data2;
    
}
  
 
InStream2.close ();
  
//--------------------------------------------------------
/* Combine vectors and display the sorted result. */ 
    output = merge (array1, array2);
  
output_sorted = sort (output);
  
cout << "\nThe sorted list of " << output_sorted.size () 
   << " numbers is: ";

for (int element:output_sorted)
{
      
cout << element << " ";
    
} 
 
// Write the output into an output file
cout << "\nEnter the output file name: ";
  
cin >> file3;
  
write_file (file3, output_sorted);
  
cout << "*** Please check the new file - " << file3 << " ***" << endl;
  
cout << "*** Goodbye. ***" << endl;
  
 
return 1;

}


 
/* read_file function definition*/ 
vector < int >
read_file (string file)
{
  
/* Input file stream. (ifstream) */ 
    ifstream stream;
  
/* Vector containing numbers from file. (vector<int>) */ 
  vector < int >v;
  
/* Integer read from file. (int) */ 
  int i;
  
/* Add each number in the file to a vector. */ 
    stream.open (file);
  
stream >> i;
  
while (stream.good ())
{
      
v.push_back (i);
      
stream >> i;
    
}
  
stream.close ();
  
return v;

}


 
/*write_file function definition*/ 
  void
write_file (string file, vector < int >v)
{
  
/* Output file stream. (ofstream) */ 
    ofstream out;
  
out.open (file);

 
for (int element:v)
{
      
out << element << endl;
    
} 
 
out.close ();
  
out.clear ();

} 
 

/*merge function definition*/ 
vector < int >
merge (vector < int >v1, vector < int >v2)
{
  
vector < int >v;

 
for (int element:v1)
{
      
v.push_back (element);

} 
 
for (int element:v2)
{
      
v.push_back (element);
    
} 
 
return v;

 
}


/*
* Learned about built-in sort functions from Nathan Hunter and GreatLearning
* Source: https://www.mygreatlearning.com/blog/sort-function-in-cpp/
*/
/*sort function definition*/ 
vector < int >
sort (vector < int >v)
{
  
sort (v.begin (), v.end ());
  
return v;

}
