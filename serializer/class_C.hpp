//
//  class_C.hpp
//  serializer
//
//  Created by Ishan Phadke on 12/29/23.
//

#ifndef class_C_hpp
#define class_C_hpp

#include <stdio.h>
#include "serializer.hpp"
#include "class_D.hpp"

// Class C derives from the Serializer class and overrides the JSON and YAMl serialize and deserialize functions. It has two member variables. dPtr is D class pointer, num is a double type variable set to 65.4 by default
class C : public Serializer{
private:
    D* dPtr;
    double num = 65.4;
public:
    
    // Constructs an object of class C with default values.
    C();
    
    // Overrides the base class method to serialize the object to a JSON-formatted string.
    char * JSON_serialize() override;
    
    // Overrides the base class method to serialize the object to a YAML-formatted string.
    char* YAML_serialize(void) override;
    
    // Overrides the base class method to deserialize the object from a YAML-formatted string.
    void YAML_deserializer(char* yamlString) override;
    
    // Overrides the base class method to deserialize the object from a JSON-formatted string.
    void JSON_deserializer(char* jsonString) override;
    
    // Destroys the object of class C.
    virtual ~C();
};

#endif /* class_C_hpp */
