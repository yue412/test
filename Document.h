#ifndef GLODON_OBJECTBUF_DOCUMENT_H
#define GLODON_OBJECTBUF_DOCUMENT_H

#include <QString>
#include <map>
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/Objectbuf.h"

namespace glodon {
namespace objectbuf {

class DocumentIterator;

//
class Document
{
public:
    Document(void);
    ~Document(void);
    void add(int nId, Entity* pEntity);
    Entity* find(int nId);
    DocumentIterator getIterator();
private:
    void clear();
    std::map<int, Entity*> m_oEntityMap;
};

// µü´úÆ÷
class DocumentIterator
{
public:
    DocumentIterator(std::map<int, Entity*>* pEntityMap): m_pEntityMap(pEntityMap) {}
    void first() {m_oItr = m_pEntityMap->begin();}
    void next() {++m_oItr;}
    bool isDone() {return m_oItr == m_pEntityMap->end();}
    Entity* current() {return m_oItr->second;}
private:
    std::map<int, Entity*>* m_pEntityMap;
    std::map<int, Entity*>::iterator m_oItr;
};

}
}

#endif

