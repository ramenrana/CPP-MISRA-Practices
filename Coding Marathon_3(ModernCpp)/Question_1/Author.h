#ifndef AUTHOR_H
#define AUTHOR_H

#include <iostream>
#include "Book.h"
#include "BookGenre.h"
#include "BookType.h"
#include <list>
#include <memory>

class Author
{
private:
    std::string authorId;
    std::string authorName;
    std::list<std::shared_ptr<Book>> authorBook;
public:
    
    /// @brief Default constructor is disabled
    Author()=delete;

    /// @brief Copy Constructor is enabled
    Author(Author &obj)=default;

    /// @brief Move Constructor is disabled
    Author(Author &&obj)=delete;

    /// @brief Parameterized constructor
    Author(std::string authorId,
        std::string authorName,
        std::list<std::shared_ptr<Book>> authorBook
        );

    /// @brief Destructor
    ~Author();

    //Getter Setter Functions
    std::string getAuthorId() const { return authorId; }
    void setAuthorId(const std::string &authorId_) { authorId = authorId_; }

    std::string getAuthorName() const { return authorName; }
    void setAuthorName(const std::string &authorName_) { authorName = authorName_; }

    std::list<std::shared_ptr<Book>> getAuthorBook() const { return authorBook; }
    void setAuthorBook(const std::list<std::shared_ptr<Book>> &authorBook_) { authorBook = authorBook_; }


    
    
    friend std::ostream &operator<<(std::ostream &os, const Author &rhs);
};

#endif // AUTHOR_H
