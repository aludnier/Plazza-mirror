/*
** EPITECH PROJECT, 2026
** lineParser
** File description:
** 
*/


#ifndef LINEPARSER
    #define LINEPARSER
    #include <string>
    #include <sstream>
    #include <vector>




class LineParser
{
private:
    std::string _line;
    std::vector<std::string> _words;
    char _delim;

    void Update_words(char delim);
public:
    LineParser();
    ~LineParser();

    class ParserError : public std::exception {
        private:
            std::string _msg;
        public:
            ParserError(std::string msg): _msg("[LineParse Error] : " + msg) {};
            const char *what() const noexcept override {
                return _msg.data();
            };
    };

    void readLineFrom(std::istream &stream, char delim = ' ');
    void ParseLine(std::string newline, char delim = ' ');
    std::size_t getNbWord();
    std::vector<std::string>& getWords();
    std::string getLine();
    void cleanChars(std::string charToRemove);
    void replaceWord(std::size_t index, std::string newWord);
    std::string concatWords(std::string delim = " ");
    void removeWord(std::size_t index);
};


#endif