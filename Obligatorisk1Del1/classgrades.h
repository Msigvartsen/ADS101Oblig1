#ifndef CLASSGRADES_H
#define CLASSGRADES_H
#include <iostream>
//Class containing array with grade scores -
class ClassGrades
{
private:
    int mClassSize;
    float* mGrades;
    float mTotalScore;
public:
    ClassGrades(int classSize): mGrades{nullptr}, mClassSize(classSize), mTotalScore{0} {initializeArray();}
    ~ClassGrades();
    void initializeArray();
    void printArray();
    float *getGradeArray();
    float getAvarageScores() const;
    int getClassSize() const;

    //Operator overloads
    friend std::ostream& operator<< (std::ostream& out, ClassGrades& classGrades);
    friend std::istream& operator>> (std::istream& in, ClassGrades& classGrades);
    friend bool operator< (ClassGrades& a, ClassGrades& b);

};

#endif // CLASSGRADES_H
