/*******************************************************************************
 * Creator: Hemajun
 * Description: 字符串翻转
*******************************************************************************/
#include <iostream>
#include <string>
#include <regex>

auto solution(const std::string &s_in) -> std::string
{
    std::regex reg("[a-z|A-Z|0-9]*[- ,.']{1}");
    std::string s_out = "";
    std::sregex_iterator it(s_in.begin(), s_in.end(), reg);
    while (it != std::sregex_iterator())
    {
        std::string s_word = it->str();
        if (s_word.length() > 1)
            s_word = s_word.substr(s_word.length() - 1) + s_word.substr(0, s_word.length() - 1);
        s_out = s_word + s_out;
        it++;
    }
    return s_out;
}

int main(int argc, char const *argv[])
{
    std::cout << solution("Zhou Guoqiang, spokesman for the State-owned aviation conglomerate, which is headquartered in Beijing, said that subcontractors started manufacturing the MA-700's components in December and some of them are set to begin delivering major parts for the aircraft's airframe this month.")
              << std::endl
              << solution("Radio and television are very popular in the world today. Millions of people watch TV. Perhaps more people listen to the radio.")
              << std::endl;
    return 0;
}