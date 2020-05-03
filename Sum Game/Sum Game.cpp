#include <iostream>
#include<vector>
#include <iostream>
#include <iomanip>

using namespace std;
using std::setw;


const int M = 21;
const int N = 5;
vector<vector<int>> calculated_values;


int check_win(int x, int y) {
    if (x >= M && y >= M) {
        return 0;
    }
    if (calculated_values[x][y] != 2) {
        return calculated_values[x][y];
    }
    for (int k = 1; k <= N; ++k) {
        if ((x + k <= M) && check_win(x + k, y) == 0) {
            calculated_values[x][y] = 1;
            return 1;
        }

        if ((y + k <= M) && check_win(x , y + k) == 0) {
            calculated_values[x][y] = 1;
            return 1;
        }


    }
    calculated_values[x][y] = 0;
    return 0;
}

void print_matrix() {
    for (int x = 0; x <= M; ++x) {
        for (int y = 0; y <= M; ++y) {
            cout << setw(2) << check_win(x, y);
        }
        cout << "\n";
    }
    cout << "\n";
}
int main()
{
    vector<int> tmp(M + 1, 2);
    for (int i = 0; i <= M; ++i) {
        calculated_values.push_back(tmp);
    }

    print_matrix();
}