#include <iostream>
#include <vector>

using namespace std;

// smmh = Symmetric Min-Max Heap
// smmh - 루트를 제외한 노드들이 하나의 원소를 갖는 완전 이진 트리.
// 1. 임의의 노드 N의 왼쪽 자식은 N의 subtree의 원소 중 최소 원소를 갖는다 (if exists)
// 2. 노드 N의 오른쪽 자식은 N의 subree의 원소 중 최대 원소를 갖는다 (if exists)
// https://constructionsite.tistory.com/48
vector <int> smmh;

// 아래 조건이 참이면서 root 가 공백인 완전 이진 트리는 SMMH이다
// P1. 각 노드의 원소는 오른쪽 형제 원소보다 작거나 같다
// P2. 조부모를 가진 노드에 대해, 조부모의 왼쪽 자식에 있는 원소는 작거나 같다
// P3. 조부모를 가진 노드에 대해, 조부모의 오른쪽 자식에 있는 원소는 크거나 같다

// SMMH 표현
// SMMH 는 완전 이진 트리이므로, 배열을 사용하여 효율적으로 표현 가능하다. 배열의 인덱스 0은 사용하지 
// 않고, index 1은 root node로 공백으로 비워둔다. 그리고 각 노드의 (index*2)에는 왼쪽 자식 노드,
// (index*2 + 1)에는 오른쪽 자식 노드를 저장한다. 

void push(int value)
{
    smmh.push_back(value);
    
    int node_location = smmh.size()-1;
    // 조건 P1 위배 확인
    if(node_location % 2)
    {
        if(smmh[node_location-1] > smmh[node_location])
        {
            int temp = smmh[node_location-1];
            smmh[node_location-1] = smmh[node_location];
            smmh[node_location] = temp;
            --node_location;
        }
    }

    bool done = false;
    while(!done && 4 <= node_location)
    {
        int grandparent = node_location / 4;
        int leftOfGrand = grandparent * 2;
        int rightOfGrand = leftOfGrand + 1;

        // 조건 P2 위배 확인
        if(smmh[leftOfGrand] > smmh[node_location])
        {
            int temp = smmh[node_location];
            smmh[node_location] = smmh[leftOfGrand];
            smmh[leftOfGrand] = temp;
            node_location = leftOfGrand;
        }
        // 조건 P3 위배 확인
        else if(smmh[node_location] > smmh[rightOfGrand])
        {
            int temp = smmh[node_location];
            smmh[node_location] = smmh[rightOfGrand];
            smmh[rightOfGrand] = temp;
            node_location = rightOfGrand;
        }
        else
        {
            done = true;
        }
    }
}

void pop(int direction)
{
    int node_location = smmh.size() - 1;
    int value = smmh[node_location];
    smmh.resize(smmh.size()-1);

    
    if(direction > 0) // 최댓값 삭제
    {
        if(smmh.size() <= 3)
        {
            return;
        }

        bool done = false;
        node_location = 3;
        while(!done && (node_location*2) <= smmh.size())
        {
            int rightChild = (node_location*2) + 1;
            int siblingRightChild = (node_location-1)*2 + 1;
            int maxChild = siblingRightChild;
            if(rightChild < smmh.size() && smmh[siblingRightChild] < smmh[rightChild])
            {
                maxChild = rightChild;
            }

            if(smmh[maxChild] > value)
            {
                smmh[node_location] = smmh[maxChild];
                node_location = maxChild;

                if(value < smmh[node_location-1])
                {
                    smmh[node_location] = smmh[node_location-1];
                    smmh[node_location-1] = value;
                    value = smmh[node_location];
                }
            }
            else
            {
                done = true;
            }
        }
        smmh[node_location] = value;
    }
    else // 최솟값 삭제
    {
        if(smmh.size() <= 2)
        {
            return;
        }
        
        bool done = false;
        node_location = 2;
        while(!done && node_location * 2 <= smmh.size())
        {
            int leftChild = node_location * 2;
            int siblingLeftChild = (node_location+1)*2;
            int minChild = leftChild;
            if(siblingLeftChild < smmh.size() && smmh[siblingLeftChild] < smmh[leftChild])
            {
                minChild = siblingLeftChild;
            }

            if(smmh[minChild] < value)
            {
                smmh[node_location] = smmh[minChild];
                node_location = minChild;

                if(node_location + 1 < smmh.size() && smmh[node_location + 1] < value)
                {
                    smmh[node_location] = smmh[node_location+1];
                    smmh[node_location+1] = value;
                    value = smmh[node_location];
                }
            }
            else
            {
                done = true;
            }
        }
        smmh[node_location] = value;
    }
}

void solve()
{
    smmh.clear();
    smmh.push_back(0);
    smmh.push_back(0);
    int t;
    cin >> t;

    for(int i = 0; i < t; i++)
    {
        char ch;
        int value;
        cin >> ch >> value;

        if(ch == 'I')
        {
            push(value);
        }
        else
        {
            if(smmh.size() <= 2)
            {
                continue;
            }

            if(value > 0)
            {
                pop(1);
            }
            else
            {
                pop(-1);
            }
        }
    }

    if(smmh.size() <= 2)
    {
        cout << "EMPTY";
    }
    else if(smmh.size() == 3)
    {
        cout << smmh[2] << " " << smmh[2];
    }
    else
    {
        cout << smmh[3] << " " << smmh[2];
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;

    while(tc--)
    {
        solve();
    }
}