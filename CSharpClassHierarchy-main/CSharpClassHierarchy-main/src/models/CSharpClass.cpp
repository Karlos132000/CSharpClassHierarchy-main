#include "CSharpClass.h"

#include <utility>

CSharpClass::CSharpClass() = default;

CSharpClass::CSharpClass(const std::string csharpClassName, TYPE type) :
        csharpClassName(csharpClassName),
        csharpClassType(type) { }

CSharpClass::CSharpClass(std::string  csharpClassName,
                         std::vector<CSharpField> fields,
                         std::vector<CSharpMethod> methods,
                         TYPE type) :
        csharpClassName(std::move(csharpClassName)),
        fields(std::move(fields)),
        methods(std::move(methods)),
        csharpClassType(type) { }

CSharpClass::CSharpClass(const std::string csharpClassName,
                         TYPE type,
                         const std::vector<CSharpClass>& parentClasses) :
        csharpClassName(csharpClassName),
        csharpClassType(type),
        parentClasses(parentClasses) {
    if (!parentClasses.empty() && type != TYPE::ABSTRACT) {
        implementMethods();
    }
}

std::string CSharpClass::toString() const {
    std::string res;
    res.append("Class: " + csharpClassName + "\n");
    for (const CSharpClass &cls: parentClasses) {
        res.append("Parent class: " + cls.csharpClassName + "\n");
    }
    res.append("Type: ");
    if (csharpClassType == TYPE::ABSTRACT) {
        res.append("abstract\n");
    } else {
        res.append("common\n");
    }
    res.append("Fields: {\n");
    for (CSharpField fld: fields) {
        res.append("\t" + fld.getField() + "\n");
    }
    res.append("}\nMethods: {\n");
    for (CSharpMethod mtd: methods) {
        res.append("\t" + mtd.get_method() + "\n");
    }
    res.append("}\n");
    return res;
}

void CSharpClass::implementMethods() {
    for (const CSharpClass &cls: parentClasses) {
        for (const CSharpMethod &method: cls.methods) {
            this->methods.emplace_back(method);
        }
    }
}


void CSharpClass::setClassName(const std::string className) {
    CSharpClass::csharpClassName = className;
}

void CSharpClass::setParentClasses(const std::vector<CSharpClass> parentClasses) {
    implementMethods();
    CSharpClass::parentClasses = parentClasses;
}

void CSharpClass::setParentClass(CSharpClass& parentClass) {
    this->parentClasses.emplace_back(parentClass);
    if (csharpClassType != TYPE::ABSTRACT) {
        implementMethods();
    }
}

void CSharpClass::setFields(const std::vector<CSharpField> fields) {
    CSharpClass::fields = fields;
}

void CSharpClass::addFields(const std::vector<CSharpField>& newFields) {
    for (const CSharpField& fld: newFields) {
        fields.emplace_back(fld);
    }
}

void CSharpClass::setMethods(const std::vector<CSharpMethod> methods) {
    CSharpClass::methods = methods;
}

void CSharpClass::addMethods(const std::vector<CSharpMethod>& newMethods) {
    for (const CSharpMethod& mtd: newMethods) {
        methods.emplace_back(mtd);
    }
}

void CSharpClass::setType(TYPE type) {
    CSharpClass::csharpClassType = type;
}

std::string CSharpClass::getClassName() const {
    return csharpClassName;
}
