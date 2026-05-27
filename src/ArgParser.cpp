/*
** EPITECH PROJECT, 2026
** plazza-mirror
** File description:
** ArgParser
*/

#include "ArgParser.hpp"

ArgParser::ArgParser(int cnt, char **args)
{
    if (cnt != ARGS_NUMBER + 1)
        throw ArgParserError("incorrect number of arguments.");
    _args.reserve(ARGS_NUMBER);
    _intArgs.reserve(ARGS_NUMBER);
    for (size_t i = 0; i < ARGS_NUMBER; ++i)
        _args.push_back(args[i + 1]);
    _cnt = cnt;
    checkArgs();
}

void ArgParser::checkArgs()
{
    double tmp;

    for (const auto &arg : _args) {
        try {
            tmp = std::stod(arg);
        } catch (const std::invalid_argument &e) {
            throw ArgParserError("incorrect argument.");
        }
        if (tmp < 0)
            throw ArgParserError("incorrect argument.");
        _intArgs.push_back(tmp);
    }
}

ArgParser::~ArgParser()
{
}
