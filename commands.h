#ifndef COMMANDS_H
#define COMMANDS_H
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#define DBUG

using graph = std::vector<std::list<int>>; // adjacency list
using it = std::list<int>::iterator;

using std::string;
using std::vector;
//the parent class that holds the virtual executable function
//to allow other command subclasses to inherit the execute()
//function
class commands {
public:
	virtual void execute(std::vector<std::string>& words, graph reg[]) = 0;
	string get_name();
protected:
	string name;
};

#endif