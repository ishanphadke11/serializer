//
//  class_D.hpp
//  serializer
//
//  Created by Ishan Phadke on 12/29/23.
//

#ifndef class_D_hpp
#define class_D_hpp
#include "serializer.hpp"

#include <stdio.h>

// Class D derives from the Serializer class and overrides the JSON and YAMl serialize and deserialize functions. It has two member variables. array is a dynamic integer array
class D : public Serializer{
private:
    int* array;
    int size;
public:
    
    // Constructs an object of class D with default values.
    D();
    
    // Overrides the base class method to serialize the object to a JSON-formatted string.
    char* JSON_serialize() override;
    
    // Overrides the base class method to serialize the object to a YAML-formatted string.
    char* YAML_serialize(void) override;

    // Overrides the base class method to deserialize the object from a YAML-formatted string.
    void YAML_deserializer(char* yamlString) override;
    
    // Overrides the base class method to deserialize the object from a JSON-formatted string.
    void JSON_deserializer(char* jsonString) override;
    
    // Destroys the object of class D.
    virtual ~D();
};

#endif /* class_D_hpp */
