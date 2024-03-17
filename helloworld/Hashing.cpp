#include <bits/stdc++.h>

using namespace std;

#define Mod 1234567891

int n;
string str;


int Hashing()
{
	long long ans=0;
	long long r=1;
	
	for(int i=0;i<n;i++){
		int a = str[i]-'a'+1;
		ans = (ans+(a*r))%Mod;
		r = (r*31)%Mod;
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n;
	cin >> str;
	
	cout<<Hashing();
	
	
	return 0;
}