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
<<<<<<< HEAD
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
=======
        char first_byte;
        PNG_file.read((char *)&first_byte, sizeof(first_byte));
        if (first_byte != -119)
        {
            std::cout << "ERROR: Analysis showed that this file is not in PNG format" << std::endl;
            return 0;
        }
        else
        {
            char second_byte;
            std::string temp_string;
            for (int i = 0; i < 4; i++)
            {
                PNG_file.seekg(i + 1);
                PNG_file.read((char *)&second_byte, sizeof(second_byte));
                if (second_byte != '\r')
                temp_string += second_byte;
            }
            if (temp_string != "PNG")
            {
                std::cout << "ERROR: Analysis showed that this file is not in PNG format" << std::endl;
                return 0;
            }
        }
    }
    else
        std::cout << "ERROR: The file did not open!" << std::endl;
    PNG_file.close();
    std::cout << "File " << path << " is in PNG format" << std::endl;
}
>>>>>>> 18f2225deb56b1ca130d9887686132914c7ad27a
