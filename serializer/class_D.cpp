//
//  class_D.cpp
//  serializer
//
//  Created by Ishan Phadke on 12/29/23.
//

#include "class_D.hpp"
#include <sstream>
#include <iostream>

using namespace std;

// Defualt constructor initializes size, and allocates space for the array based on size
D::D()
{
    size = 3;
    array = new int[size];
    for (int i = 1; i < 4; i++)
        array[i-1] = i;
}

/*
 Overriding the JSON serializer function. Takes no parameters and returns a char* with the whole serialized string for class class D.
 */
char* D::JSON_serialize()
{
    stringstream ss;
    ss << "{Class D," << endl << endl;
    ss << "\t\t\t\t\t\"array\": {[";

    for (int i = 0; i < size; ++i) {
        if (i != 0) {
            ss << ",";
        }
        ss << array[i];
    }

    ss << "], int*}," << endl;
    ss << "\t\t\t\t\t\"size\": " << "{" << size << ", int}" << endl << endl;
    ss << "\t\t\t\t}";

    string jsonString = ss.str();
    char* result = new char[jsonString.size() + 1];
    strcpy(result, jsonString.c_str());

    return result;
}

/*
    Overriding the YAML serializer function. Takes no parameters and returns a char* with the whole serialized string for class class D.
 */
char* D::YAML_serialize(void)
{
    stringstream ss;
    
    ss << "\t\t\t- array: (" << endl;

    for (int i = 0; i < size; i++) {
        ss << "\t\t\t\t- " << array[i] << endl;
    }
    
    ss << "\t\t\t\t, int*)" << endl;
    
    ss << "\t\t\t- size: " << "(" << size << ", int)" << endl;
    
    string yamlString = ss.str();
    char* result = new char[yamlString.size() + 1];
    strcpy(result, yamlString.c_str());
    
    return result;
}

/*
    Overriding the YAML deserialzer function. Takes one char* parmater that holds the YAML string. It then deserialzes it for class D by using the specific functions for those classes. No return value
 */
void D::YAML_deserializer(char* yamlString)
{
    stringstream ss(yamlString);
    string line, tab;

    
    getline(ss, line);
    getline(ss, line);
    getline(ss, line);
    getline(ss, line);
    getline(ss, line);
    getline(ss, line);
    getline(ss, line);
    getline(ss, line);
    
    getline(ss, tab, '\t');

    getline(ss, line, ':');
    getline(ss, line);     

    
    getline(ss, line, ':');
    getline(ss, line);
    getline(ss, line);
    getline(ss, line);
    getline(ss, line);

   
    array = nullptr;
    size = 0;

    // Iterate through array elements
    while (getline(ss, line, '-')) {
       
        int element;
        ss >> element;
        
        if (element == 0)
            break;

       
        int* newArray = new int[size + 1];
        for (int i = 0; i < size; ++i) {
            newArray[i] = array[i];
        }
        newArray[size++] = element;

        delete[] array;
        array = newArray;
    }
    
    ss >> size;
    getline(ss, line);
}

/*
    Overriding the JSON deserialzer function. Takes one char* parmater that holds the JSON string. It then deserialzes it for class D by using the specific functions for those classes. No return value
 */
void D::JSON_deserializer(char* jsonString)
{
    stringstream ss(jsonString);
    string line, tab;

    getline(ss, line, ',');
    getline(ss, line, ',');
    getline(ss, line, ',');
    getline(ss, line, ',');
    getline(ss, line, ',');
    getline(ss, line, ',');
    getline(ss, line, ',');
    getline(ss, line, '[');
    
    array = nullptr;
    size = 0;

    // Iterate through array elements
    while (true) {
       
        int element;
        ss >> element;
        
        if (element == 0)
            break;

       
        int* newArray = new int[size + 1];
        for (int i = 0; i < size; ++i) {
            newArray[i] = array[i];
        }
        newArray[size++] = element;

        delete[] array;
        array = newArray;
        ss.ignore();
    }
    
    getline(ss, line, '{');
    ss >> size;
    getline(ss, line);
}

// Destructor for class D releases all allocated memory.
D::~D()
{
    delete [] array;
    size = 0;
    array = nullptr;
}
