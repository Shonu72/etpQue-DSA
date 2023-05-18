#include <iostream>
#include <list> // For linked list
using namespace std;

class HashTable
{
private:
    static const int tableSize = 100;      // Size of hash table
    list<pair<int, int>> table[tableSize]; // Array of linked lists to store key-value pairs

public:
    // Hash function
    int HashFunc(int k)
    {
        return k % tableSize;
    }

    // Insert key-value pair into hash table
    void Insert(int k, int v)
    {
        int index = HashFunc(k);                     // Get index to insert at
        bool keyExists = false;                      // Flag to check if key already exists
        list<pair<int, int>> &bucket = table[index]; // Get the bucket at index

        // Check if key already exists in bucket, and update value if it does
        for (auto &pair : bucket)
        {
            if (pair.first == k)
            {
                pair.second = v;
                keyExists = true;
                break;
            }
        }

        // If key does not exist in bucket, insert new key-value pair
        if (!keyExists)
        {
            bucket.push_back(make_pair(k, v));
        }
    }

    // Search for key in hash table and return value if found
    int Search(int k)
    {
        int index = HashFunc(k);                     // Get index to search at
        list<pair<int, int>> &bucket = table[index]; // Get the bucket at index

        // Search for key in bucket
        for (const auto &pair : bucket)
        {
            if (pair.first == k)
            {
                return pair.second;
            }
        }

        // If key not found, return -1
        return -1;
    }

    // Display all key-value pairs in hash table
    void Display()
    {
        for (int i = 0; i < tableSize; i++)
        { // Iterate through each bucket in the table
            list<pair<int, int>> &bucket = table[i];
            if (!bucket.empty())
            { // If bucket is not empty
                for (const auto &pair : bucket)
                { // Iterate through key-value pairs in bucket
                    cout << "(" << pair.first << "," << pair.second << ") ";
                }
                cout << endl;
            }
        }
    }
};

int main()
{
    HashTable ht;

    // Insert key-value pairs
    ht.Insert(1, 10);
    ht.Insert(2, 20);
    ht.Insert(3, 30);
    ht.Insert(101, 40);
    ht.Insert(102, 50);

    // Search for keys and display values
    cout << "Value of key 1: " << ht.Search(1) << endl;
    cout << "Value of key 101: " << ht.Search(101) << endl;
    cout << "Value of key 5: " << ht.Search(5) << endl;

    // Display contents of hash table
    cout << "Contents of hash table:" << endl;
    ht.Display();

    return 0;
}
