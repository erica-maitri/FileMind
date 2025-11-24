#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <stdexcept>

using namespace std;

// Book Class
class Book {
public:
    int id;
    string title;
    bool available;

    Book(int id, string title) : id(id), title(title), available(true) {}

    void issue() { available = false; }
    void returnBook() { available = true; }

    void display() {
        cout << "ID: " << id << " | Title: " << title 
             << " | Status: " << (available ? "Available" : "Issued") << endl;
    }
};

// Member Class
class Member {
public:
    int memberId;
    string name;
    list<Book*> issuedBooks;

    Member(int id, string name) : memberId(id), name(name) {}

    void issueBook(Book* book) {
        if (issuedBooks.size() >= 3) throw runtime_error("Max issue limit reached!");
        issuedBooks.push_back(book);
        book->issue();
    }

    void returnBook(Book* book) {
        issuedBooks.remove(book);
        book->returnBook();
    }

    void displayIssuedBooks() {
        cout << "Issued Books for " << name << " (ID: " << memberId << ")\n";
        if (issuedBooks.empty()) cout << "No books issued.\n";
        else for (Book* book : issuedBooks) book->display();
    }
};

// Transaction Class
class Transaction {
public:
    stack<Book*> issueStack;
    queue<Book*> returnQueue;

    void issueBook(Book* book) { issueStack.push(book); }
    void returnBook(Book* book) { returnQueue.push(book); }

    void displayRecentTransactions() {
        cout << "\nRecent Issued Books:\n";
        if (issueStack.empty()) cout << "No recent issues.\n";
        else while (!issueStack.empty()) { issueStack.top()->display(); issueStack.pop(); }

        cout << "\nRecent Returned Books:\n";
        if (returnQueue.empty()) cout << "No recent returns.\n";
        else while (!returnQueue.empty()) { returnQueue.front()->display(); returnQueue.pop(); }
    }
};

// Library Class
class Library {
public:
    vector<Book> books;
    list<Member> members;
    Transaction transactions;

    void addBook(int id, string title) { books.emplace_back(id, title); }
    void registerMember(int id, string name) { members.emplace_back(id, name); }

    Book* findBook(int id) {
        for (auto& book : books) if (book.id == id) return &book;
        cout << "Error: Invalid Book ID!\n"; return nullptr;
    }

    Member* findMember(int id) {
        for (auto& member : members) if (member.memberId == id) return &member;
        cout << "Error: Invalid Member ID!\n"; return nullptr;
    }

    void displayBooks() {
        for (auto& book : books) book.display();
    }
};

int main() {
    Library lib;
    lib.addBook(1, "C++ Programming");
    lib.addBook(2, "Data Structures");
    lib.registerMember(101, "Alice");
    lib.registerMember(102, "Bob");

    int choice;
    while (true) {
        cout << "\nLibrary Menu:\n1. Display Books\n2. Issue Book\n3. Return Book\n4. View Transactions\n5. View Issued Books\n6. Exit\n";
        cin >> choice;

        if (choice == 1) lib.displayBooks();
        else if (choice == 2) {
            int memberId, bookId;
            cout << "Enter Member ID & Book ID: "; cin >> memberId >> bookId;
            Member* member = lib.findMember(memberId);
            Book* book = lib.findBook(bookId);
            if (member && book) {
                try { member->issueBook(book); lib.transactions.issueBook(book); cout << "Book issued!\n"; }
                catch (exception& e) { cout << "Error: " << e.what() << endl; }
            }
        } else if (choice == 3) {
            int memberId, bookId;
            cout << "Enter Member ID & Book ID: "; cin >> memberId >> bookId;
            Member* member = lib.findMember(memberId);
            Book* book = lib.findBook(bookId);
            if (member && book) {
                try { member->returnBook(book); lib.transactions.returnBook(book); cout << "Book returned!\n"; }
                catch (exception& e) { cout << "Error: " << e.what() << endl; }
            }
        } else if (choice == 4) lib.transactions.displayRecentTransactions();
        else if (choice == 5) {
            int memberId;
            cout << "Enter Member ID: "; cin >> memberId;
            Member* member = lib.findMember(memberId);
            if (member) member->displayIssuedBooks();
        } else if (choice == 6) { cout << "Exiting...\n"; break; }
        else cout << "Invalid choice!\n";
    }
    return 0;
}