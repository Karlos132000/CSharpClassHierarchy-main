#ifndef CSHARPCLASSHIERARCHY_CSHARPCLASS_H
#define CSHARPCLASSHIERARCHY_CSHARPCLASS_H

#include <vector>
#include <string>

#include "CSharpMethod.h"
#include "CSharpField.h"

enum class TYPE {
    BASE,
    DERIVED,
    ABSTRACT
};

class CSharpClass {
private:
    std::string csharpClassName;
    std::vector<CSharpField> fields;
    std::vector<CSharpMethod> methods;
    std::vector<CSharpClass> parentClasses;
    TYPE csharpClassType;
    void implementMethods();
public:
    CSharpClass();

    CSharpClass(std::string csharpClassName,
                TYPE type);

    CSharpClass(std::string csharpClassName,
                TYPE type,
                const std::vector<CSharpClass>& parentClasses);

    CSharpClass(std::string  csharpClassName,
                             std::vector<CSharpField> fields,
                             std::vector<CSharpMethod> methods,
                             TYPE type);

    std::string toString() const;

    void setClassName(std::string csharpClassName);

    void setParentClass(CSharpClass& parentClass);


    void addFields(const std::vector<CSharpField>& fields);

    std::string getClassName() const;

    void setFields(const std::vector<CSharpField> fields);

    void setMethods(const std::vector<CSharpMethod> methods);

    void addMethods(const std::vector<CSharpMethod> &newMethods);

    void setType(TYPE type);

    void setParentClasses(const std::vector<CSharpClass> parentClasses);
};


#endif //CSHARPCLASSHIERARCHY_CSHARPCLASS_H
