/*
File: commands.cc
This file simply returns the name of a specific command

Name: Zach Prong
Date of last revision: 05/26/2017
*/
#include <iostream>
#include <string>
#include <vector>
#include "commands.h"

string commands::get_name() {
	return name;
}