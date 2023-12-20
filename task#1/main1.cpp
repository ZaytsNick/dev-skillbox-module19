#include <iostream>
#include <string>
#include <fstream>

int main()
{
    std::ifstream words;
    std::string word;
    int answer(0);
    words.open("words.txt");
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
    }
    std::cout << "Answer: " << answer << std::endl;
}