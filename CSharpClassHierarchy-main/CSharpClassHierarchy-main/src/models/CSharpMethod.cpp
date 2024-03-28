#include "CSharpMethod.h"

CSharpMethod::CSharpMethod() { }

CSharpMethod::CSharpMethod(const std::string method) : method(method) {}

std::string CSharpMethod::get_method() {
    return method;
}

