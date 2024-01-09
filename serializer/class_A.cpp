//
//  class_A.cpp
//  serializer
//
//  Created by Ishan Phadke on 12/29/23.
//

#include "class_A.hpp"
#include "class_B.hpp"
#include <iostream>
#include <sstream>

// Default constructor is empty since all the default values are already assigned in the class defintion
A::A()
{
    
}

// Value constructor for class A. format specifies the format of which strings is written in (JSON or YAML)
A::A(char* strings, string format)
{
    if (format == "YAML")
        YAML_deserializer(strings);
    
    else if (format == "JSON")
        JSON_deserializer(strings);
}

/*
 Overriding the JSON serializer function. Takes no parameters and returns a char* with the whole serialized string for class class A, B, C, and D.
 */
char* A::JSON_serialize()
{
    stringstream ss;
    
    ss << "{" << endl;
    ss << "\t{Class A,  " << endl;
    ss << "\t\t\"val1\": " << "{" << val1 << ", int}" << "," << endl;
    ss << "\t\t\"val2\": " << "{" << val2 << ", double}"  "," << endl;
    ss << "\t\t\"name\": {\"" << name << "\"" << ", string}, " << endl;
    
    // Serialize the B object
    char* bSerialized = bPtr->JSON_serialize();
    ss << "\t\t\"bPtr\": " << bSerialized;
    ss << "\t}" << endl;
    // End the JSON-like string
    ss << "}";

    // Convert the stringstream to a string and allocate memory for char*
    string jsonString = ss.str();
    char* result = new char[jsonString.size() + 1];
    strcpy(result, jsonString.c_str());

    return result;
}

/*
    Overriding the YAML serializer function. Takes no parameters and returns a char* with the whole serialized string for class class A, B, C, and D.
 */
char* A::YAML_serialize(void)
{
    
    stringstream ss;
    
    ss << "---" << endl;
    ss << "Class A" << endl << endl;
    ss << "val1: " << "(" << val1 << ", int)" << endl;
    ss << "val2: "<< "(" << val2 << ", double)" << endl;
    ss << "name: " << "(" << "\"" << name << "\"" << ", string)" << endl;
    ss << "bPtr: " << endl;
    ss << "\tClass B" << endl << endl;
    ss << bPtr->YAML_serialize();
    
    string yamlString = ss.str();
    char* result = new char[yamlString.size() + 1];
    strcpy(result, yamlString.c_str());
    
    return result;
    
}

/*
    Overriding the YAML deserialzer function. Takes one char* parmater that holds the YAML string. It then deserialzes it for class A, B, C, and D by using the specific functions for those classes. No return value
 */
void A::YAML_deserializer(char* yamlString)
{
    stringstream ss(yamlString);
    string line;

    getline(ss, line);

    getline(ss, line);
    getline(ss, line);

    getline(ss, line, '(');
    int intVal;
    ss >> intVal;
    val1 = intVal;
    getline(ss, line);
    ss.ignore();

    getline(ss, line, '(');
    double doubleVal;
    ss >> doubleVal;
    val2 = doubleVal;
    getline(ss, line);

    getline(ss, line, '(');
    getline(ss, line, '"');
    getline(ss, name, '"');
    getline(ss, line);
    
    getline(ss, line, ':');
    getline(ss, line);
    
    bPtr->YAML_deserializer(yamlString);
    
}

/*
    Overriding the JSON deserialzer function. Takes one char* parmater that holds the JSON string. It then deserialzes it for class A, B, C, and D by using the specific functions for those classes. No return value
 */
void A::JSON_deserializer(char* jsonString)
{
    stringstream ss(jsonString);
    string line;
    
    getline(ss, line, '{');
    getline(ss, line, '{');
    getline(ss, line, '{');
    ss >> val1;
    getline(ss, line, '{');
    ss >> val2;
    getline(ss, line, '{');
    getline(ss, line, '"');
    getline(ss, name, '"');
    getline(ss, line);
    
    bPtr->JSON_deserializer(jsonString);
    
}

// Destructor for class A releases all allocated memory.
A::~A()
{
    delete bPtr;
    val1 = 0;
    val2 = 0;
    name = nullptr;
}
