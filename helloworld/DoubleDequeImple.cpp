#include <iostream>

using namespace std;

struct node {
    int data;
    node* next;
    node* previous;
    node (int d) 
    {   
        previous = NULL;
        data = d;
        next = NULL;
    }
};

struct Queue {
    node* front, *rear;
    Queue() {front = rear = NULL;}

    void enQueue(int x) {
        // Create a new LL node
        node* temp = new node(x);

        // If queue is empty, then new node is front and rear both
        if (rear == NULL) {
            front = rear = temp;
            return;
        }

        // Add the new node at the end of queue and change rear
        temp->previous = rear;
        rear->next = temp;
        rear = temp;
    }

    // Function to remove a key from given queue q
    void deQueue() {
        // If queue is empty, return NULL
        if (front == NULL) 
            return;
        
        // Store previous front and move front one node ahead
        node* temp = front; 
        front = front->next; 
        if (front != NULL) {
            front->previous = NULL; 
        }

        // If front becomes NULL, then change rear also as NULL
        if (front == NULL)
            rear = NULL;
        
        delete temp; // possible because it's address
    }

    void moveLeftOne() {
        // since it doesn't disappear after going to rear, let's do rear first
        rear->next = front; // assign original rear->next to front node
        front->previous = rear;
        rear = front; // change rear to front node
        front = rear->next; // change front to changed rear's next
        rear->next = NULL; // change changed rear's next to NULL
    }

    void moveRightOne() {
        front->previous = rear; // original
        rear->next = front; // original

        front = rear; // change front to rear node
        rear = rear->previous; // change rear node to one in front of rear node

        front->previous = NULL;
        rear->next = NULL;
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;

    cin >> N >> M;

    struct Queue queNum;

    int num;
    int count{0};

    for (int i = 0; i < N; ++i) {
        queNum.enQueue(i +1);
    }

    while (M > 0) {
        cin >> num;

        int tempCount{0};

        if (num == queNum.front->data) {
            queNum.deQueue();
            // cout << "1 " << queNum.front->data << "\n";
            --N;
            --M;
        } else {
            while (num != queNum.front->data) {
                queNum.moveLeftOne();
                ++tempCount;
            }
            if (tempCount > N / 2) {
                for (int j = 0; j < tempCount; ++j) {
                    queNum.moveRightOne();
                }
                tempCount = 0;     
                while (num != queNum.front->data) {
                    queNum.moveRightOne();
                    ++tempCount;
                }           
            }
            // cout << tempCount << "\n";
            count += tempCount;
            queNum.deQueue();
            --N; --M;
        }
    }

    cout << count;
}