//
//  class_B.hpp
//  serializer
//
//  Created by Ishan Phadke on 12/29/23.
//

#ifndef class_B_hpp
#define class_B_hpp

#include <stdio.h>
#include "class_C.hpp"
#include <iostream>

// Class B derives from the Serializer class and overrides the JSON and YAMl serialize and deserialize functions. It has three member variables. cPtr is C class pointer, number is an int type variable set to 87 by default. city is a string type variable set to "Boston" by defualt
class B : public Serializer{
private:
    C* cPtr;
    int number = 87;
    string city = "Boston";
    
public:
    
    // Constructs an object of class B with default values.
    B();
    
    // Overrides the base class method to serialize the object to a JSON-formatted string.
    char * JSON_serialize() override;
    
    // Overrides the base class method to serialize the object to a YAML-formatted string.
    char* YAML_serialize(void) override;
   
    // Overrides the base class method to deserialize the object from a YAML-formatted string.
    void YAML_deserializer(char* yamlString) override;
    
    // Overrides the base class method to deserialize the object from a JSON-formatted string.
    void JSON_deserializer(char* jsonString) override;
    
    // Destroys the object of class B.
    virtual ~B();
};

#endif /* class_B_hpp */
