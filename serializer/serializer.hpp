//
//  serializer.hpp
//  serializer
//
//  Created by Ishan Phadke on 12/29/23.
//

#ifndef serializer_hpp
#define serializer_hpp

#include <stdio.h>

using namespace std;

// Abstract class has no member functions. It is used to derive classes that overload the JSON serializer/deseializer and YAML serializer/deserializer
class Serializer {
    virtual char* JSON_serialize(void) = 0;
    virtual char* YAML_serialize(void) = 0;
    virtual void YAML_deserializer(char* yamlString) = 0;
    virtual void JSON_deserializer(char* jsonString) = 0;
};

#endif /* serializer_hpp */
