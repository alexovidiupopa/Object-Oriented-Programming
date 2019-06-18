#pragma once
#include "Utils.h"
class Issuee
{
private:
	string description, status, reporter, solver;
public:
	Issuee();
	Issuee(string desc, string status, string reporter, string solver) : description(desc), status(status), reporter(reporter),solver(solver){}
	~Issuee();
public:
    string getDescription() const;
    void setDescription(string description);

    string getStatus() const;
    void setStatus(string status);

    string getReporter() const;
    void setReporter(string reporter);

    string getSolver() const;
    void setSolver(string solver);

	string toString() { return description + ";" + status + ";" + reporter + ";" + solver + "\n"; }
	friend istream& operator>>(istream& stream, Issuee& issue);
};

