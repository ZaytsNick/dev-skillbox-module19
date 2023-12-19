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
<<<<<<< HEAD
            char buffer[1000];  
            file.read(buffer,sizeof(buffer)-1);
            buffer[file.gcount()]=0;
=======
            char buffer;
            file.read((char*)&buffer,sizeof(buffer));
            if(file.gcount())
>>>>>>> 18f2225deb56b1ca130d9887686132914c7ad27a
            std::cout<<buffer;
        }
    }
    else
        std::cout << "false" << std::endl;
}