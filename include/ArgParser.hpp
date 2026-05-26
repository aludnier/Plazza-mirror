/*
** EPITECH PROJECT, 2026
** plazza-mirror
** File description:
** ArgParser
*/

#ifndef ARGPARSER_HPP_
    #define ARGPARSER_HPP_
    #define ARGS_NUMBER 3
    #include <string>
    #include <vector>
    #include <stdexcept>

class ArgParser
{
    public:
        size_t _cnt;
        std::vector<std::string> _args;
        std::vector<double> _intArgs;

        ArgParser(int cnt, char **args);
        ~ArgParser();

        void checkArgs();

        class ArgParserError : public std::exception
        {
            private:
                std::string _msg;
            public:
                ArgParserError(std::string msg): _msg("[ArgParse Error] : " + msg) {};
                const char *what() const noexcept override
                {
                    return _msg.data();
                };
        };
};

#endif /* !ARGPARSER_HPP_ */
