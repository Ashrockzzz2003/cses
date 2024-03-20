/*
The Tower of Hanoi game consists of three stacks (left, middle and right) and n round disks of different sizes. Initially, the left stack has all the disks, in increasing order of size from top to bottom. 

The goal is to move all the disks to the right stack using the middle stack. On each move you can move the uppermost disk from a stack to another stack. In addition, it is not allowed to place a larger disk on a smaller disk.
Your task is to find a solution that minimizes the number of moves.
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define ll long long

void minMoves(int n, int from, int to, int aux) {
    if (n == 1) {
        cout << from << " " << to << endl;
        return;
    }

    minMoves(n-1, from, aux, to); // move n-1 disks from 'from' to 'aux' using 'to'
    cout << from << " " << to << endl;
    minMoves(n-1, aux, to, from); // move n-1 disks from 'aux' to 'to' using 'from'
}

int main() {
    ll n;
    cin >> n;

    cout << (1 << n) - 1 << endl; // 2^n - 1
    minMoves(n, 1, 3, 2);
}