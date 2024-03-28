//
// Created by Carlos on 20.03.2024.
//

#include "runTests.h"
#include <iostream>
#include "CSharpHierarchy.h"

// Function to run simple tests
void runTests() {
    // Create an instance of CSharpHierarchy
    CSharpHierarchy hierarchy;

    // Test creating a namespace
    hierarchy.createNamespace("Namespace1");

    // Test creating a class
    std::vector<CSharpField> fields;
    fields.emplace_back("int x;");
    std::vector<CSharpMethod> methods;
    methods.emplace_back("void method1();");
    hierarchy.createClass("Class1", fields, methods, TYPE::BASE);

    // Test adding a class to a namespace
    hierarchy.addClassToNamespace("Class1", "Namespace1");

    // Test getting namespaces and classes
    const auto& namespaces = hierarchy.getNamespaces();
    for (const auto& ns : namespaces) {
        std::cout << "Namespace: " << ns.getName() << std::endl;
        const auto& classes = ns.getClasses();
        for (const auto& cls : classes) {
            std::cout << "Class: " << cls.getClassName() << std::endl;
        }
    }
}


