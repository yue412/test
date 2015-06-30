#ifndef GLODON_OBJECTBUF_ENTITYFACTORY_H
#define GLODON_OBJECTBUF_ENTITYFACTORY_H

#include "glodon/objectbuf/Objectbuf.h"

namespace glodon {
namespace objectbuf {

class Entity;

class EntityFactory
{
public:
    EntityFactory(void);
    ~EntityFactory(void);
    virtual Entity* create() = 0;
};

}
}

#endif

