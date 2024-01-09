//
//  class_A.hpp
//  serializer
//
//  Created by Ishan Phadke on 12/29/23.
//

#ifndef class_A_hpp
#define class_A_hpp

#include <stdio.h>
#include "serializer.hpp"
#include <iostream>
#include "class_B.hpp"

using namespace std;

// Class A derives from the Serializer class and overrides the JSON and YAMl serialize and deserialize functions. It has four member variables. val1 is an int type variable set to 1 by default. val2 is abouble type variable set to 9.8 by default. name is a string object set to "ishan" by default. bPtr is a B class pointer, which allocates memory by default
    
class A: public Serializer {
private:
    int val1 = 1;
    double val2 = 9.8;
    string name = "ishan";
    B* bPtr = new B;
    
public:
    
    // Constructs an object of class A with the provided string and format parameters.
    A(char* strings, string format);
    
    // Constructs an object of class A with default values.
    A();
    
    // Overrides the base class method to serialize the object to a JSON-formatted string.
    char* JSON_serialize() override;
    
    // Overrides the base class method to serialize the object to a YAML-formatted string.
    char* YAML_serialize(void) override;
    
    // Overrides the base class method to deserialize the object from a YAML-formatted string.
    void YAML_deserializer(char* jsonString) override;
    
    // Overrides the base class method to deserialize the object from a JSON-formatted string.
    void JSON_deserializer(char* jsonString) override;
    
    // Destroys the object of class A.
    virtual ~A();
};




#endif /* class_A_hpp */
