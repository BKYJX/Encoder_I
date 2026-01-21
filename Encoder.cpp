#include<cstdio>
#include<string>
#include<iostream>
#include<vector>
using namespace std;

#define ull unsigned long long

vector<char> m;
ull kk;

ull hsh(string k, ull t){
	ull ans = 0;
	for(ull i = 0; i < k.size(); i++){
		ull tmp = (int(k[i]) * t + 13131) * 131 / t * 131;
		ans += tmp * (i + 131) * 131;
		ans *= 13131;
	}
	return ans;
}

void decodeByGenerate(unsigned long long target_hash, ull n, string current, string& result) {
    if (result != "") {
        return;
    }
    if (current.length() == n) {
        if (hsh(current, kk) == target_hash) {
            result = current;
        }
        return;
    }
    for (char c = 'a'; c <= 'z'; c++) {
        decodeByGenerate(target_hash, n, current + c, result);
    }
}

string decodeOpt(unsigned long long target_hash, ull n) {
    string result = "";
    if (n < 1) {
        return result;
    }
    decodeByGenerate(target_hash, n, "", result);
    return result;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	bool modemodemode;
	ull op;
	string a;
	cin >> modemodemode >> op >> kk;
	if(modemodemode == 0){
		for(ull i = 1; i <= op; i++){
			cin >> a;
			cout << hsh(a, kk) << ' ' << a.size() << endl;
		}
	}else{
		for(ull i = 1; i <= op; i++){
			ull m = 0, l = 0;
			cin >> m >> l;
			cout << decodeOpt(m, l) << endl;
		}
	}
	return 0;
}
