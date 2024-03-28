#ifndef CSHARPCLASSHIERARCHY_CSHARPHIERARCHY_H
#define CSHARPCLASSHIERARCHY_CSHARPHIERARCHY_H

#include <string>
#include <vector>

#include "./models/CSharpField.h"
#include "./models/CSharpMethod.h"
#include "./models/CSharpNamespace.h"
#include "./models/CSharpClass.h"

class CSharpHierarchy {
private:
    std::vector<CSharpClass> cSharpClasses;
    std::vector<CSharpNamespace> cSharpNamespaces;

    int getNamespaceIdByName(std::string namespaceName);
public:
    const std::vector<CSharpClass> &getClasses() const;

    void setClass(CSharpClass cSharpClass);

    const std::vector<CSharpNamespace> &getNamespaces() const;

    void setNamespace(CSharpNamespace namespaces);

    CSharpHierarchy();

    void createNamespace(std::string name);

    CSharpNamespace& getNamespaceByName(const std::string& cSharpNamespaceName);

    void createClass(std::string name, std::vector<CSharpField> fields, std::vector<CSharpMethod> methods, TYPE type);

    void createClass(std::string name, TYPE type);

    CSharpClass& getClassByName(const std::string& cSharpClassName);

    void addClassToNamespace(const std::string& className, const std::string& namespaceName);

    void addParents(CSharpClass& currClass, std::string parentClassName);

    void deleteClassByName(std::string className);

    void deleteNamespaceByName(std::string namespaceName);

    void updateNamespaceByName(std::string namespaceName, std::string newNamespaceName);

    std::string namespacesToString();

    std::string classesToString();

    void updateClassByName(std::string className, std::string newClassName, std::vector<CSharpField> fields,
                           std::vector<CSharpMethod> methods, CSharpClass parent);
};


#endif //CSHARPCLASSHIERARCHY_CSHARPHIERARCHY_H
