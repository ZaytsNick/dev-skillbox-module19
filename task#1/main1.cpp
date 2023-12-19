#include <iostream>
#include <string>
#include <fstream>

int main()
{
    std::ifstream words;
    std::string word;
<<<<<<< HEAD
    int answer(0);
    words.open("wordss.txt");
    if (words.is_open())
    {
        std::cout << "Enter the word you want to find: ";
        std::cin >> word;
        while (!words.eof())
        {
            std::string temp_word;
            words >> temp_word;
            if (temp_word == word)
                answer++;
        }
    }
    else
    {
        std::cout << "ERROR: The file did not open!" << std::endl;
        return 0;
=======
    std::cout << "Enter the word you want to find: ";
    std::cin >> word;
    int answer(0);
    words.open("words.txt");
    while (!words.eof())
    {
        std::string temp_word;
        words >> temp_word;
        if (temp_word == word)
            answer++;
>>>>>>> 18f2225deb56b1ca130d9887686132914c7ad27a
    }
    std::cout << "Answer: " << answer << std::endl;
}