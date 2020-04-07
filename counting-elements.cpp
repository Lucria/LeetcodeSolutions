#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <string>
#include <sstream>
#include <list>
#include <stack>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int countElements(vector<int>& arr) {
    int result = 0;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++) {
        int chosen = arr[i] + 1;
        auto low = lower_bound(arr.begin(), arr.end(), chosen);
        auto high = upper_bound(arr.begin(), arr.end(), chosen);
        if (low == arr.end() || *low != chosen) {
            continue;
        } else {
            cout << "Current element is" << arr[i] << endl;
            result++;
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<string> tempSplit;
    string tempInput;
    getline(cin, tempInput);
    istringstream tempStream(tempInput);
    string tempInput2;
    while (getline(tempStream, tempInput2, ' ')) {
        tempSplit.push_back(tempInput2);
    }

    vector<int> properInput;
    for (auto i : tempSplit) {
        properInput.push_back(stoi(i));
    }

    cout << countElements(properInput) << endl; 
}