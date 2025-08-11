#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <functional>
#include <cassert>

// Function to generate the color map
std::vector<std::tuple<int, std::string, std::string>> generateColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

    std::vector<std::tuple<int, std::string, std::string>> colorMap;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            colorMap.emplace_back(i * 5 + j, majorColor[i], minorColor[j]);
        }
    }
    return colorMap;
}

// Function to format each color map entry
std::string formatColorMapEntry(int index, const std::string& major, const std::string& minor) {
    return std::to_string(index) + " | " + major + " | " + minor;
}

// Function to print a line of content
void printOnConsole(const std::string& lineContent) {
    std::cout << lineContent << std::endl;
}

// Function to print the entire color map
int printColorMap(const std::function<void(const std::string&)>& outputFunc) {
    auto colorMap = generateColorMap();
    for (const auto& [index, major, minor] : colorMap) {
        outputFunc(formatColorMapEntry(index, major, minor));
    }
    return static_cast<int>(colorMap.size());
}

// Test environment
std::vector<std::string> capturedLines;
std::vector<std::string> expectedLines = {
    "0 | White | Blue", "1 | White | Orange", "2 | White | Green", "3 | White | Brown", "4 | White | Slate",
    "5 | Red | Blue", "6 | Red | Orange", "7 | Red | Green", "8 | Red | Brown", "9 | Red | Slate",
    "10 | Black | Blue", "11 | Black | Orange", "12 | Black | Green", "13 | Black | Brown", "14 | Black | Slate",
    "15 | Yellow | Blue", "16 | Yellow | Orange", "17 | Yellow | Green", "18 | Yellow | Brown", "19 | Yellow | Slate",
    "20 | Violet | Blue", "21 | Violet | Orange", "22 | Violet | Green", "23 | Violet | Brown", "24 | Violet | Slate"
};

// Fake output function to capture printed lines
void fakeOutputFunc(const std::string& lineContent) {
    capturedLines.push_back(lineContent);
}

// Test function to verify the color map printing
void testPrintColorMap() {
    std::cout << "\nPrint color map test\n";

    int result = printColorMap(fakeOutputFunc);

    assert(result == 25); // value-based test
    assert(capturedLines == expectedLines);
    std::cout << "All is well (maybe!)\n";
}

int main() {
    testPrintColorMap();
    return 0;
}
