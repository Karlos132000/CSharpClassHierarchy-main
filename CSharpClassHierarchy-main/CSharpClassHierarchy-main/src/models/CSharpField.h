#ifndef CSHARPCLASSHIERARCHY_CSHARPFIELD_H
#define CSHARPCLASSHIERARCHY_CSHARPFIELD_H

#include <vector>
#include <string>

class CSharpField {
private:
    std::string field;
public:
    CSharpField();
    CSharpField(std::string field);
    std::string getField();
};


#endif //CSHARPCLASSHIERARCHY_CSHARPFIELD_H
