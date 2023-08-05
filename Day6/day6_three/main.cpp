#include<bits/stdc++.h>
using namespace std;


int main() {

    int number_of_queries, queue_type, value;
    cin >> number_of_queries;

    queue<int> storage_queue;

    for(int i = 0; i < number_of_queries; i++){

        cin >> queue_type;

        switch(queue_type){

            case 1:
                cin >> value;
                storage_queue.push(value);
                break;

            case 2:
                storage_queue.pop();
                break;

            case 3:
                cout << storage_queue.front() << endl;
        }
    }

    return 0;
}
