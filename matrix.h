//
//  matrix.h
//  Matrix Manipulation
//
//  Created by Yosef on 9/4/15.
//  Copyright (c) 2015 Yosef. All rights reserved.
//

#ifndef __Matrix_Manipulation__matrix__
#define __Matrix_Manipulation__matrix__

#include <stdio.h>
#include <iostream>
#include <vector>


using namespace std;
template <typename Comparable>
class Matrix
{
    
    public:
        Matrix(); //Constructor
        Matrix(size_t rows, size_t cols); //Constructor with two elements

        ~Matrix(); // Destructor
        Matrix( const Matrix & rhs ); // Copy constructor
        Matrix( Matrix && rhs ); // Move constructor
        Matrix & operator= ( const Matrix & rhs ); //Copy assignment operator
        Matrix & operator= ( Matrix && rhs ); // Move assignment operator
        size_t NumRows(); // Returns number of rows
        size_t NumCols(); // Returns number of columns
        void ReadMatrix(); // Takes user inputs for new matrix
        friend void PrintVec(const vector<Comparable> & obj); // Prints obect elements'
    
        friend ostream& operator<<(ostream& os, Matrix<Comparable>& mtx) // Overloading << for lvalues
        {
            for (int i = 0; i < mtx.num_rows_; i++ )
            {
            
                for (int j = 0; j < mtx.num_cols_; j++ )
                {
                    os << mtx.array_[i][j] << " ";
                }
                os << endl;
            }
        
            return os;
        }
    
        friend ostream& operator<<(ostream& os, Matrix<Comparable>&& mtx) // Overloading << for rvalues
        {
            for (int i = 0; i < mtx.num_rows_; i++ )
            {
            
                for (int j = 0; j < mtx.num_cols_; j++ )
                {
                    os << mtx.array_[i][j] << " ";
                }
                os << endl;
            }
        
            return os;
        }
    
        Matrix <Comparable> operator+( Matrix<Comparable>& rhs) //Overloads the + operator to add like string
        {
            Matrix <Comparable> NewObject;
            NewObject.num_rows_ = this->num_rows_;
            NewObject.num_cols_ = this->num_cols_;
            NewObject.array_ = this->array_;
        
            NewObject.array_ = new Comparable *[num_rows_];
        
            for (int i = 0; i < num_rows_; i++ )
            {
                NewObject.array_[i] = new Comparable[num_cols_];
            
                for(int j=0; j<num_cols_; j++)
                {
                    
                   NewObject.array_[i][j] = this->array_[i][j] + rhs.array_[i][j];
   
                }
            }
 
        return NewObject;
        }
    
        Matrix <Comparable> operator+( const Comparable & s) //Overloads the + operator to add string to other data
        {
            Matrix <Comparable> NewObject;
            NewObject.num_rows_ = this->num_rows_;
            NewObject.num_cols_ = this->num_cols_;
            NewObject.array_ = this->array_;

            NewObject.array_ = new Comparable *[this->num_rows_];

            for (int i = 0; i < num_rows_; i++ )
            {
                NewObject.array_[i] = new Comparable [this->num_cols_];

                for(int j=0; j<num_cols_; j++)
                {
                    
                    NewObject.array_[i][j] = this->array_[i][j] + s;                   
                }
            
            }
            return NewObject;
        }

        vector<Comparable> operator[](int rowNum) // Overloads the [] simbol
        {
            vector<Comparable> vecObj;
            for (int i = 0; i < num_cols_; i++ )
            {
                    vecObj.push_back (array_[rowNum-1][i]);

            }
            return vecObj;
        }
    

        Matrix<Comparable> Swap( Matrix<Comparable> rhs ) //Swaps elements and returns a pointer with its new value
        {
            Matrix<Comparable> tmp = std::move(rhs);
            rhs = std::move( *this );
            *this = std::move( rhs );
        
            return *this;
        }

    private:
        size_t num_cols_=0;
        size_t num_rows_=0;
        Comparable **array_=nullptr;
    
};
#endif /* defined(__Matrix_Manipulation__matrix__) */
