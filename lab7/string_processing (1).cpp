#include <iostream>
#include <stack>
#include <string>
#include <algorithm> // For reverse function
using namespace std;

int main() {
    string input;
    cout << "Enter the input string: ";
    getline(cin, input);

    // Using stack ADT for optimal processing of the string.
    stack<char> st;

    // Process each character in the input string
    for (char ch : input) {
        if (ch == '+') {
            if (!st.empty()) {
                st.pop();  // Remove the immediate left non-'+' character.
            }
        } else {
            st.push(ch); // Add current character to the stack.
        }
    }

    // Since stack gives characters in reverse order, we need to reverse them.
    string result;
    while (!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }
    reverse(result.begin(), result.end());

    cout << "Output: " << result << endl;
    return 0;
}

/*
Time Complexity Analysis:
- The solution iterates through each character of the input string exactly once. 
- Each push and pop operation on the stack is O(1).
- Thus, the overall time complexity is O(n), where n is the length of the string.

ADT and Data Structure:
- ADT: Stack (Last-In-First-Out behavior is ideal for removing the immediate left element when encountering '+').
- Data Structure: The C++ STL stack is used for its simplicity and efficiency in handling push and pop operations.

Optimality Justification:
- The stack-based approach is optimal because it allows for processing the string in a single pass (O(n) time) and naturally handles the requirement to remove the character immediately preceding a '+'.
- Alternative solutions might involve repeated string manipulations (which can lead to higher time complexities), whereas using a stack maintains a constant time per operation with minimal extra space.
*/ 
