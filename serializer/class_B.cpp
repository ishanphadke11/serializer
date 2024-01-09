//
//  class_B.cpp
//  serializer
//
//  Created by Ishan Phadke on 12/29/23.
//

#include "class_B.hpp"
#include <iostream>
#include <sstream>
#include "class_C.hpp"

using namespace std;

// Defualt constructor simply allocates space for cPtr
B::B()
{
    cPtr = new C;
}

/*
 Overriding the JSON serializer function. Takes no parameters and returns a char* with the whole serialized string for class class B, C, and D.
 */
char* B::JSON_serialize()
{
    stringstream ss;
    ss << "{Class B, " << endl << endl;
    ss << "\t\t\t\"cPtr\": " << cPtr->JSON_serialize() << "," << endl;
    ss << "\t\t\t\"number\": " << "{" << number << ", int}" << "," << endl;
    ss << "\t\t\t\"city\": " << "{\"" << city << "\"" << ", string}" << endl << endl;
    ss << "\t\t\t}" << endl << endl;

    string jsonString = ss.str();
    char* result = new char[jsonString.size() + 1];
    strcpy(result, jsonString.c_str());

    return result;
}

/*
    Overriding the YAML serializer function. Takes no parameters and returns a char* with the whole serialized string for class class B, C, and D.
 */
char* B::YAML_serialize(void)
{
    
    stringstream ss;
    
    ss << "\t- cPtr: " << endl;
    ss << "\t\t Class C" << endl << endl;
    ss << cPtr->YAML_serialize();
    ss << "\t- number: " << "(" << number << ", int)" << endl;
    ss << "\t- city: " << "(" << "\"" << city << "\"" << ", string)" << endl;
    
    string yamlString = ss.str();
    char* result = new char[yamlString.size() + 1];
    strcpy(result, yamlString.c_str());
    
    return result;
}

/*
    Overriding the YAML deserialzer function. Takes one char* parmater that holds the YAML string. It then deserialzes it for class B, C, and D by using the specific functions for those classes. No return value
 */
void B::YAML_deserializer(char* yamlString)
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
    getline(ss, line);

    getline(ss, tab, '\t');
    
    getline(ss, line, ':');
    getline(ss, line);
    
    cPtr->YAML_deserializer(yamlString);
    
    getline(ss, line, ')');
    getline(ss, line, ')');
    ss.ignore();
    getline(ss, line, '(');
    ss >> number;
    getline(ss, line, '\n');
    
    getline(ss, line, ':');
    getline(ss, line, '"');
    getline(ss, city, '"');
    getline(ss, line);
}

/*
    Overriding the JSON deserialzer function. Takes one char* parmater that holds the JSON string. It then deserialzes it for class B, C, and D by using the specific functions for those classes. No return value
 */
void B::JSON_deserializer(char* jsonString)
{
    stringstream ss(jsonString);
    string line;
    
    getline(ss, line, ',');
    getline(ss, line, ',');
    getline(ss, line, ',');
    getline(ss, line, ',');
    getline(ss, line, ',');
    getline(ss, line, '{');
    
    cPtr->JSON_deserializer(jsonString);
    
    getline(ss, line, '}');
    getline(ss, line, '}');
    getline(ss, line, '}');
    getline(ss, line, '}');
    getline(ss, line, '}');
    getline(ss, line, '{');
    ss >> number;

    getline(ss, line, '"');
    getline(ss, city, '"');
    getline(ss, line);
}

// Destructor for class B releases all allocated memory.
B::~B()
{
    delete cPtr;
    cPtr = nullptr;
    city = nullptr;
    number = 0;
}
