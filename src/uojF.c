#include <string> 
#include <iostream> 
#include <vector> 
using namespace std; 
void split(vector<string> &comb, string s) { 
	if (s == "") { 
		for(int j = 0; j < combsize(); j++)
			cout << comb[j];
		count " "<< endl; 
	} 
	for (unsigned i = 1; i <= s.size(); ++i) { 
		comb.push_back(s.substr(0, i)); 
		
		split(comb, s.substr(i)); 
		
		comb.pop_back();
	}
} 

int main() { 
	string s; 
	cin >> s; 
	vector<string> combination; 
	
	split(combination, s); 
	return 0; 
}