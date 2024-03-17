#include <iostream>
#include <queue>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
	int testCase;
	int n, m;
	int priority;
	int count;

	cin >> testCase;

	for (int i = 0; i < testCase; ++i) {
		count = 0;
		
        cin >> n >> m;
		
        // priority queue for sorting importance
		priority_queue<int> pq; 
		queue<pair<int, int>> q;

		for (int j = 0; j < n; ++j) {
			cin >> priority;
			q.push({ j, priority });
			pq.push(priority);
		}

		while (!q.empty()) {
			// priority and order value comparison
			int location = q.front().first;
			int value = q.front().second;
			q.pop();
            
			if (pq.top() == value) {
				pq.pop();
				++count;
				if (m == location) {
					cout << count << "\n";
					break;
				}
			}

			else q.push({ location, value });
		}
	}
}