/*
** EPITECH PROJECT, 2026
** lineparser
** File description:
** 
*/

#include "LineParser.hpp"
#include <string>
#include <iostream>
#include <algorithm>

void LineParser::Update_words(char delim)
{
    std::stringstream stream(_line);
    std::string word;

    _words.clear();
    while (std::getline(stream, word, delim)) {
        if (word.empty())
            continue;
        _words.push_back(word);
    }
}

void LineParser::readLineFrom(std::istream &stream, char delim)
{
    _delim = delim;

    std::getline(stream, _line);
    Update_words(_delim);
}


std::string LineParser::getLine() 
{
    return _line;
}

void LineParser::ParseLine(std::string newline, char delim)
{
    _line = newline;
    Update_words(delim);
    _delim = delim;
}

std::vector<std::string>& LineParser::getWords()
{
    return _words;
}

std::size_t LineParser::getNbWord()
{
    return _words.size();
}

void LineParser::cleanChars(std::string CharsToRemove)
{
    for (char c : CharsToRemove){
        _line.erase(std::remove(_line.begin(), _line.end(), c), _line.end());
    }
    Update_words(_delim);
}

void LineParser::replaceWord(std::size_t index, std::string newWord)
{
    if (index >= _words.size()){
        throw LineParser::ParserError("Invalid index on call replaceWord()");
    }
    _words[index] = newWord;
}

std::string LineParser::concatWords(std::string delim)
{
    std::string newLine;
    std::size_t index = 0;
    std::size_t maxWordIndex = _words.size() - 1;

    while (index <= maxWordIndex){
        newLine += _words[index] + ((index == maxWordIndex) ? "" : delim);
        index++;
    }
    return newLine;
}

void LineParser::removeWord(std::size_t index)
{
    if (index >= _words.size()){
        throw LineParser::ParserError("Invalid index on call removeWord()");
    }
    _words.erase(_words.begin() + index);
}

std::string &LineParser::operator[](std::size_t index)
{
    if (index >= getNbWord()){
        throw LineParser::ParserError("index out of range");
    }
    return _words[index];
}

LineParser::LineParser()
{
}

LineParser::~LineParser()
{
}
