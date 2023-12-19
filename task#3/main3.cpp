
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int main()
{
    int sum(0), max_money(0);
    std::ifstream DB;
    std::string max_string;
    DB.open("data_base.txt", std::ios::binary);
    if (DB.is_open())
    {
        for (int i = 0; !DB.eof();)
        {
            std::stringstream max_stringstream(max_string);
            int temp_money;
            std::string tmp, temp_name, temp_surname, temp_date;

            DB >> temp_name >> temp_surname >> temp_money >> temp_date;
            max_stringstream >> tmp >> tmp >> max_money;
            sum += temp_money;
            if (temp_money > max_money)
                max_string = temp_name + " " + temp_surname + " " + std::to_string(temp_money) + " " + temp_date;
        }
    }
    else
        std::cout << "false" << std::endl;
    DB.close();
    std::cout << "Total paid: " << sum << "\nMaximum payout amount: " << max_string << std::endl;
}