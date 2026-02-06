#include <iostream>
#include <vector>
using namespace std;

class Book {
private:
    string title;
    string isbn;
    bool available;

public:
    Book(string t, string i) {
        title = t;
        isbn = i;
        available = true;
    }

    string getISBN() { return isbn; }
    string getTitle() { return title; }
    bool isAvailable() { return available; }

    void borrow() { available = false; }
    void giveBack() { available =  true; }

    void display() {
        cout << title << " (" << isbn << ") - "
             << (available ? "Available" : "Borrowed") << endl;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(Book b) {
        books.push_back(b);
    }

    void searchBook(string isbn) {
        for (int i = 0; i < books.size(); i++) {
            if (books[i].getISBN() == isbn) {
                books[i].display();
                return;
            }
        }
        cout << "Book not found\n";
    }

    void borrowBook(string isbn) {
        for (int i = 0; i < books.size(); i++) {
            if (books[i].getISBN() == isbn && books[i].isAvailable()) {
                books[i].borrow();
                cout << "Book borrowed successfully\n";
                return;
            }
        }
        cout << "Cannot borrow book\n";
    }

    void returnBook(string isbn) {
        for (int i = 0; i < books.size(); i++) {
            if (books[i].getISBN() == isbn) {
                books[i].giveBack();
                cout << "book returned successfully \n";
                return;
            }
        }
        cout << "Book not found\n";
    }

    void showAllBooks() {
        for (int i = 0; i < books.size(); i++) {
            books[i].display();
        }
    }
};

int main() {
    Library lib;

    lib.addBook(Book("C++ basics", "101"));
    lib.addBook(Book("Cyber Security", "102"));

    lib.showAllBooks();

    lib.borrowBook("101");
    lib.showAllBooks();

    lib.returnBook("101");
    lib.showAllBooks();

    return 0;
}
