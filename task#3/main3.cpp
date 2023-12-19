
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int main()
{
<<<<<<< HEAD
    int sum(0), max_money(0);
=======
    int sum(0);
>>>>>>> 18f2225deb56b1ca130d9887686132914c7ad27a

    std::ifstream DB;
    std::string max_string;
    DB.open("data_base.txt", std::ios::binary);
    if (DB.is_open())
    {
        for (int i = 0; !DB.eof();)
        {
<<<<<<< HEAD
            std::stringstream max_stringstream(max_string);
            int temp_money;
            std::string tmp,temp_name,temp_surname,temp_date;

            DB >> temp_name >> temp_surname >> temp_money>>temp_date;
            max_stringstream >> tmp >> tmp>>max_money;
            sum += temp_money;
            if (temp_money > max_money)
                max_string = temp_name+" "+temp_surname+" "+std::to_string(temp_money)+" "+temp_date;
=======
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
>>>>>>> 18f2225deb56b1ca130d9887686132914c7ad27a
        }
    }
    else
        std::cout << "false" << std::endl;
    DB.close();
    std::cout << "Total paid: " << sum << "\nMaximum payout amount: " << max_string << std::endl;
<<<<<<< HEAD
    std::cout<<"end";
=======
>>>>>>> 18f2225deb56b1ca130d9887686132914c7ad27a
}