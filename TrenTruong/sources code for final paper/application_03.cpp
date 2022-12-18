//Applying a permutation k times
#include <iostream>
#include <vector>

using namespace std;

vector<int> applyPermutation(vector<int> sequence, vector<int> permutation) {
    vector<int> newSequence(sequence.size());
    for(int i = 0; i < sequence.size(); i++) {
        newSequence[i] = sequence[permutation[i]];
    }
    return newSequence;
}

vector<int> permute(vector<int> sequence, vector<int> permutation, long long b) {
    while (b > 0) {
        if (b & 1) {
            sequence = applyPermutation(sequence, permutation);
        }
        permutation = applyPermutation(permutation, permutation);
        b >>= 1;
    }
    return sequence;
}

int main() {
    // Example usage of permute function
    vector<int> sequence = {1, 2, 3, 4};
    vector<int> permutation = {3, 2, 1, 0};
    long long b = 3;

    vector<int> permutedSequence = permute(sequence, permutation, b);

    cout << "Original sequence: ";
    for (int i : sequence) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Permuted sequence: ";
    for (int i : permutedSequence) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
