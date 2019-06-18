#include "Issuee.h"



Issuee::Issuee()
{
}


Issuee::~Issuee()
{
}

string Issuee::getDescription() const
{
    return description;
}

void Issuee::setDescription(string description)
{
    this->description = description;
}

string Issuee::getStatus() const
{
    return status;
}

void Issuee::setStatus(string status)
{
    this->status = status;
}

string Issuee::getReporter() const
{
    return reporter;
}

void Issuee::setReporter(string reporter)
{
    this->reporter = reporter;
}

string Issuee::getSolver() const
{
    return solver;
}

void Issuee::setSolver(string solver)
{
    this->solver = solver;
}

istream & operator>>(istream & stream, Issuee & issue)
{
	string input;
	getline(stream, input);
	Utils utils{};
	vector<string> tokens = utils.tokenize(input);
	if (tokens.size() != 4)
		return stream;
	issue.setDescription(tokens[0]);
	issue.setStatus(tokens[1]);
	issue.setReporter(tokens[2]);
	issue.setSolver(tokens[3]);
	return stream;
}
