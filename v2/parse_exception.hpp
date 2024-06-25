#ifndef PARSE_EXCEPTION_HPP
#define PARSE_EXCEPTION_HPP

#include <string>
#include <exception>

class ParseException : public std::exception {
public:
    ParseException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override { return message.c_str(); }
private:
    std::string message;
};

#endif // PARSE_EXCEPTION_HPP