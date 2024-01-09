//
//  main.cpp
//  serializer
//
//  Created by Ishan Phadke on 12/26/23.
//

#include <iostream>
#include <sstream>
#include "serializer.hpp"
#include "class_D.hpp"
#include "class_C.hpp"
#include "class_B.hpp"
#include "class_A.hpp"


int main(int argc, const char * argv[]) {
    
    A a;
    
    char* s = a.YAML_serialize();
   
    cout << endl << "YAML: " << endl << s << endl;
    
    A* a1 = new A(s, "YAML");
    
    cout << a1->YAML_serialize();
    
    char* m = a.JSON_serialize();
    
    cout << "JSON: " << endl << a.JSON_serialize() << endl;
    
    A* a2 = new A(m, "JSON");
    
    cout << a2->JSON_serialize() << endl;
    
    
    
    /*string serialized_yaml = "---\nClass A\n\nval1: (45, int)\nval2: (99.86, double)\nname: (\"Ishan\", string)\nbPtr:\n\tClass B\n\n\t- cPtr:\nClass C\n\n\t\t- dPtr:\nClass D\n\n\t\t\t- array:\n\t\t\t\t- 4\n\t\t\t\t- 5\n\t\t\t\t- 6\n\t\t\t- size: (3, int)\n\t\t- num: (134.5, double)\n\t- number: (53, int)\n\t- city: (\"New York\", string)";
    
    char* modifiedYaml = &serialized_yaml[0];
    
    a.YAML_deserializer(modifiedYaml);
    
    cout << endl << "YAML: " << endl << a.YAML_serialize() << endl;*/
    
    return 0;
}
