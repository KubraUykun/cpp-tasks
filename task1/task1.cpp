#include <iostream>  // for std::cin and std::cout 


// Function to update the values of 'a' and 'b' based on the specified logic
void update(int& a, int& b) {
    a += b;
    // Update b based on the comparison of a and b
    b = (a < b) ? (b-a) : (a-b);  
}

int main() {   
    int a; // Variable to hold the first user input
    int b; // Variable to hold the second user input
    
    // Prompt user to enter the first number and read it
    std::cout << "Enter a number: \n";
    std::cin >> a;
    // Prompt user to enter the second number and read it
    std::cout << "Enter another number: \n";
    std::cin >> b;

    std::cout << "a before update: " << a << "\n";
    std::cout << "b before update: " << b << "\n";

    update(a, b);
    
    std::cout << "a after update: " << a << "\n";
    std::cout << "b after update: " << b << "\n";
    return 0;
}