// vertex - edge = worm numbers

#include <iostream>
#include <deque>

using namespace std;

struct point {
    int x;
    int y;
};

int width, height, cabaggeNumber;

bool** cabbageMatrix = new bool*[50];

void breadthSearch(int startRow, int startCol) {   
    deque<point> coordinates;

    point temp;
    temp.x = startRow; temp.y = startCol;
    coordinates.push_back(temp);

    point popped;
    point pushed;

    while (!coordinates.empty()) {
        popped = coordinates.front();
        coordinates.pop_front();

        if (popped.x + 1 < width && cabbageMatrix[popped.x+1][popped.y] == true) {
            cabbageMatrix[popped.x+1][popped.y] = false;
            pushed.x = popped.x + 1;
            pushed.y = popped.y;
            coordinates.push_back(pushed);
        }
        if (popped.y + 1 < height && cabbageMatrix[popped.x][popped.y+1] == true) {
            cabbageMatrix[popped.x][popped.y+1] = false;
            pushed.x = popped.x;
            pushed.y = popped.y + 1;
            coordinates.push_back(pushed);
        }
        if (popped.x - 1 >= 0 && cabbageMatrix[popped.x-1][popped.y] == true) {
            cabbageMatrix[popped.x-1][popped.y] = false;
            pushed.x = popped.x - 1;
            pushed.y = popped.y;
            coordinates.push_back(pushed);
        }
        if (popped.y - 1 >= 0 && cabbageMatrix[popped.x][popped.y-1] == true) {
            cabbageMatrix[popped.x][popped.y-1] = false;
            pushed.x = popped.x;
            pushed.y = popped.y - 1;
            coordinates.push_back(pushed);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    point coordinates[2500];

    int testNumber;

    // Initialize CabbageMatrix
    for (int row = 0; row < 50; row++){
            cabbageMatrix[row] = new bool[50];
            for (int col = 0; col < 50; col++) {
                cabbageMatrix[row][col] = false;
            }
    }

    cin >> testNumber;

    while (testNumber > 0) {

        cin >> width >> height >> cabaggeNumber;

        int minRow{0xfffffff}, minCol{0xfffffff};

        int tempRow, tempCol;

        int result {0};

        for (int turn = 0; turn < cabaggeNumber; turn++){
            cin >> tempRow >> tempCol;

            if (tempRow < minRow && tempCol < minCol) {
                minRow = tempRow;
                minCol = tempCol;
            }

            cabbageMatrix[tempRow][tempCol] = true;

            coordinates[turn].x = tempRow;
            coordinates[turn].y = tempCol;
        }

        for (int turn = 0; turn < cabaggeNumber; turn++) {
            if (cabbageMatrix[coordinates[turn].x][coordinates[turn].y] == true) {
                result++;
                // breadth search
                breadthSearch(coordinates[turn].x, coordinates[turn].y);
                cabbageMatrix[coordinates[turn].x][coordinates[turn].y] = false;
            }
        }

        testNumber--;
        cout << result << "\n";
    }

    for (int i = 0; i < height; ++i) {
        delete[] cabbageMatrix[i];
    }

    delete[] cabbageMatrix;
}