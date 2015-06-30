#ifndef GLODON_OBJECTBUF_ENTITY_H
#define GLODON_OBJECTBUF_ENTITY_H

#include <google/protobuf/io/coded_stream.h>
#include "glodon/objectbuf/Objectbuf.h"

//using namespace google::protobuf;

namespace glodon {
namespace objectbuf {

class EntitySchema;

enum EnParseFieldState {
    PFS_FAIL,
    PFS_SUCCESS,
    PFS_IGNORE
};

class Document;

class Entity
{
public:
    Entity(void);
    virtual ~Entity(void);
    static void setDocument(Document* pDocument);
    bool serialize(google::protobuf::io::CodedOutputStream* output) const;
    bool parse(google::protobuf::io::CodedInputStream* input);
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual int byteSize() const;
    virtual int typeId() const = 0;
    virtual bool isInitialized() const;
protected:
    virtual void serializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output) const;
    virtual google::protobuf::uint8* serializeWithCachedSizesToArray(google::protobuf::uint8* target) const;
    virtual EnParseFieldState parseField(google::protobuf::io::CodedInputStream* input, int nFieldNum);
    static Document* m_pDocument;
//    virtual bool parseFromCodedStream(io::CodedInputStream* input);
};

typedef int EntityRef;

}
}

#endif
