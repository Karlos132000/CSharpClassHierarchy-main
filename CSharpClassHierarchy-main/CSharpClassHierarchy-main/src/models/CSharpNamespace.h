#ifndef CSHARPCLASSHIERARCHY_CSHARPNAMESPACE_H
#define CSHARPCLASSHIERARCHY_CSHARPNAMESPACE_H

#include <string>
#include <vector>

#include "CSharpClass.h"

class CSharpNamespace {
private:
    std::string name;
    std::vector<CSharpClass> classes;
public:
    CSharpNamespace();
    CSharpNamespace(std::string name, CSharpClass childClass);
    CSharpNamespace(std::string name);
    std::string getName() const;

    void addClass(CSharpClass childClass);

    const std::vector<CSharpClass>& getClasses() const;

    void setName(std::string namespaceName);

    std::string toString() {
        std::string res;
        res.append(name + ": [\n");
        for (const CSharpClass& cls: classes) {
            res.append(cls.toString());
        }
        res.append("\n]");
        return res;
    }
};

#endif //CSHARPCLASSHIERARCHY_CSHARPNAMESPACE_H
