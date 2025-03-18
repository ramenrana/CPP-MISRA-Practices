#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include "BookGenre.h"
#include "BookType.h"
#include <variant>

class Book
{
private:
    std::variant<std::string,int> bookId;
    float bookPrice;
    BookGenre bookGenre;
    BookType bookType;    
public:
    /// @brief Default constructor is disabled
    Book(/* args */)=delete;
    /// @brief Copy Constructor is enabled
    Book(Book &obj)=default;
    /// @brief Move Constructor is disabled
    Book(Book &&obj)=delete;
    /// @brief Parameterized constructor
    Book(
        std::variant<std::string,int> bookId,
        float bookPrice,
        BookGenre bookGenre,
        BookType bookType
    );
    /// @brief Destructor
    ~Book();

    //Getter Setter Functions
    

    float getBookPrice() const { return bookPrice; }
    void setBookPrice(float bookPrice_) { bookPrice = bookPrice_; }

    BookGenre getBookGenre() const { return bookGenre; }
    void setBookGenre(const BookGenre &bookGenre_) { bookGenre = bookGenre_; }

    BookType getBookType() const { return bookType; }
    void setBookType(const BookType &bookType_) { bookType = bookType_; }

    std::variant<std::string,int> getBookId() const { return bookId; }
    void setBookId(const std::variant<std::string,int> &bookId_) { bookId = bookId_; }

    /// @brief overload ostream operator 
    /// @param os 
    /// @param rhs 
    /// @return 
    friend std::ostream &operator<<(std::ostream &os, const Book &rhs);
};

/// @brief Display Book Genre
/// @param type BookGenre
/// @return string

std::string displayBookGenre(BookGenre type);

/// @brief Display Book Type
/// @param type BookType
/// @return string
std::string displayBookType(BookType type);

#endif // BOOK_H
