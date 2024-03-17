#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    unordered_map<string, int> pokemonHash;
    pokemonHash.reserve(100001);

    int N, M;

    cin >> N >> M;

    string* pokemons = new string[N + 1]; // 1-indexing

    for (int i = 1; i <= N; i++) {
        cin >> pokemons[i];
        pokemonHash.insert(make_pair(pokemons[i], i));
    }

    int question2;
    for (int i = 1; i <= M; i++) {
        string question1;

        cin >> question1;
        if ((int)question1[0] < 58) {
            question2 = 0;
            // sscanf(question1, "%d", &question2);
            question2 = stoi(question1);
            cout << pokemons[question2] << "\n";
            continue;
        }
        cout << pokemonHash[question1] << "\n";
    }
}