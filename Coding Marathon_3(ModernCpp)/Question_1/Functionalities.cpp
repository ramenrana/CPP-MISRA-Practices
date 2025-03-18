#include <iostream>
#include "Functionalities.h"

/*
    Create List of Book object
*/
void CreateBook(BookContainer &data)
{
    data.emplace_back(
        std::make_shared<Book>("1001", 9898.0f, BookGenre::ADVENTURE, BookType::HARDCOVER));
    data.emplace_back(
        std::make_shared<Book>("1002", 9000.0f, BookGenre::FICTION, BookType::EBOOK));
    data.emplace_back(
        std::make_shared<Book>(1003, 4000.0f, BookGenre::FICTION, BookType::EBOOK));
}

/*
    Create List of Author object
*/
void CreateAuthor(AuthorContainer &data, BookContainer &bdata)
{
    auto itr = bdata.begin();
    data.emplace_back(
        std::make_shared<Author>(
            "100A",
            "XXXX",
            std::list<std::shared_ptr<Book>>{*itr}));

    data.emplace_back(
        std::make_shared<Author>(
            "100A",
            "YYYY",
            std::list<std::shared_ptr<Book>>{*itr, *itr++}));
}

/*
    Find N instances of the book which satisfy this conditions:

        -bookPrice >1000;
        -bookGenre is FICTION or ADVENTURE
        -BookType is PAPERBACK or EBOOK
*/
std::optional<BookContainer> ReturnNinstances(BookContainer &datan, int N)
{

    if (datan.empty() && N >= datan.size())
    {
        return {};
    }

    BookContainer result;
    for (auto &val : datan)
    {
        if (N <= datan.size())
        {
            if ((*val).getBookPrice() > 1000.0f &&
                ((*val).getBookGenre() == BookGenre::ADVENTURE || (*val).getBookGenre() == BookGenre::FICTION) && ((*val).getBookType() == BookType::PAPERBACK || (*val).getBookType() == BookType::EBOOK))
            {
                result.emplace_back(val);
            }

            N--;
        }
    }

    if (result.empty())
    {
        return {};
    }
    else
    {
        return result;
    }
}

/*
   Find The Average price of all book which satisfy this conditions
       - Match Book Author Name pass by
       - bookGenre is BioGraphy
       - BookType is Ebook
*/
std::optional<AuthorContainer> ReturnAverageOfBook(AuthorContainer &data, std::string name)
{
    if (data.empty())
    {
        return {};
    }

    AuthorContainer result;

    for (auto &val : data)
    {

        if ((*val).getAuthorName() == name)
        {
            for (auto &val1 : (*val).getAuthorBook())
            {
                if ((*val1).getBookGenre() == BookGenre::BIOGRAPHY && (*val1).getBookType() == BookType::EBOOK)
                {
                    result.emplace_back(val);
                }
            }
        }
    }

    if (result.empty())
    {
        return {};
    }
    else
    {
        return result;
    }
}

/*
    Return the Container of Author
        - whose count of books writen by author is at least 2
        - At least one book written by the author is of bookGenre FICTION

*/
std::optional<AuthorContainer> ReturnAuthor(AuthorContainer &data)
{
    if (data.empty())
    {
        return {};
    }

    AuthorContainer result;

    for (auto &val : data)
    {
        int count = 0;
        for (auto &val1 : (*val).getAuthorBook())
        {
            count++;
        }
        if (count >= 2)
        {
            for (auto &val2 : (*val).getAuthorBook())
            {
                if ((*val2).getBookGenre() == BookGenre::FICTION)
                {
                    result.emplace_back(val);
                }
            }
        }

    }

    if (result.empty())
    {
        return {};
    }
    else
    {
        return result;
    }
}

/*
    Demonstrate of All functionalities
*/
void Demonstrate()
{

    BookContainer Bdata;
    AuthorContainer Adata;

    CreateBook(Bdata);
    CreateAuthor(Adata, Bdata);
    for(auto &val: Adata){
        std::cout<<*val<<"\n";
    }

    std::optional<BookContainer> res = ReturnNinstances(Bdata, 2);
    if (res.has_value())
    {
        for (auto &val : res.value())
        {
            std::cout << *val;
        }
    }
    else
    {
        std::cout << "Value Not Found";
    }

    std::optional<AuthorContainer> res1 = ReturnAverageOfBook(Adata,"YYYY");
    if (res1.has_value())
    {
        for (auto &val : res1.value())
        {
            std::cout << *val;
        }
    }
    else
    {
        std::cout << "Value Not Found";
    }

    std::optional<AuthorContainer> res2 = ReturnAuthor(Adata);
    if (res2.has_value())
    {
        for (auto &val : res2.value())
        {
            std::cout << *val;
        }
    }
    else
    {
        std::cout << "Value Not Found";
    }
}
