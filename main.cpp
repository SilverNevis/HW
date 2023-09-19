#include "IntegerArray.h"
#include <iostream>

int main() {
    try {
        IntegerArray arr;
        arr.insert(0, 45);
        arr.insert(1, 50);
        arr.insert(2, 62);

        std::cout << "IntegerArray Demo" << std::endl;
        std::cout << "Initial Array:" << std::endl;
        std::cout << "Array size: " << arr.getSize() << std::endl;
        for (int i = 0; i < arr.getSize(); ++i) {
            std::cout << "Element " << i << ": " << arr.getElementAt(i) << std::endl;
        }

        int indexToRemove = 1;
        if (indexToRemove >= 0 && indexToRemove < arr.getSize()) {
            arr.remove(indexToRemove);
            std::cout << "After removing element at index " << indexToRemove << ":" << std::endl;
            std::cout << "Array size: " << arr.getSize() << std::endl;
            for (int i = 0; i < arr.getSize(); ++i) {
                std::cout << "Element " << i << ": " << arr.getElementAt(i) << std::endl;
            }
        }
        else {
            std::cerr << "Error: Index to remove is out of range" << std::endl;
        }

        int indexToAccess = 1; 

        if (indexToAccess >= 0 && indexToAccess < arr.getSize()) {
            std::cout << "Accessing element at index " << indexToAccess << ": " << arr.getElementAt(indexToAccess) << std::endl;
        }
        else {
            std::cerr << "Error: Index to access is out of range" << std::endl;
        }

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}