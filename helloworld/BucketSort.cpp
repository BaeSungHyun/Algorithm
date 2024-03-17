#include <iostream>

using namespace std;

struct Person;

struct Person {
    Person* endNode {nullptr};
    int age;
    char name[101];
    Person* nextNode {nullptr};
}; 

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    
    Person ageGroup[201]; // all initialized to null by default

    while (N > 0) {
        Person* temp = new Person;
        cin >> (*temp).age;
        cin >> (*temp).name;
        
        if (ageGroup[(*temp).age].endNode != nullptr){
            // Age already exists in the array
            ageGroup[(*temp).age].endNode->nextNode = temp;
            ageGroup[temp->age].endNode = temp;
        } else {
            ageGroup[(*temp).age] = *temp; // Pass by value
            ageGroup[(*temp).age].endNode = &(ageGroup[(*temp).age]);
        }
        N--;
    }

    int discreteAge {1};
    while (discreteAge <= 200) {
        if (ageGroup[discreteAge].endNode != nullptr) {
            cout << ageGroup[discreteAge].age << " " << ageGroup[discreteAge].name << "\n";

            Person* temp = ageGroup[discreteAge].nextNode;
            while (temp != nullptr) {
                cout << (*temp).age << " " << (*temp).name << "\n";
                temp = temp->nextNode;
            }
        }
        discreteAge++;
    }
}