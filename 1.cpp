#include<iostream>
#include<vector>
using namespace std;
//回溯与递推
bool isprime(int k) {
	for (int a = 2; a * a <= k; a++) {
		if (k % a == 0) {
			return false;
		}
	}
	return true;
}
void primering(int n,vector<bool>isused,vector<int>ring) {
	if (ring.size() == n) {
		if (isprime(ring.back() + ring.front())) {
			for (const auto& a : ring) {
				cout << a << " ";
			}
			cout << endl;
		}
		return;
	}
	for (int i = 2; i <=n; i++) {
		if (!isused[i] && isprime(i + ring.back())) {
			isused[i] = true;
			ring.push_back(i);
			primering(n, isused, ring);
			isused[i] = false;
			ring.pop_back();
		}
	}
	
}
int main() {
	int k;
	cin >> k;
	vector<int>ring = { 1 };
	vector<bool>isused(k+1, false);
	isused[1] = true;
	primering(k,isused,ring);
	
	return 0;
}
