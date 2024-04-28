#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

// Function to append user input to the existing data in the file
void appendToFile(const std::string &filename, const std::string &data)
{
    std::ofstream file(filename, std::ios::app);
    if (file.is_open())
    {
        file << data << std::endl;
        file.close();
        std::cout << "Data appended to file successfully." << std::endl;
    }
    else
    {
        std::cerr << "Unable to open the file for appending." << std::endl;
    }
}

// Function to reverse the content of a file
void reverseFile(const std::string &inputFilename, const std::string &outputFilename)
{
    std::ifstream inputFile(inputFilename);
    if (inputFile.is_open())
    {
        std::string content((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
        std::reverse(content.begin(), content.end());

        std::ofstream outputFile(outputFilename);
        if (outputFile.is_open())
        {
            outputFile << content;
            outputFile.close();
            std::cout << "File reversed and saved to " << outputFilename << " successfully." << std::endl;
        }
        else
        {
            std::cerr << "Unable to open the output file for writing." << std::endl;
        }

        inputFile.close();
    }
    else
    {
        std::cerr << "Unable to open the input file for reading." << std::endl;
    }
}

int main()
{
    std::string userInput;
    std::cout << "Enter data to append to the file: ";
    std::getline(std::cin, userInput);

    appendToFile("CSC450_CT5_mod5.txt", userInput);

    reverseFile("CSC450_CT5_mod5.txt", "CSC450-mod5-reverse.txt");

    return 0;
}
