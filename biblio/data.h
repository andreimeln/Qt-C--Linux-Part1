#ifndef DATA_H
#define DATA_H

#include <QString>

namespace BIBLIO {
namespace DATA {

struct Object
{
    QString Author; //  char szAuthor[256]; - worse, doesn't support encoding
    QString Title;
    QString Subtitle;
    QString Location;
    QString Publisher;
    int     Year;
    virtual ~Object() {}; // needed for dynamic_cast; = class object;public:

};

struct Book : public Object
{
    int TotalPages;
};

struct Article : public Object
{
    QString Journal;
    QString Volume;
    QString Issue;
    QString Pages;
};

} // namespace DATA
/*
class Book : ...
{
private:
    Data::Book *Dt;
public:
    DATA::Book * data() { return Dt; }
}
*/
} // namespace BIBLIO

#endif // DATA_H
