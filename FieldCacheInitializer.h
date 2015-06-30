#ifndef GLODON_OBJECTBUF_FIELDCACHEINITIALIZER_H
#define GLODON_OBJECTBUF_FIELDCACHEINITIALIZER_H

#include <map>
#include <QString>
#include "glodon/objectbuf/Objectbuf.h"

namespace glodon {
namespace objectbuf {

class FieldCacheInitializer
{
public:
    FieldCacheInitializer(void);
    ~FieldCacheInitializer(void);
    int getFieldId(const std::map<QString, int>& oFieldIdMap, const QString& sName)
    {
        auto oItr = oFieldIdMap.find(sName);
        return oItr == oFieldIdMap.end() ? 0 : oItr->second;
    }
    virtual void init(const std::map<QString, int>& oFieldIdMap) = 0;
};

}
}

#endif