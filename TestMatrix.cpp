//
//  main.cpp
//  Matrix Manipulation
//
//  Created by Yosef on 9/4/15.
//  Copyright (c) 2015 Yosef. All rights reserved.
//

#include <iostream>
#include "matrix.cpp"
#include <vector>

using namespace std;

void TestPart1()
{
    cout << "PART 1:" << endl;
    Matrix<int> a, b;
    cout << a.NumRows() << " " << a.NumCols() << endl;
    
    a.ReadMatrix(); // user provides rows, columns and values
    
    cout << a << endl; // An overloaded operator to print matrix results
    b.ReadMatrix(); // user provides rows, columns and values
    cout << b << endl; // An overloaded operator to print matrix results
    
    a=b;
    cout << b << endl; // An overloaded operator to print matrix results
    
    Matrix<int> c = b; // Calling a copy constructor
    cout << c << endl;
    
    Matrix<int> d = move(c); // Calling a move constructor for d
    cout << d << endl;
    
    a = move(d); // Using the move assignment operator for a ??
    cout << a << endl;
}

void TestPart2()
{
    cout << "PART 2:" << endl;
    Matrix <string> a,b;
    a.ReadMatrix();
    cout << a << endl;
    b.ReadMatrix();
    cout << b << endl;
    
    cout << a + b << endl;
    Matrix <string> d = a+b;
    cout << d << endl;
    cout << d + "hi_there";

    PrintVec(a[1]);
    PrintVec(b[2]);
 
}

void TestPart3()
{
    cout << "PART 3:" << endl;
    Matrix<double> a,b;
    a.ReadMatrix();
    cout << a << endl;
    
    b.ReadMatrix();
    cout << b << endl;
    
    a.Swap(b);
    cout << a << endl;
    cout << b << endl;
}

int main()
{
   
    TestPart1(); 

    TestPart2();
    
    TestPart3();

    return 0;
}
