#include <iostream>
#include <vector>
using namespace std;

void hanoi(int n, char from, char to, char med) {
    if (n == 1) {
        cout << "Move disk 1 from " << from << " to " << to << endl;
        return;
    }
    hanoi(n - 1, from, med, to);
    cout << "Move disk " << n << " from " << from << " to " << to << endl;
    hanoi(n - 1, med, to, from);
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;
    hanoi(n, 'A', 'C', 'B');
    return 0;
}
