#include <exception>
#include <string>
class RepositoryException : public std::exception{
	std::string message;
public: 
	RepositoryException(std::string message) :message(message) {};
	std::string getMessage() { return this->message; };
};

class ValidatorException : public std::exception {
	std::string message;
public:
	ValidatorException(std::string message) :message(message) {};
	std::string getMessage() { return this->message; };
};

class UserInputException : public std::exception {
	std::string message;
public:
	UserInputException(std::string message) :message(message) {};
	std::string getMessage() { return this->message; };
};