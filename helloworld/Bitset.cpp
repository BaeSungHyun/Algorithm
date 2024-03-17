#include <iostream>
#include <bitset>

#define R 1000000
#define D 2000001

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
    int N; cin >> N;
	
    bitset<D> exist;
	
    int tmp;
    for (int i = 0; i < N; i++)
    {
		cin >> tmp;
		exist[tmp + R] = 1;
	}
	
	for (int i = exist._Find_first();
         i < exist.size();
         i = exist._Find_next(i)) 
    {
		cout << i - R << '\n';
	}
	return 0;
}