#include <iostream>
#include <string>
#include <vector>

std::string smartAssigning(std::vector<std::string> names, std::vector<bool> statuses, std::vector<int> projects, std::vector<int> tasks) {

	int num = names.size();
	std::vector<int> av;
	for (int i = 0; i < num; i++) {
		if (statuses[i] == false) { av.push_back(i); }
	}
	if (av.size() == 1) { return names[av[0]]; }
	std::vector<int> av2;
	int tmpv, tmpp;
	for (int i = 0; i < av.size(); i++) {
		tmpv = tasks[i];tmpp = av[i];
		for (int j = i + 1; j < av.size(); j++) {
			if (tmpv > tasks[av[j]]) { tmpv= }
			
		}
	}

	std::vector<int> av2;
	for (int i = 0; i < av3.size(); i++) {
		for (int j = i + 1; j < av3.size(); j++) {
			if (tasks[av3[i]] > tasks[av3[j]]) { av2.push_back(av3[j]); }
			else if (tasks[av3[i]] < tasks[av3[j]]) { av2.push_back(av3[i]); }
			else if (tasks[av3[i]] == tasks[av3[j]]) { av2.push_back(av3[i]);av2.push_back(av3[j]); }
		}
	}


	if (av2.size() == 1) { return names[av2[0]]; }
	av.clear();
	std::vector<int> avv;
	for (int i = 0; i < av2.size(); i++) {
		for (int j = i + 1; j < av2.size(); j++) {
			if (projects[av2[i]] > projects[av2[j]]) { avv.push_back(av[j]); }
			else { avv.push_back(av[i]); }
		}
	}
	if (av.size() == 1)return names[av[0]];
	else { return names[1]; }
}


int main() {

	std::vector<std::string> names = { "John", "Martin" };
	std::vector<bool>statuses = { false, false };
	std::vector<int>tasks = { 16, 5 };
	std::vector<int>projects ={ 2, 1 };

	std::string x = smartAssigning(names, statuses, projects, tasks);
	std::cout << x;
	system("pause");
	return 0;
}