#include<iostream>
#include<vector>
#include <algorithm>
#include <random>
using namespace std;

vector<vector<int>> get_input_vectors(int n) {
    // Original vector
    vector<int> original = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

    // Vector to store permutations
    std::vector<std::vector<int>> permutations;

    // Random number generator
    std::random_device rd;
    std::mt19937 g(rd());

    // Generate 20 random permutations
    for (int i = 0; i < n; ++i) {
        std::vector<int> perm = original;
        std::shuffle(perm.begin(), perm.end(), g);
        permutations.push_back(perm);
    }

    return permutations;
}


class BinaryIndexedTree {
public:
    int size; // Size of the array
    vector<int> tree; // BIT data structure

    // Constructor to initialize the BIT with a given size.
    BinaryIndexedTree(int n): size(n), tree(n + 1) {}

    // Updates the BIT at a specific index by a value delta.
    void update(int index, int delta) {
        for (; index <= size; index += index & -index) {
            tree[index] += delta;
        }
    }

    // Queries the prefix sum from the start to a specific index.
    int query(int index) {
        int sum = 0;
        for (; index; index -= index & -index) {
            sum += tree[index];
        }
        return sum;
    }
};

class Solution_algomonster {
public:
    // Method to find the first day where there are 'k' empty slots between two bulbs.
    int kEmptySlots(vector<int>& bulbs, int k) {
        int n = bulbs.size();
        BinaryIndexedTree bit(n); // Instance of BIT
        vector<bool> isOn(n + 1, false); // Tracks if a bulb is turned on

        for (int day = 1; day <= n; ++day) {
            int current = bulbs[day - 1];
            bit.update(current, 1); // Turn on the bulb at position 'current' and update BIT
            isOn[current] = true;

            // Check the left side of the current bulb
            int leftNeighbor = current - k - 1;
            if (leftNeighbor > 0 && isOn[leftNeighbor] && bit.query(current - 1) - bit.query(leftNeighbor) == 0) {
                return day;
            }

            // Check the right side of the current bulb
            int rightNeighbor = current + k + 1;
            if (rightNeighbor <= n && isOn[rightNeighbor] && bit.query(rightNeighbor - 1) - bit.query(current) == 0) {
                return day;
            }
        }

        return -1; // Return -1 if no such day is found
    }
};

class Solution {

    //turn on bulb at index: indx. so update the tree
    public:
     void add(vector<int> &tree, int node, int b, int e, int indx) {
        
        if(b == e) {
            if(b == indx) {
                tree[node] = 1;
            }
            // tree[node] = (int)(b == indx);
            return;
        }

        if(indx < b || e < indx) return;

        tree[node]++;
        int mid = (b + e) / 2;
        add(tree, node * 2, b, mid, indx);
        add(tree, node * 2 + 1, mid + 1, e, indx);
    }

    //count number of on bulds between index i and j (inclusive)
    int cnt(vector<int> &tree, int node, int b, int e, int i, int j) {

        if(j < b || e < i) return 0;

        if(i <= b && e <= j) {
            return tree[node];
        }

        int mid = (b + e) / 2;
        
        return cnt(tree, node * 2, b, mid, i, j) + 
                cnt(tree, node * 2 + 1, mid + 1, e, i, j);
    }

public:
    
    int kEmptySlots(vector<int>& bulbs, int k) {
        
        int n = bulbs.size();

        if(k > n - 2) return -1;
        
        vector<int> tree(n * 4);
        vector<bool> isOn(n + 1);
        for(int i = 0; i < n; i++) {
            int indx = bulbs[i];

            if(indx + k + 1 <= n && isOn[indx + k + 1] && cnt(tree, 1, 1, n, indx + 1, indx + k + 1) == 1) return (i + 1);

            if(indx - k - 1 >= 0 && isOn[indx - k - 1] && cnt(tree, 1, 1, n, indx - k - 1, indx - 1) == 1) return (i + 1);
            
            add(tree, 1, 1, n, bulbs[i]);
            isOn[indx] = true;
        }

        return -1;
    }
};

int main() {
    
    Solution my_solution;
    Solution_algomonster algomonster_solution;

    // Vector for bulb sequences
    std::vector<std::vector<int>> bulb_sequences = get_input_vectors(30);

    for(int i = 0; i < bulb_sequences.size(); i++) {
        for(int k = 0; k < 100; k++) {
            int found = my_solution.kEmptySlots(bulb_sequences[i], k);
            int expected = algomonster_solution.kEmptySlots(bulb_sequences[i], k);
            if(found != expected) {
                cout<<"mismatch i = "<<i<<" expected = "<<expected<<" found = "<<found<<endl;
                cout<<"{";
                for(int j = 0; j < bulb_sequences[i].size(); j++) {
                    cout<<bulb_sequences[i][j]<<",";
                }
                cout<<"}"<<endl;
                cout<<k<<endl;
            }
        }
    }

    // vector<int> v = {2, 1, 4, 5, 6, 3};
    // vector<int> tree(v.size() * 4);
    // for(int i = 0; i < v.size(); i++) {
    //     my_solution.add(tree, 1, 1, v.size(), v[i]);
    //     cout<<my_solution.cnt(tree, 1, 1,v.size(), 2, 4)<<endl;
    // }
    return 0;
}