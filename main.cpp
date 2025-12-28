#include <iostream>
#include <bitset>
#include <sstream>

using namespace std;
//TODO: Add better error handling.
//User can enter anything, this means that when user enters something other than bunch of 1 and 0 program crashes

// Function to convert binary to hexadecimal
string binaryToHexadecimal(string binary)
{
    // Add leading zeros to ensure the binary length is a multiple of 4
    while (binary.length() % 4 != 0)
    {
        binary = "0" + binary;
    }

    stringstream hexResult;

    // Process 4 binary digits at a time
    for (size_t i = 0; i < binary.length(); i += 4)
    {
        bitset<4> bits(binary.substr(i, 4));
        hexResult << hex << uppercase << bits.to_ulong();
    }

    return hexResult.str();
}

int main()
{
    string binary;

    // Input binary number
    cout << "Enter a binary number: ";
    cin >> binary;

    // Convert to hexadecimal
    string hexadecimal = binaryToHexadecimal(binary);

    // Output the result
    cout << "Hexadecimal: " << hexadecimal << endl;

    return 0;
}
