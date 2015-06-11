/*
 * hosttypeimpl.h
 *
 *  Created on: Nov 17, 2014
 *      Author: ykhodosh
 */

#ifndef HOSTTYPEIMPL_H_
#define HOSTTYPEIMPL_H_

#include "hosttype.h"

namespace twilio
{

class HostTypeImpl: public HostType
{
public:
    HostTypeImpl ();
    virtual ~HostTypeImpl () {
        // TODO Auto-generated destructor stub
    }

public:
    // Returns the host (instance) type ID.
    virtual std::string getId() { return this->id_; }

    // Returns the host (instance) type (role).
    virtual std::string getType() { return this->type_; }

    // Returns the host (instance) type description.
    virtual std::string getDescription() { return this->description_; }

private:
    std::string id_;
    std::string type_;
    std::string description_;
};

} /* namespace twilio */

#endif /* HOSTTYPEIMPL_H_ */
