//
//  matrix.cpp
//  Matrix Manipulation
//
//  Created by Yosi on 9/4/15.
//  Copyright (c) 2015 Yosef. All rights reserved.
//

#ifndef __Matrix_Manipulation__matrix__cpp
#define __Matrix_Manipulation__matrix__cpp
#include "matrix.h"
#include <iostream>
using namespace std;

// Constructor
template <typename Comparable>
Matrix<Comparable>::Matrix()
{
    num_cols_=0;
    num_rows_=0;
}

// Constructor with two elements
template <typename Comparable>
Matrix<Comparable>::Matrix(size_t rows, size_t cols)
{
    cols = num_cols_;
    rows = num_rows_;
}

// Destructor
template <typename Comparable>
Matrix<Comparable>::~Matrix()
{
    if (array_ != nullptr)
    {
        for(int i = 0; i < num_rows_; i++)
        {
            delete[] array_[i];
            
        }
        delete[] array_;
        array_ = nullptr;
    }
    
}

// Copy Constuctor. Takes an object and copys all elements to it
template <typename Comparable>
Matrix<Comparable>::Matrix(const Matrix & rhs)
{
    // assign on side values' to the other side
    num_rows_ = rhs.num_rows_;
    num_cols_ = rhs.num_cols_;
    
    array_ = new Comparable *[num_rows_]; // dinamic array size for rows

    for (int i = 0; i < num_rows_; i++ )
    {
        array_[i] = new Comparable[num_cols_]; // dinamic array size for columns
    }
    
    for (int i = 0; i < num_rows_; i++ )
    {
        for(int j=0; j<num_cols_; j++)
        {
           array_[i][j] = rhs.array_[i][j];
        }

    }
  
}

// Copy assignment operator. Overloads the equal sign to copy from object. It uses the swap() function
// and returns pointer to itself
template <typename Comparable>
Matrix<Comparable> & Matrix<Comparable>::operator=(const Matrix<Comparable> & rhs )
{

    if (this != &rhs)
    {
        
        Matrix<Comparable> copy = rhs;
        std::swap( *this, copy );
    }
   
     return *this;
    
} // end operator=


// Move Constructor. Creats copy just like above bot this time doesn't save it data.
// It uses the move() function to "take over" its address.
template <typename Comparable>
Matrix<Comparable>::Matrix(Matrix<Comparable> && rhs )
{
    
    //num_rows_ = std::swap(num_rows_,rhs.num_rows_);
    //num_cols_ = std::swap(num_cols_,rhs.num_cols_);
    //array_ = std::swap(array_,rhs.array_);
    
    array_ = std::move(rhs.array_);
    num_rows_ = std::move(rhs.num_rows_);
    num_cols_ = std::move(rhs.num_cols_);
    
    rhs.num_rows_=0;
    rhs.num_cols_=0;
    rhs.array_=nullptr;
  
}

// Move Operator. Uses swap() function and deletes rvalues
template <typename Comparable>
Matrix<Comparable> & Matrix<Comparable>::operator=(Matrix<Comparable> && rhs)
{
    if (this != &rhs)
    {
        std::swap(num_rows_,rhs.num_rows_);
        std::swap(num_cols_,rhs.num_cols_);
        std::swap(array_,rhs.array_);
    }
    rhs.num_rows_=0;
    rhs.num_cols_=0;
    rhs.array_=nullptr;
    return *this;

}

// Function to return rows
template <typename Comparable>
size_t Matrix<Comparable>::NumRows()
{
    return num_rows_;
 
}

// Function to return cols
template <typename Comparable>
size_t Matrix<Comparable>::NumCols()
{
    return num_cols_;
    
}

// A function that creats a matrix based on number of rows, number of columns and values from the user.
template <typename Comparable>
void Matrix<Comparable>::ReadMatrix()
{
    size_t rows, columns;
    cout << "Number of rows: " << endl;
    cin >> rows;
    cout << "Number of columns: " << endl;
    cin >> columns;

    num_cols_=columns;
    num_rows_=rows;
    array_ = new Comparable *[num_rows_];
    for (int i = 0; i < num_rows_; i++ )
    {
        array_[i] = new Comparable[num_cols_];
        
        for(int j=0; j<num_cols_; j++)
        {
            cout << "Value: " << endl;
            cin >> array_[i][j];
        }
        
    }
    
}

// A functionto print elements from a vector
template <typename Comparable>
void PrintVec(const vector<Comparable> &obj)
{
    for (int i = 0; i < obj.size(); i++ )
    {
        cout << obj[i] << " ";
    }
    cout << endl;

}

#endif






