//
// Created by FloatingOcean on 25-5-20.
//

#include <algorithm>
#include <iostream>
#include <string>
#include <map>

std::map<std::string, std::string> colors = {
    {"NR", "black"},    // Not Rated
    {"N", "gray"},      // Newbie
    {"P", "green"},     // Pupil
    {"S", "#03a89e"},   // Specialist
    {"E", "blue"},      // Expert
    {"CM", "#aa00aa"},  // Candidate Master
    {"M", "#ff8c00"},   // Master
    {"IM", "#ff8c00"},  // International Master
    {"GM", "red"},      // Grandmaster
    {"LGM", "red"},     // Legendary Grandmaster
    {"4K", "black"},    // Rating 4K+
};

std::map<std::string, std::string> initial_colors = {
    {"LGM", "black"},   // Legendary Grandmaster
    {"4K", "red"},      // Rating 4K+
};

std::string separator = "、";

int main() {
    int n;
    std::cin >> n;

    for (int i = 1; i <= n; i++) {
        std::string handle, dan;
        std::cin >> handle >> dan;

        std::ranges::transform(dan, dan.begin(), ::toupper);

        std::string color = colors["NR"];
        if (colors.contains(dan)) color = colors[dan];

        if (dan != "LGM" && dan != "4K") {
            std::cout << "<a href=\"https://codeforces.com/profile/"
                      << handle
                      << R"(" target="_blank"><span style="color:)"
                      << color
                      << R"(;"><span style="font-weight:600;">)"
                      << handle
                      << "</span></span></a>";
        } else {
            std::cout << "<a href=\"https://codeforces.com/profile/"
                      << handle
                      << R"(" target="_blank"><span style="color:)"
                      << initial_colors[dan]
                      << R"(;"><span style="font-weight:600;">)"
                      << handle[0]
                      << "</span></span><span style=\"color:"
                      << color
                      << R"(;"><span style="font-weight:600;">)"
                      << handle.substr(1, handle.size() - 1)
                      << "</span></span></a>";
        }

        if (i < n) std::cout << separator;
        else std::cout << '\n';
    }

    return 0;
}
