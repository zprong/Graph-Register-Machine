#include "commands.h"
#include "subcommands.h"

// function prototypes
vector<string> split_words(string phrase);

// main()
 int main()
 {

#if defined DBUG
	graph reg[4];
	string input;
	create cCreate;
    print cPrint;
	arc cArc;
	biarc cBiarc;
	bfs_command cbfs;
	vector <commands*> cmds = { &cCreate, &cPrint, &cArc, &cBiarc, &cbfs };
	std::cout << "Enter a command:\n";
	std::cout << "1 - create <# of nodes> <register>\t";
	std::cout << "2 - print <register>\n";
	std::cout << "3 - arc <node1> <node2> <register>\t";
	std::cout << "4 - biarc <node1> <node2> <register>\n";
	std::cout << "5 - bfs <start node> <target node> <register>\n";
	std::cout << "\"stop\" to quit\n";
	std::cout << "> ";
	std::getline(std::cin, input);
	while (input != "stop")
	{
		bool valid = false;
		vector<string> words = split_words(input);
		for (unsigned int i = 0; i < cmds.size(); i++) {
			if (words[0] == cmds[i]->get_name()) {
				cmds[i]->execute(words, reg);
				valid = true;
			}
		}
		if (!valid)
			std::cout << "No command with that name exists\n";
		std::cout << "> ";
		std::getline(std::cin, input);
	}
	return 0;
}  // end of main
// ========================================================
// Register commands to create the given graph:
// create 10 a
// arc 0 2 a
// arc 1 0 a
// arc 2 1 a
// arc 3 1 a
// arc 3 4 a
// arc 4 5 a 
// arc 4 7 a 
// arc 8 9 a
// arc 9 7 a
// bfs 9 6 a
// ===========================================================
	/*
   vector<string> split_words(string phrase)
   A string is passed in and each word is split and stored as an index
   in a vector of strings.

   -string phrase: Passed in order to split each word up

   Returns: A vector of strings from the passed in phrase.

	*/

vector<string> split_words(string phrase)
{
	string word;
	vector<string> words;
	bool word_read = false;

	for (char c : phrase) {
		if (word_read == true) {
			if (c != ' ')
				word.push_back(c);
			else {
				words.push_back(word);
				word.clear();
				word_read = false;
			}
		}
		else {
			if (c != ' ') {
				word.push_back(c);
				word_read = true;
			}
		}
	}
	if (word_read == true)
		words.push_back(word);
	return words;
}
#endif
