
#ifndef SUBCOMMANDS_H
#define SUBCOMMANDS_H
#include "commands.h"
#if defined DBUG
class create : public commands {
  public:
	void execute(std::vector<std::string>& words, graph reg[]);
	create();
};

class print : public commands {
  public:
	void execute(std::vector<std::string>& words, graph reg[]);
	void trav_list(it start, it finish);
	print();
};

class arc : public commands{
  public:
	void execute(std::vector<std::string>& words, graph reg[]);
	arc();
};

class biarc : public commands {
  public:
	void execute(std::vector<std::string>& words, graph reg[]);
	biarc();
};

class bfs_command : public commands{
  public:
	void execute(std::vector<std::string>& words, graph reg[]);
	void bfs(graph& g, int start, int target);
	bfs_command();
};

#endif
#endif