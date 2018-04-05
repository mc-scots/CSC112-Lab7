## Introduction

Writing robust programs is an absolute must. In real-world settings,
programs that simply stop working for no readily apparent reason are
unacceptable. Programs which continue to appear to work when they have,
in fact, failed are even worse\!

To that end, we are going to take a program and add error checking
mechanisms to make sure that the program will either work correctly or
fail in a way that alerts the user to a problem.

The program we are going to modify is a relatively simple one. It is a
program which computes the average age of friends in a list. The friends
list will be read from a text file, and it will be stored as a vector of
pairs.

## The averageAge Program

Let's start off with the program. This program is already in your lab
folder, but it is also here for the ease of reading the original. (Plus
you can reset your code if you really mess it up\!)

'''File: ''' averageAge.cpp

``` cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

//Function prototypes
pair<string, double> getRecord(ifstream &file);
double average(const vector<pair<string, double>> &data);


int main(int argc, char** argv) 
{
    vector<pair<string, double>> data;   //the data to average
    ifstream file;                       //the file containing the average
    
    //read the vector from the file
    file.open(argv[1]);
    while(not file.eof()) {
        data.push_back(getRecord(file));
    }
    file.close();
    
    
    //print out the average age of our friends
    cout << "Average Age of Friends: " << average(data) << endl;
}


//Read a record from the file and return it as a double 
pair<string, double> 
getRecord(ifstream &file)
{
    //read the pair in 
    pair<string, double> result;
    file >> result.first >> result.second;
    
    return result;
}


//compute the average of the ages in the list
double 
average(const vector<pair<string, double>> &data)
{
    double total=0.0;
    
    for(auto itr=data.begin(); itr != data.end(); itr++) {
        total += itr->second;
    }
    
    return total / data.size();
}
```

This program works\! At least, it works so long as you play nice. Let's
test it out by compiling it and then running it against the friend.txt
file.

` make averageAge`  
` ./averageAge file.txt`

Also, note that there is something just a little bit new here, pair. A
pair is just a simple little object which can store two things for you.
The first item is referred to by "name.first" and the second by
"name.second". A pair is defined by its types, so

`  pair<string, double>`

is a pair where the first item is a string and the second is a double.
Also, take a look at the implications of using a pair with vectors and
iterators. It's not hard, and it's a handy thing to know\!

## Fixing the Issues

The other files in your directory have something wrong with them. Let's
take a look at the files.

**File:** friends.txt

` Bill 18`  
` Jill 25`  
` Will 17`  
` Jack 30`  
` Mack 35`  
` Jennifer 21`

This file is a valid file. We have a first name, followed by an age.

**File:** friends2.txt

` Bill 18`  
` Jill 25`  
` Will 17`  
` Jack 30`  
` Mack `  
` Jennifer 21`

This file has something wrong with it. Can you identify it?

**File:** friends3.txt

` Bill 18`  
` Jill 25`  
` Will 17`  
` Jack 30`  
` Mack Jones 35`  
` Jennifer 21`

This file also has problems.

**File:** friends4.txt

` Bill 18`  
` Jill 25`  
` Will 17`  
` Jack 30`  
` Mack 35`  
` Jennifer `

Again, not a valid file\!

So now your task is to modify the getRecord function so that it can
identify these errors and throw appropriate exceptions. Then, modify the
main function so that it correctly catches the exceptions and handles
them properly. For some of them, they may be recoverable. For others,
you'll just have to terminate the program with a helpful message.

## Further Errors

In addition to the exceptions in the previous section, there are at
least 2 more. Figure out what they are and build appropriate handling of
them.

Good luck\!
