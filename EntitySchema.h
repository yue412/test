#ifndef GLODON_OBJECTBUF_ENTITYSCHEMA_H
#define GLODON_OBJECTBUF_ENTITYSCHEMA_H

#include <vector>
#include <QString>
#include <google/protobuf/io/coded_stream.h>
#include "Entity.h"
#include "glodon/objectbuf/Objectbuf.h"

namespace glodon {
namespace objectbuf {

class EntitySchema: public glodon::objectbuf::Entity
{
public:
    EntitySchema(void);
    ~EntitySchema(void);
    int byteSize() const;
    bool isInitialized() const;
    int typeId() const;

    void setName(const QString& sValue)
    {
        m_sName = sValue;
        setHasName();
    }
    QString getName() const {return m_sName;}
    bool hasName() const {return (_has_bits_[0] & 0x1u) != 0;}

    void setId(const int& nValue)
    {
        m_nId = nValue;
        setHasId();
    }
    int getId() const {return m_nId;}
    bool hasId() const {return (_has_bits_[0] & 0x2u) != 0;}

    int getAttribNamesCount() const {return (int)m_oAttribNames.size();}
    void clearAttribNames() {m_oAttribNames.clear();}
    void addAttribNames(const QString& sValue) {m_oAttribNames.push_back(sValue);}
    QString getAttribNames(int nIndex) const {return m_oAttribNames[nIndex];}

    int getAttribIdsCount() const {return (int)m_oAttribIds.size();}
    void clearAttribIds() {m_oAttribIds.clear();}
    void addAttribIds(const int& nValue) {m_oAttribIds.push_back(nValue);}
    int getAttribIds(int nIndex) const {return m_oAttribIds[nIndex];}

    void setParent(EntitySchema* pParent) {m_pParent = pParent;}
    EntitySchema* getParent() {return m_pParent;}

protected:
    virtual void serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output) const;
    virtual google::protobuf::uint8* serializeWithCachedSizesToArray(google::protobuf::uint8* target) const;
    virtual EnParseFieldState parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum);

protected:
    google::protobuf::uint32 _has_bits_[1];

private:
    void setHasName() {_has_bits_[0] |= 0x1u;}
    void setHasId() {_has_bits_[0] |= 0x2u;}

    QString m_sName;
    int m_nId;
    std::vector<QString> m_oAttribNames;
    std::vector<int> m_oAttribIds;
    EntitySchema* m_pParent;

};

}
}

#endif