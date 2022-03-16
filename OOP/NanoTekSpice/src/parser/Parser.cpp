/*
** EPITECH PROJECT, 2022
** /home/hugo/Epitach/tekspice
** File description:
** RegUtil.cpp
*/

#include "Parser.hpp"

std::ifstream Parser::checkFile(std::string filename)
{
    std::ifstream file;
    if (!RegUtils::isMatch(filename, "^(.*\\/)*[^\\.]+\\.nts$")) {
        throw std::invalid_argument("Invalid file name: " + filename);
    }
    file.open(filename);
    if (!file.is_open()) {
        throw std::invalid_argument("File not found: " + filename);
    }
    return file;
}

bool Parser::isInVector(std::string str, std::vector<std::string> vec)
{
    return std::find(vec.begin(), vec.end(), str) != vec.end();
}

void Parser::parseLink(std::string line, nts::Factory *factory)
{
    std::string linkPattern = "^((\\w+):(\\d+)) ((\\w+):(\\d+))$";
    static std::vector<std::string> linksVec;
    if (RegUtils::isMatch(line, linkPattern)) {
        std::smatch smatch = RegUtils::getMatch(line, linkPattern);
        std::string chipsetLink = smatch[1].str();
        std::string chipset = smatch[2].str();
        int pin = std::stoi(smatch[3].str());
        std::string linkLinkPin = smatch[4].str();
        std::string link = smatch[5].str();
        int linkPin = std::stoi(smatch[6].str());

        if (isInVector(chipsetLink, linksVec))
            throw std::invalid_argument("Duplicate link: " + line);
        linksVec.push_back(chipsetLink);
        auto chipsetInput = factory->GetChipset(chipset);
        auto chipsetOutput = factory->GetChipset(link);
        chipsetInput->setLink(pin, *chipsetOutput, linkPin);
        chipsetOutput->setLink(linkPin, *chipsetInput, pin);
        return;
    }
    throw std::invalid_argument("Invalid link: " + line);
}

void Parser::parseChipset(std::string line, nts::Factory *factory)
{
    static std::vector<std::string> chipsetsVec;
    const std::string wordPattern = " ([\\w]+)$";
    const std::string chipsetsPatterns[] = {
        "^(input)" + wordPattern,
        "^(output)" + wordPattern,
        "^(2716)" + wordPattern,
        "^(4001)" + wordPattern,
        "^(4008)" + wordPattern,
        "^(4011)" + wordPattern,
        "^(4013)" + wordPattern,
        "^(4017)" + wordPattern,
        "^(4030)" + wordPattern,
        "^(4040)" + wordPattern,
        "^(4069)" + wordPattern,
        "^(4071)" + wordPattern,
        "^(4081)" + wordPattern,
        "^(4094)" + wordPattern,
        "^(4512)" + wordPattern,
        "^(4514)" + wordPattern,
        "^(4801)" + wordPattern,
        "^(clock)" + wordPattern,
        "^(false)" + wordPattern,
        "^(logger)" + wordPattern,
        "^(true)" + wordPattern,
    };
    for (std::string pattern : chipsetsPatterns) {
        if (!RegUtils::isMatch(line, pattern))
            continue;
        std::smatch smatch = RegUtils::getMatch(line, pattern);
        std::string type = smatch[1].str();
        std::string name = smatch[2].str();

        if (isInVector(name, chipsetsVec))
            throw std::invalid_argument("Duplicate link name: " + name);
        chipsetsVec.push_back(name);
        factory->AddChipset(name, type);
        return;
    }
    throw std::invalid_argument("Invalid chipset: " + line);
}

void Parser::parse(std::string filename, nts::Factory *factory)
{
    std::ifstream file = checkFile(filename);
    std::string line;
    bool sectionChipsets = false;
    bool sectionLinks = false;

    while (getline(file, line)) {
        if (line.empty() || line[0] == '#')
            continue;
        if (RegUtils::isMatch(line, "^\\.chipsets:$")) {
            if (sectionChipsets)
                throw std::invalid_argument("Two chipset section");
            if (sectionLinks)
                throw std::invalid_argument("Chipsets section after links section");
            sectionChipsets = true;
            continue;
        }
        if (RegUtils::isMatch(line, "^\\.links:$")) {
            if (sectionLinks)
                throw std::invalid_argument("Two link section");
            if (!sectionChipsets)
                throw std::invalid_argument("Link section before chipset section");
            sectionLinks = true;
            sectionChipsets = false;
            continue;
        }
        if (sectionChipsets) {
            parseChipset(line, factory);
            continue;
        } else if (sectionLinks) {
            parseLink(line, factory);
            continue;
        }
        throw std::invalid_argument("Invalid nts: " + line);
    }
}
