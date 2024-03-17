#include <iostream>
#include <string.h>

using namespace std;

void computeLPSArray(char* pat, int M, int* lps);
 
// Prints occurrences of pat[] in txt[]
int KMPSearch(char* pat, char* txt)
{
    int _M = strlen(pat);
    int _N = strlen(txt);

    int count{0};
 
    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int lps[_M];
 
    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, _M, lps);
 
    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    while ((_N - i) >= (_M - j)) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
 
        if (j == _M) {
            // cout << "Found pattern at index " << i - j << "\n";
            count++;
            j = lps[j - 1];
        }
 
        // mismatch after j matches
        else if (i < _N && pat[j] != txt[i]) {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }

    return count;
}
 
// Fills lps[] for given pattern pat[0..M-1]
void computeLPSArray(char* pat, int M, int* lps)
{
    // length of the previous longest prefix suffix
    int len = 0;
 
    lps[0] = 0; // lps[0] is always 0
 
    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0) {
                len = lps[len - 1];
 
                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
 
// Driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int M;

    cin >> N;
    cin >> M;

    char* pat = new char[2 * N  + 2];
    char* txt = new char[M + 1];

    pat[2 * N + 1] = '\0';
    txt[M] = '\0';

    cin >> txt;
    for (int i = 0; i < 2 * N + 1; i++) {
        if (i % 2 == 0)
            pat[i] = 'I';
        else 
            pat[i] = 'O';
    }

    cout << KMPSearch(pat, txt);
    return 0;
}