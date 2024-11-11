#include <iostream>

using namespace std; 

#define MAX_DIM 10 

// Function to calculate address in row-major order
int calculateRowMajorAddress(int baseAddress, int elementSize, int dimensions[], int indices[], int numDimensions) {
    int offset = 0;
    for (int i = 0; i < numDimensions; i++) {
        int product = 1;
        for (int j = i + 1; j < numDimensions; j++) {
            product *= dimensions[j];
        }
        offset += indices[i] * product;
    }
    return baseAddress + elementSize * offset;
}

// Function to calculate address in column-major order
int calculateColumnMajorAddress(int baseAddress, int elementSize, int dimensions[], int indices[], int numDimensions) {
    int offset = 0;
    for (int i = 0; i < numDimensions; i++) {
        int product = 1;
        for (int j = 0; j < i; j++) {
            product *= dimensions[j];
        }
        offset += indices[i] * product;
    }
    return baseAddress + elementSize * offset;
}

int main() {
    int numDimensions;
    int dimensions[MAX_DIM], indices[MAX_DIM];
    int baseAddress, elementSize;
    char order;

    // Taking inputs from the user
    cout << "Enter the base address of the array: ";
    cin >> baseAddress;
    cout << "Enter the element size (in bytes): ";
    cin >> elementSize;
    cout << "Enter the number of dimensions: ";
    cin >> numDimensions;

    cout << "Enter the dimensions:\n";
    for (int i = 0; i < numDimensions; i++) {
        cout << "Dimension " << i + 1 << ": ";
        cin >> dimensions[i];
    }

    cout << "Enter the indices of the element to find the address:\n";
    for (int i = 0; i < numDimensions; i++) {
        cout << "Index " << i + 1 << ": ";
        cin >> indices[i];
    }

    cout << "Enter 'R' for row-major or 'C' for column-major order: ";
    cin >> order;

    // Calculate address based on row-major or column-major order
    int address;
    if (order == 'R' || order == 'r') {
        address = calculateRowMajorAddress(baseAddress, elementSize, dimensions, indices, numDimensions);
    } else if (order == 'C' || order == 'c') {
        address = calculateColumnMajorAddress(baseAddress, elementSize, dimensions, indices, numDimensions);
    } else {
        cout << "Invalid order specified.\n";
        return 1;
    }

    // Output the result
    cout << "The address of the element is: " << address << endl;

    return 0;
}
