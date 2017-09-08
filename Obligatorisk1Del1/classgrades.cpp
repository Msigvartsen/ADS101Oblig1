#include "classgrades.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

//Returns size of grades array
int ClassGrades::getClassSize() const
{
    return mClassSize;
}
//Returs a pointer to the grade Array
float* ClassGrades::getGradeArray()
{
    return mGrades;
}

float ClassGrades::getAvarageScores() const
{
    return mTotalScore / mClassSize;
}

ClassGrades::~ClassGrades()
{
    delete[] mGrades;
    mGrades = nullptr;
}

// Initializes the array with 0's on construction of object
void ClassGrades::initializeArray()
{
    mGrades = new float[mClassSize];
    for(int i{0}; i < mClassSize; i++)
    {
        mGrades[i] = 0;
    }
}

void ClassGrades::printArray()
{
    for(int i{0}; i < mClassSize; i++)
    {
        std::cout << mGrades[i] << "\n";
    }
}

//Overloading out operator << for writing out to new file
std::ostream& operator<< (std::ostream& out, ClassGrades& classGrades)
{
    for(int i{0}; i < classGrades.getClassSize(); i++)
    {
        out << classGrades.mGrades[i] << "\n";
    }

    return out;
}

//Overload in operator >> to read from file and save data to array. Sums up total scores
std::istream& operator>> (std::istream& in, ClassGrades& classGrades)
{

    for(int i {0}; i < classGrades.getClassSize(); i++)
    {
        in >> classGrades.mGrades[i];
        classGrades.mTotalScore += classGrades.mGrades[i];
    }
    return in;
}

//Overloads < operator to check which instance has the highest average score
bool operator<(ClassGrades &a, ClassGrades &b)
{
       return ((a.mTotalScore / a.getClassSize()) < (b.mTotalScore / b.getClassSize()));
}


