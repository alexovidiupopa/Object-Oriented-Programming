#pragma once
#include "Utils.h"

class Task
{
private: 
	std::string description, status;
	int id;
public:
	Task();
	Task(std::string description, std::string status, int id):description(description),status(status),id(id){}
	int getProgId() { return id; }
	std::string getStatus() { return status; }
	std::string getDescription() { return description; }
	void setId(int newId) { id = newId; }
	void setStatus(std::string newStatus) { status = newStatus; }
	void setDescription(std::string newD) { description = newD; }
	std::string toString() {
		std::string str = description;
		str += ";" + status + ";" + std::to_string(id) + "\n";
		return str;
	}
	friend std::istream& operator>>(std::istream& stream, Task &task);
	~Task();
};

