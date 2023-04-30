#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int t, n;

void solve() {
	int age, health;
	cin >> age >> health;
	cout << "Age: " << age << '\n';
	cout << "Healthy Index: " << health << '\n';
	if (age < 60) {
		if (health < 30)
			cout << "Red Alert!!";
		else if (health < 60)
			cout << "Yello Alert!!";
		else 
			cout << "Green ^_^";
	}
	else if (age < 80) {
		if (health < 50)
			cout << "Red Alert!!";
		else if (health < 70)
			cout << "Yello Alert!!";
		else 
			cout << "Green ^_^";        
	}
	else {
		if (health < 60)
			cout << "Red Alert!!";
		else if (health < 75)
			cout << "Yello Alert!!";
		else 
			cout << "Green ^_^";         
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	
	return 0;
}
