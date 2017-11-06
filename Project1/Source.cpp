#include <iostream>
#include <vector>
#include <string>


using namespace std;

template <class T>
void myswap(T& a, T &b) {
	T temp;
	temp = a;
	a = b;
	b = temp;
}

vector<string> stringToVec(string s) {
	vector<string> v;
	if (s[s.length() - 1] != ' ') { s = s + " "; }

	int size = s.length();
	int from = 0;
	for (int i = 0; i < size;i++) {
		if (s[i] == ' ') {
			string str = s.substr(from, i - from);
			bool exist = false;
			for (int j = 0; j < v.size();j++) {
				if (v[j] == str) { exist = true; break; }
			}
			if (!exist) { v.push_back(str); }

			from = i + 1;
		}

	}


	return v;
}

bool stringABiggerB(string & a, string &b) {
	int aa = a.size();
	int bb = b.size();
	int s = (aa < bb) ? aa : bb;
	for (int i = 0; i < s; i++) {
		char ca = a[i], cb = b[i];
		if (ca < cb) { return false; }
		else if (ca > cb) { return true; }
	}
	//if (aa > bb) { return false; }
	return true;
}

std::vector<std::vector<int>> spamClusterization(std::vector<std::string> requests, std::vector<int> IDs, double threshold) {

	std::vector<std::vector<int>> result;
	int size = requests.size();
	for (int i = 0; i < size; i++) { // to lowercase
		int j = 0;
		while (requests[i][j]) {
			requests[i][j] = tolower(requests[i][j]);
			char c = requests[i][j];
			if (requests[i][j] != ' ' && ((requests[i][j] < 'a') || (requests[i][j] > 'z'))) { requests[i].erase(j, 1);j--; }
			else if ((requests[i][j] == ' ')&&(j != 0) ) {
				if (requests[i][j-1] == ' '){ requests[i].erase(j, 1);j--; }
			}
			j++;
		}
	}
	std::vector<std::vector<string>> mes;
	for (int i = 0; i < size; i++) {
		//cout<<requests[i] <<endl ;
		mes.push_back(stringToVec(requests[i]));
	}
	
	// calc jac
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size;j++) {
			double counter = 0;
			for (int k = 0; k < mes[i].size();k++) {
				for (int l = 0; l < mes[j].size();l++) {
					if (mes[i][k] == mes[j][l]) { counter++; }
				}
			}
			double r = counter / (mes[i].size() + mes[j].size() - counter);
			if (r >= threshold) {
				bool co = true;
				for (int x = 0; x < result.size(); x++) {
					for (int y = 0;y < result[x].size();y++) {
						int ss = result[x].size();
						if (result[x][y] == IDs[i]) { result[x].push_back(IDs[j]);co = false;break; }
						else if (result[x][y] == IDs[j]) { result[x].push_back(IDs[i]);co = false;break; }
					}
				}
				if (co) { result.push_back({ IDs[i], IDs[j] }); }
			}
		}
	}
	// sorting
	for (int b = 0;b <result.size();b++) {
		for (int x = 0; x < result[b].size(); x++) {
			for (int y = x + 1;y < result[b].size();y++) {
				if (result[b][x] > result[b][y]) {
					myswap(result[b][x], result[b][y]);
				}
			}
		}

	}
	for (int a = 0;a < result.size();a++) {
		for (int b = a + 1;b < result.size();b++) {
			if (result[b][0] < result[a][0])myswap(result[a], result[b]);
		}
	}
	return result;
}

int main1() {
	vector<int> id = {374, 2845, 83, 1848, 1837, 1500 };
	std::vector<std::string> requests = { "I need a new window.",
		"I  really, really want to replace my window!",
		"Replace my window.",
		"I want a new window.",
		" I want a new carpet, I want a new carpet, I want a new carpet.",
		"Replace  my  carpet" };
	std::vector<std::vector<int>> x;
	x = spamClusterization(requests, id, 0.5);
	for (int i = 0; i < x.size(); i++) {
		cout << "[ ";
		for (int j = 0; j < x[i].size();j++) {
			cout << x[i][j] << " ";
		}cout << " ]" << endl;
	}
	system("pause");
	return 0;
}