#include <bits/stdc++.h>
using namespace std;

struct Role {
	string name;
	vector<string> op;
	vector<string> restype;
	vector<string> resname;
};

struct User {
	string name;
	vector<string> g;
	vector<string> r;
};

struct G {
	string name;
	vector<string> r;
};

int n, m, q;
vector<Role> role;
vector<User> u;
vector<G> g;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m >> q;
	for (int i = 1; i <= n; ++i) {
		Role r;
		int nv, no, nn;
		string s;
		cin >> s;
		r.name = s;
		cin >> nv;
		while (nv--) {
			cin >> s;
			r.op.push_back(s);
		}
		cin >> no;
		while (no--) {
			cin >> s;
			r.restype.push_back(s);
		}
		cin >> nn;
		while (nn--) {
			cin >> s;
			r.resname.push_back(s);
		}
		role.push_back(r);
	}
	for (int i = 1; i <= m; ++i) {
		int ns;
		string r;
		cin >> r >> ns;
		while (ns--) {
			char t;
			string s;
			cin >> t >> s;			
			if (t == 'u') {	
				User user;
				user.name = s;
				user.r.push_back(r);
				u.push_back(user);
			} else {
				G gg;
				gg.name = s;
				gg.r.push_back(r);
				g.push_back(gg);
			}
		}
	}
	
	while (q--) {
		int ng;
		string name, op, restype, resname;
		set<string> ss;		
		cin >> name;

		for (auto t : u) {
			if (t.name == name) {
				for (auto uu : (t.r)) {
					ss.insert(uu);
				}
				break;
			}
		}
		cin >> ng;
		while (ng--) {
			string s;
			cin >> s;
			for (auto p : g) {
				if (p.name == s) {
					for (auto rr : (p.r)) {
						ss.insert(rr);
					}
				}
			}
		}

		cin >> op >> restype >> resname;
			bool ok = 0;
			for (auto name : ss) {
				for (auto rr : role) {
					if (rr.name == name) {
						if (rr.op.size() == 0 || rr.restype.size() == 0)
							continue;
						if (rr.op[0] != "*") {
							for (auto oo : rr.op) {
								if (oo == op) {
									if (rr.restype[0] != "*")
										for (auto tt : rr.restype) {
											if (tt == restype) {
												if (rr.resname.size() == 0) {
													ok = 1;
													goto A;
												} else {
													for (auto nn : rr.resname) {
														if (nn == resname) {
															ok = 1;
															goto A;
														}
													}
												}
											}	
										}
								}
							}
						}
					}
				}
			}
			A:
			if (ok) {
				cout << "1\n";
			} else {
				cout << "0\n";
			}
	}
	
	return 0;
}
