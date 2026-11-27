#include <iostream>
#include "smartretail.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: p4 <data_folder> [store_id]" << endl;
        return 1;
    }
    string folder = argv[1];
    string storeId = "S001";
    if (argc >= 3) storeId = argv[2];

    cout << "RETAIL STAFF ASSISTANT - " << storeId << endl;
    cout << "Data folder: " << folder << endl;
    return 0;
}
