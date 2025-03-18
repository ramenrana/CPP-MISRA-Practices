#include "Author.h"
std::ostream &operator<<(std::ostream &os, const Author &rhs) {
    os << "authorId: " << rhs.authorId
       << " authorName: " << rhs.authorName
       << " authorBook: " ;
       for(auto val:rhs.authorBook){
            os<<*val;
       }
    return os;
}

Author::Author(std::string authorId, std::string authorName, std::list<std::shared_ptr<Book>> authorBook)
:authorId(authorId),authorName(authorName),authorBook(authorBook){
}

Author::~Author()
{
    std::cout<<"Author Deleted\n";
}
