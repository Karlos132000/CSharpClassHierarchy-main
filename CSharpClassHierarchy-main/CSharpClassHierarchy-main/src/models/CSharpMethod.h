#ifndef CSHARPCLASSHIERARCHY_CSHARPMETHOD_H
#define CSHARPCLASSHIERARCHY_CSHARPMETHOD_H

#include <vector>
#include <string>

class CSharpMethod {
private:
    std::string method;
public:
    CSharpMethod();

    explicit CSharpMethod(const std::string method);
    std::string get_method();
};


#endif //CSHARPCLASSHIERARCHY_CSHARPMETHOD_H
