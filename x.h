#ifndef GLODON_OBJECTBUF_READER_H
#define GLODON_OBJECTBUF_READER_H

#include <QString>
#include <map>
#include "glodon/objectbuf/Objectbuf.h"

namespace glodon {
namespace objectbuf {

class Document;
class EntityFactory;
class Reader;
class FieldCacheInitializer;

typedef void (*RegSchemaInfoProc) (Reader* reader);
typedef void (*FieldCacheProc) ();

///////////////////////////////////////////////////////////////
// dev3
// dev3
//////////////////////////////////////////////////////////////
class Reader
{
public:
    Reader(RegSchemaInfoProc pProc, FieldCacheProc pInitProc, FieldCacheProc pFreeProc);
    ~Reader(void);
    bool read(const QString& sFileName, Document* pDoc);
    void regSchemaInfo(const QString& sName, EntityFactory* pFactory, FieldCacheInitializer* pInitializer);
private:
    void clear();
    std::map<QString, std::pair<EntityFactory*, FieldCacheInitializer*>> m_oSchemaInfoMap;
    std::map<int, EntityFactory*> m_oFactoryList;
    FieldCacheProc m_pFreeProc;
};
//==============================================================

}
}

#endif

