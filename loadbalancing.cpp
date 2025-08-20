#include <iostream>

#include <string>

using namespace std;


int main() {

    int s, r;

    cout << "Enter the number of servers: ";

    cin >> s;

    cout << "Enter the number of incoming requests: ";

    cin >> r;


    string hash_server[100][100];  // server storage

    int server_count[100] = {0};   // number of requests per server

    string all_requests[100];      // store requests in input order

    int request_server[100];       // store which server handled each request


    cout << "\nEnter request IDs:\n";

    for (int i = 0; i < r; i++) {

        cout << "Request " << i + 1 << ": ";

        cin >> all_requests[i];


        // hash function for string request

        size_t hash_val = hash<string>{}(all_requests[i]) % s;


        // store request in server

        hash_server[hash_val][server_count[hash_val]] = all_requests[i];

        server_count[hash_val]++;


        // also keep mapping of request -> server

        request_server[i] = hash_val;

    }


    // Now display assignment of each request

    cout << "\nRequest Distribution:\n";

    for (int i = 0; i < r; i++) {

        cout << "Request '" << all_requests[i] 

             << "' is handled by Server " << request_server[i] << endl;

    }


    // Display Server Load Summary

    cout << "\nServer Load Summary:\n";

    for (int i = 0; i < s; i++) {

        cout << "Server " << i << " handled " << server_count[i] << " requests";

        if (server_count[i] > 0) {

            cout << ": ";

            for (int j = 0; j < server_count[i]; j++) {

                cout << hash_server[i][j];

                if (j < server_count[i] - 1) cout << ", ";

            }

        }

        cout << endl;

    }


    return 0;

}
