#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	ll N;
	cin >> N;

	vector<string>wrds;
	map<char, ll> letter;

	for(int i = 0; i < N; i++) {
		string s;
		cin >> s;
		wrds.push_back(s);
		letter[s[0]]++;
	}

	ll cnt = 0;
	for(int i = 0; i < N; i++) {
		map<char, ll> letterCopy = letter;
		string s = wrds[i];
		string acronym = "";
		letterCopy[s[0]]--;//para que no busque la que tiene como primera de el
		for(size_t k = 0; k < s.size(); k++) {
			if(letterCopy.find(s[k]) != letterCopy.end() && letterCopy[s[k]] > 0 ) {
				acronym += s[k];
				letterCopy[s[k]]--;
			}
		}
		if(acronym == s) cnt++;
	}

	cout << cnt;

	return 0;
}