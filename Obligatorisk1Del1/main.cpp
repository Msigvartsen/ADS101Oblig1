#include <iostream>
#include "classgrades.h"
#include <cstdlib>
#include <fstream>

template<typename T>
void insertionSort(T* array, int arrayLength)
{
    T valueToInsert;                    // Stores the value of current index and sorts it to the left in the array
    int indexPosition;                  // Stores the current index
    for(int i{1}; i < arrayLength; i++)
    {
        valueToInsert = array[i];
        indexPosition = i;
        while(indexPosition > 0 && array[indexPosition-1] > valueToInsert)
        {
            array[indexPosition] = array[indexPosition-1];
            indexPosition = indexPosition - 1;
        }
        array[indexPosition] = valueToInsert;
    }
}

void readFile(ClassGrades& classGrades, std::string fileName)
{
    //Opens and reads file with inputted name and inputs the data in the class objects array
    std::ifstream readFile("../Obligatorisk1Del1/files/" + fileName + ".txt");
    if(!readFile)
    {
        std::cerr << "Could not read file " << fileName;
        exit(1);
    }
    readFile >> classGrades;
    readFile.close();
}


void printFile(ClassGrades& classGrades, std::string fileName)
{
    //Opens and writes all data to a new file with inputted name
    std::ofstream printFile("../Obligatorisk1Del1/files/" + fileName + ".txt");
    if(!printFile)
    {
        std::cerr << "Error writing to file " << fileName;
        exit(1);
    }
    printFile << classGrades;
    printFile.close();
}

int main()
{
    ClassGrades a(10);
    std::cout << "Creating new instance \"a\" with size: " << a.getClassSize() << "\n";

    ClassGrades b(10);
    std::cout << "Creating new instance \"b\" with size: " << b.getClassSize() << "\n\n";

    std::cout << "Gather data from file. Input in a.mGrades[]: \n";
    readFile(a, "gradeList");
    a.printArray();

    std::cout << "Sorting data in a.mGrades[]... \nSorted Data: \n";
    insertionSort(a.getGradeArray(),a.getClassSize());
    a.printArray();

    std::cout << "\nGather data from file. Input in b.mGrades[]: \n";
    readFile(b, "gradeList2");
    b.printArray();

    std::cout << "Sorting data in b.mGrades[]... \nSorted Data: \n";
    insertionSort(b.getGradeArray(),b.getClassSize());
    b.printArray();

    std::cout << "\nWriting sorted list to new file..\n";
    printFile(a, "sortA");
    std::cout << "Writing sorted list to new file..\n";
    printFile(b, "sortB");

    std::cout << "\nCalculating average scores...\n\n";
    if(a < b)
    {
        std::cout << "Class B has the highest average of: " << b.getAvarageScores() << "!\n";
        std::cout << "Class A came second with a average of: " << a.getAvarageScores() << "\n";

    }
    else
    {
        std::cout << "Class A has the highest average of: " << b.getAvarageScores() << "!\n";
        std::cout << "Class B came second with a average of: " << a.getAvarageScores() << "\n";
    }

    return 0;
}
