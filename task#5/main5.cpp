#include <iostream>
#include <fstream>
#include <string>
<<<<<<< HEAD
// std::string return_string(int *spin, std::string path)
// {
//     std::string str;
//     std::ifstream file;
//     file.open(path, std::ios::binary);
//     {
//         int start_sector(0);
//         for (int i = 0; i < *spin;)
//         {
//             char buffer;
//             start_sector++;
//             file.read((char *)&buffer, sizeof(buffer));
//             if (buffer == '\n')
//             {
//                 i++;
//             }
//         }
//         char buffer = '0';
//         file.seekg(start_sector);
//         while (true)
//         {
//             // char buffer;
//             file.read((char *)&buffer, sizeof(buffer));
//             if (buffer == '\r' || buffer == '\n' || file.eof())
//                 break;
//             else
//                 str += buffer;
//         }
//     }
//     file.close();
//     return str;
// }
=======
>>>>>>> 18f2225deb56b1ca130d9887686132914c7ad27a
std::string return_string(int *spin, std::string path)
{
    std::string str;
    std::ifstream file;
    file.open(path, std::ios::binary);
    {
        int start_sector(0);
<<<<<<< HEAD
        
        
=======
        for (int i = 0; i < *spin;)
        {
            char buffer;
            start_sector++;
            file.read((char *)&buffer, sizeof(buffer));
            if (buffer == '\n')
            {
                i++;
            }
        }
>>>>>>> 18f2225deb56b1ca130d9887686132914c7ad27a

        char buffer = '0';
        file.seekg(start_sector);
        while (true)
        {
            // char buffer;
            file.read((char *)&buffer, sizeof(buffer));
            if (buffer == '\r' || buffer == '\n' || file.eof())
                break;
            else
                str += buffer;
        }
    }
    file.close();
    return str;
}
<<<<<<< HEAD

=======
>>>>>>> 18f2225deb56b1ca130d9887686132914c7ad27a
bool play(bool sector[],int& spiner)
{
    int spin(0);
    std::cout << "Player enter spin: ";
    std::cin >> spin;
    spiner = (spiner + spin) % 12;
    while (!sector[spiner])
    {
        spiner = (spiner + 1) % 12;
    }

    sector[spiner] = false;
    std::cout << "Sector " << spiner + 1 << " question from a viewer:\n"
              << return_string(&spiner, "ask.txt");

    std::cout << "\nPlayer enter the answer to the question: " << std::endl;
    std::string answer_player;
    std::cin >> answer_player;
    std::string correct_answer = return_string(&spiner, "answer.txt");
    if (answer_player == correct_answer)
    {
        std::cout << "Your answer is correct!" << std::endl;
        return true;
    }
    else
    {
        std::cout << "Your answer is incorrect, the correct answer is: " << correct_answer << std::endl;
        return false;
    }
}

int main()
{
    int tv_viewers(0), player(0), spiner(0);

    bool sectors[12] = {true, true, true, true, true, true, true, true, true, true, true, true};
    while (tv_viewers != 6 && player != 6)
    {
        if (play(sectors, spiner))
            player++;
        else
            tv_viewers++;
    }
    std::cout << "Winner: " << ((tv_viewers == 6) ? "TV Viewers" : "Player");
}