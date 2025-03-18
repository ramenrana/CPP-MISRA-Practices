#include "Book.h"
std::ostream &operator<<(std::ostream &os, const Book &rhs) {
    os << "bookId: ";
    std::visit([&](auto &&val){os<<val;},rhs.bookId);
       os<< " bookPrice: " << rhs.bookPrice
       << " bookGenre: " <<displayBookGenre( rhs.bookGenre)
       << " bookType: " <<displayBookType( rhs.bookType);
    return os;
}

std::string displayBookGenre(BookGenre type)
{
    if(BookGenre::ADVENTURE==type){
        return "ADVENTURE";
    }else if(BookGenre::BIOGRAPHY==type){
        return "BIOGRAPHY";
    }else if(BookGenre::FICTION==type){
        return  "FICTION";
    }else{
        return "OTHER";
    }
}

std::string displayBookType(BookType type)
{
    if(BookType::EBOOK==type){
        return "EBOOK";
    }else if(BookType::HARDCOVER==type){
        return "HARDCOVER";
    }else{
        return "PAPERBACK";
    }
}

Book::Book(std::variant<std::string,int> bookId, float bookPrice, BookGenre bookGenre, BookType bookType)
:bookId(bookId),bookPrice(bookPrice),bookGenre(bookGenre),bookType(bookType){
}

Book::~Book()
{
    std::cout<<"Book Deleted\n";
}
