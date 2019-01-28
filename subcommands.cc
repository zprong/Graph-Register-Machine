#include "subcommands.h"
#if defined DBUG

/*  execute(vector<string> &words, int reg[])
compares 2 integer/register values and stores into a register a 1, 0, -1 if the first element is greater, equal, or less, respectively.

-vector<string> &words: allows the function to read each word inputted by user
-int reg[]: passes in the register array to store inputted values there

Assumes: the number of words typed at the command line is 4

Ensures: a 1, 0, or -1 is stored in the register

*/
void create::execute(std::vector<std::string>& words, graph reg[]) {
	std::string reg_letter[] = { "a","b","c","d" };
	int index = 0;
	int num_nodes;
	bool found = false;
	if (words.size() != 3) {
		std::cout << "Wrong format: create <# of nodes> <register>\n";
		return;
	}
	for (; index < 4; index++)
		if (reg_letter[index] == words.at(2)) {
			found = true;
			break;				// index = which index of graph array to refer to.
		}
	if (!found) {
		std::cout << "The specified register does not exist.\n";
	}
	num_nodes = stoi(words.at(1));
	reg[index].clear();
	reg[index].resize(num_nodes);
}

create::create() {
	name = "create";

}
// ===================================================================

void print::execute(std::vector<std::string>& words, graph reg[]) {
	std::string reg_letter[] = { "a","b", "c", "d" };
	int index = 0;
	bool found = false;
	if (words.size() != 2) {
		std::cout << "Wrong format: print <register>\n";
		return;
	}
	for (; index < 4; index++)
		if (reg_letter[index] == words.at(1)) {
			found = true;
			break;				// index = which index of graph array to refer to.
		}
	if (!found) {
		std::cout << "The specified register does not exist.\n";
		return;
	}
	std::cout << "Printout of each node's neighbor:\n";
	for (unsigned int i = 0; i < reg[index].capacity(); i++) {
		std::cout << i << ": ";
		if (!reg[index].empty())
			trav_list(reg[index].at(i).begin(), reg[index].at(i).end());
		else
			std::cout << "Empty";
		std::cout << std::endl;
	}
}
void print::trav_list(it start, it finish) {
	for (it p = start; p != finish; p++) {
		std::cout << *p << " ";
	}
}


print::print() {
	name = "print";
}

// ==========================================================

void arc::execute(std::vector<std::string>& words, graph reg[]) {
	std::string reg_letter[] = { "a","b","c","d" };
	int index = 0;
	int from;
	int to;
	bool found = false;
	if (words.size() != 4) {
		std::cout << "Wrong format: arc <node1> <node2> <register>\n";
		return;
	}
	for (; index < 4; index++)
		if (reg_letter[index] == words.at(3)) {
			found = true;
			break;				// index = which index of graph array to refer to.
		}
	if (!found) {
		std::cout << "The specified register does not exist.\n";
		return;
	}
	from = stoi(words.at(1));
	to = stoi(words.at(2));
	reg[index].at(from).push_back(to);
}

arc::arc() {
	name = "arc";
}
// ===========================================================

void biarc::execute(std::vector<std::string>& words, graph reg[]) {
	std::string reg_letter[] = { "a","b", "c", "d" };
	int index = 0;
	int node1;
	int node2;
	bool found = false;
	if (words.size() != 4) {
		std::cout << "Wrong format: biarc <node1> <node2> <register>\n";
		return;
	}
	for (; index < 4; index++)
		if (reg_letter[index] == words.at(3)) {
			found = true;
			break;	// index = which index of graph array to refer to.
		}
	if (!found) {
		std::cout << "The specified register does not exist.\n";
		return;
	}
	node1 = stoi(words.at(1));
	node2 = stoi(words.at(2));
	reg[index].at(node1).push_back(node2);
	reg[index].at(node2).push_back(node1);
}

biarc::biarc() {
	name = "biarc";
}

// ================================================================

void bfs_command::execute(std::vector<std::string>& words, graph reg[]) {
	std::string reg_letter[] = { "a","b", "c", "d" };
	int index = 0;
	int start;
	int end;
	bool found = false;
	if (words.size() != 4) {
		std::cout << "Wrong format: bfs <start node> <target node> <register>\n";
		return;
	}
	for (; index < 4; index++)
		if (reg_letter[index] == words.at(3)) {
			found = true;
			break;	// index = which index of graph array to refer to.
		}
	if (!found) {
		std::cout << "The specified register does not exist.\n";
		return;
	}
	start = stoi(words.at(1));
	end = stoi(words.at(2));
	bfs(reg[index], start, end);
}

void bfs_command::bfs(graph& g, int start, int target) {
	vector<int> colors(g.size(), 0);
	std::queue<int> q;
	const int WHITE = 0;
	const int GREY = 1;
	const int BLACK = 2;
	bool found = false;
	vector<int> dists(g.size(), 0);
	int val;
	colors.at(start) = GREY;
	q.push(start);
	dists.at(start) = 0;
	while (!q.empty()) {
		val = q.front();
		q.pop();
		colors.at(val) = BLACK;		// node is done being explored
		if (val == target) {
			std::cout << "We have found your value!\n";
			if (dists.at(target) != 1)
				std::cout << target << " is " << dists.at(target) << " nodes away from " << start << std::endl;
			else
				std::cout << target << " is " << dists.at(target) << " node away from " << start << std::endl;
			found = true;
			break;
		}
		for (int neighbor : g.at(val)) {
			if (colors.at(neighbor) == WHITE) {
				q.push(neighbor);	// enqueue if node is unexplored		
				colors.at(neighbor) = GREY;
				dists.at(neighbor) = dists.at(val) + 1;	// updating distances
			}
		}
	}
	if (!found)
		std::cout << "Your desired vertex is not in the graph, ya dimwit!\n";
	else
		std::cout << "Congratulations! Hope you live happily ever after with your newfound vertex.\n";
}

bfs_command::bfs_command() {
	name = "bfs";
}
#endif