//
//  class_C.cpp
//  serializer
//
//  Created by Ishan Phadke on 12/29/23.
//

#include "class_C.hpp"
#include <sstream>
#include <iostream>
#include <iostream>
#include "class_D.hpp"

using namespace std;

// Defualt constructor simply allocates space for dPtr
C::C()
{
    dPtr = new D;
}

/*
 Overriding the JSON serializer function. Takes no parameters and returns a char* with the whole serialized string for class class C, and D.
 */
char* C::JSON_serialize()
{
    stringstream ss;
    ss << "{Class C," << endl << endl;
    ss << "\t\t\t\t\"dPtr\": " << dPtr->JSON_serialize() << "," << endl;
    ss << "\t\t\t\t\"num\": " << "{" << num << ", double}" << endl << endl;
    ss << "\t\t\t}";

    string jsonString = ss.str();
    char* result = new char[jsonString.size() + 1];
    strcpy(result, jsonString.c_str());

    return result;
}

/*
    Overriding the YAML serializer function. Takes no parameters and returns a char* with the whole serialized string for class class C, and D.
 */
char* C::YAML_serialize(void){
    
    stringstream ss;
    
    ss << "\t\t- dPtr: " << endl;
    ss << "\t\t\tClass D" << endl << endl;
    ss << dPtr->YAML_serialize();
    ss << "\t\t- num: " << "(" << num << ", double)"<< endl;
    
    string yamlString = ss.str();
    char* result = new char[yamlString.size() + 1];
    strcpy(result, yamlString.c_str());
    
    return result;
}

/*
    Overriding the YAML deserialzer function. Takes one char* parmater that holds the YAML string. It then deserialzes it for class C, and D by using the specific functions for those classes. No return value
 */
void C::YAML_deserializer(char* yamlString)
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

    
    dPtr->YAML_deserializer(yamlString);


    getline(ss, line, ')');
    ss.ignore();
    getline(ss, line, '(');
    ss >> num;
    getline(ss, line, '\n');
}

/*
    Overriding the JSON deserialzer function. Takes one char* parmater that holds the JSON string. It then deserialzes it for class C, and D by using the specific functions for those classes. No return value
 */
void C::JSON_deserializer(char* jsonString)
{
    stringstream ss(jsonString);
    string line, tab;

    getline(ss, line, ',');
    getline(ss, line, ',');
    getline(ss, line, ',');
    getline(ss, line, ',');
    getline(ss, line, ',');
    getline(ss, line, ',');
    getline(ss, line, '{');
    
    dPtr->JSON_deserializer(jsonString);
    
    getline(ss, line, '}');
    getline(ss, line, '}');
    getline(ss, line, '{');
    ss >> num;
}

// Destructor for class C releases all allocated memory.
C::~C()
{
    delete dPtr;
    dPtr = nullptr;
    num = 0.0;
}
