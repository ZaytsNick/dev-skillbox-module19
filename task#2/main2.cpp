#include <iostream>
#include <string>
#include <fstream>

int main()
{
    std::string path;
    std::cout << "Enter path: ";
    std::cin >> path;
    std::ifstream file;
    file.open(path,std::ios::binary);
    if (file.is_open())
    {
        while (!file.eof())
        {
            char buffer[1000];  
            file.read(buffer,sizeof(buffer)-1);
            buffer[file.gcount()]=0;
            std::cout<<buffer;
        }
    }
    else
        std::cout << "false" << std::endl;
}