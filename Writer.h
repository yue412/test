#ifndef GLODON_OBJECTBUF_WRITER_H
#define GLODON_OBJECTBUF_WRITER_H

#include <QString>
#include "Entity.h"
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <fstream>
#include <map>
#include "glodon/objectbuf/Objectbuf.h"

namespace glodon {
namespace objectbuf {

// hehe next
class Writer
{
public:
    Writer(void);
    ~Writer(void);
    void open(const QString& sFileName);
    void close();
    EntityRef writeEntity(Entity* pEntity); 
private:
    void writeSchema(EntitySchema* pSchema);
    std::fstream* m_pFileStream;
    google::protobuf::io::OstreamOutputStream* m_pZeroCopyStream;
    google::protobuf::io::CodedOutputStream* m_pCodedOutputStream;
    std::map<int, bool> m_oTypeMap;
    int m_nCount;
};

}
}

#endif
