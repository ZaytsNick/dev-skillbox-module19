#include <iostream>
#include <fstream>
#include <string>
int main()
{
    std::string path;
    std::cout << "Enter path: ";
    std::cin >> path;
    std::ifstream PNG_file;

    PNG_file.open(path, std::ios::binary);
    if (PNG_file.is_open())
    {
        std::string extension;
        for (int i = path.size() - 1; path[i] != '.'; i--)
        {
            char simbol = path[i];
            extension = simbol + extension;
        }
        if (extension == "png")
            std::cout << "This file has extension .png" << std::endl;
        else
            std::cout << "ERROR: This file doesn't have extension .png" << std::endl;
        char first_four_byte[4];
        PNG_file.read(first_four_byte, sizeof(first_four_byte));
        if (first_four_byte[0] == -119 &&
            first_four_byte[1] == 'P' &&
            first_four_byte[2] == 'N' &&
            first_four_byte[3] == 'G')
        {
            std::cout << "File " << path << " is in PNG format" << std::endl;
        }
        else
        {
            std::cout << "ERROR: Analysis showed that this file is not in PNG format" << std::endl;
        }
    }
}

