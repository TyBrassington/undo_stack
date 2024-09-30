#include "StringList.h"
#include <iostream>

using namespace std;

void testInsertAndUndo() {
    StringList list;
    list.insertBack("apple");
    list.insertBack("banana");
    list.insertBack("cherry");

    cout << "List after inserting 3 elements: " << list.toString() << endl;

    // Perform undo
    list.undo();
    cout << "List after undoing last insert: " << list.toString() << endl;
}

void testRemoveAndUndo() {
    StringList list;
    list.insertBack("apple");
    list.insertBack("banana");
    list.insertBack("cherry");

    cout << "List after inserting 3 elements: " << list.toString() << endl;

    // Remove element
    list.remove(1); // Remove "banana"
    cout << "List after removing 'banana': " << list.toString() << endl;

    // Perform undo
    list.undo();
    cout << "List after undoing removal: " << list.toString() << endl;
}

void testSetAndUndo() {
    StringList list;
    list.insertBack("apple");
    list.insertBack("banana");

    cout << "Original list: " << list.toString() << endl;

    // Change value
    list.set(1, "orange");
    cout << "List after setting 'banana' to 'orange': " << list.toString() << endl;

    // Perform undo
    list.undo();
    cout << "List after undoing set: " << list.toString() << endl;
}

void testRestoreAndUndo() {
    StringList list;
    list.insertBack("apple");
    list.insertBack("banana");
    list.insertBack("cherry");

    cout << "Original list: " << list.toString() << endl;

    // Remove all elements
    list.removeAll();
    cout << "List after removeAll: " << list.toString() << endl;

    // Perform undo (should restore the previous state of the list)
    list.undo();
    cout << "List after undoing removeAll (restore): " << list.toString() << endl;
}

void testDeepCopy() {
    StringList original;
    original.insertBack("apple");
    original.insertBack("banana");
    original.insertBack("cherry");

    // Perform a deep copy
    StringList copy = original;

    cout << "Original list: " << original.toString() << endl;
    cout << "Copied list: " << copy.toString() << endl;

    // Modify the copied list
    copy.set(1, "orange");

    // Verify that modifying the copy does not affect the original
    cout << "After modifying the copied list:" << endl;
    cout << "Original list: " << original.toString() << endl; // Should remain unchanged
    cout << "Copied list: " << copy.toString() << endl;       // Should reflect the changes
}

int main() {
    cout << "Testing insert and undo:" << endl;
    testInsertAndUndo();

    cout << "\nTesting remove and undo:" << endl;
    testRemoveAndUndo();

    cout << "\nTesting set and undo:" << endl;
    testSetAndUndo();

    cout << "\nTesting removeAll (restore) and undo:" << endl;
    testRestoreAndUndo();

    cout << "\nTesting Deep Copy:" << endl;
    testDeepCopy();

    return 0;
}
