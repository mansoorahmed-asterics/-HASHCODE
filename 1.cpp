#include <fstream>
#include <utility>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<int, string> i, pair<int, string> j) {
	return i.first < j.first;
}

int main() {
	ifstream fin("d.txt");

	vector<string> streets;
	vector<int> cars;
	vector<pair<int, string>> intersections;
	int D, I, S, V, F;
	fin >> D >> I >> S >> V >> F;
	vector<int> inter;
	inter.resize(I);
	for (int i = 0; i < I; i++) {
		inter[i] = 0;
	}

	for (int i = 0; i < S; i++) {
		int B, E;
		fin >> B >> E;
		string name;
		fin >> name;
		int L;
		fin >> L;
		inter[E]++;
		intersections.push_back({ E, name });
	}
	string s1;
	for (int i = 0; i < V; i++) {
		int P;
		fin >> P;
		vector<string> path;
		for (int j = 0; j < P; j++) {
			fin >> s1;
			path.push_back(s1);
		}
	}
	fin.close();

	sort(intersections.begin(), intersections.end(), comp);

	ofstream fout("dout.txt");
	fout << I << "\n";
	int prev = -1;
	for (auto intersection : intersections) {
		if (prev != intersection.first) {
			prev = intersection.first;
			fout << prev << "\n";
			fout << inter[prev] << "\n";
		}
		fout << intersection.second << " " << 1 << "\n";
	}
	fout.close();
	return 0;
}