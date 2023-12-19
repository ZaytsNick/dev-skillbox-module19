
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int main()
{
    int sum(0);

    std::ifstream DB;
    std::string max_string;
    DB.open("data_base.txt", std::ios::binary);
    if (DB.is_open())
    {
        for (int i = 0; !DB.eof();)
        {
            DB.seekg(i);
            char buffer(0);
            std::string temp_string;
            while (buffer != '\r' && buffer != '\n' && !DB.eof())
            {
                i++;
                DB.read((char *)&buffer, sizeof(buffer));
                if (buffer != '\r')
                    temp_string += buffer;
            }
            i += 3;
            std::stringstream temp_stringstream(temp_string);
            std::stringstream max_stringstream(max_string);
            int temp_int, max_int(0);
            std::string tmp;
            temp_stringstream >> tmp >> tmp >> temp_int;
            max_stringstream >> tmp >> tmp >> max_int;
            sum += temp_int;
            if (temp_int > max_int)
                max_string = temp_string;
        }
    }
    else
        std::cout << "false" << std::endl;
    DB.close();
    std::cout << "Total paid: " << sum << "\nMaximum payout amount: " << max_string << std::endl;
}