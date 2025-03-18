#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <iostream>
#include "Book.h"
#include "BookGenre.h"
#include "BookType.h"
#include "Author.h"
#include <list>
#include <vector>
#include <memory>
#include <optional>
#include <vector>


using BookPointer =std::shared_ptr<Book>;
using BookContainer = std::list<BookPointer>;

using AuthorPointer =std::shared_ptr<Author>;
using AuthorContainer =std::list<AuthorPointer>;

/*
    Create List of Book object
*/
void CreateBook(BookContainer &data);

/*
    Create List of Author object
*/
void CreateAuthor(AuthorContainer &data,BookContainer &bdata);

/*
    Find N instances of the book which satisfy this conditions:

        -bookPrice >1000;
        -bookGenre is FICTION or ADVENTURE
        -BookType is PAPERBACK or EBOOK
*/
std::optional<AuthorContainer> ReturnNinstances(AuthorContainer &data,int N);

 /*
    Find The Average price of all book which satisfy this conditions
        - Match Book Author Name pass by 
        - bookGenre is BioGraphy
        - BookType is Ebook
 */
std::optional<BookContainer> ReturnAverageOfBook(BookContainer &data,std::string name);

/*
    Return the Container of Author 
        - whose count of books writen by author is at least 2
        - At least one book written by the author is of bookGenre FICTION

*/
std::optional<AuthorContainer> ReturnAuthor(AuthorContainer &data);

/*
    Demonstrate of All functionalities
*/
void Demonstrate();

#endif // FUNCTIONALITIES_H
