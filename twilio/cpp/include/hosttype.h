#ifndef HOSTTYPE_H_
#define HOSTTYPE_H_

#include <string>

namespace twilio {

class HostType {
public:
    virtual ~HostType () { }

public:
    // Returns the host (instance) type ID.
    virtual std::string getId() = 0;

    // Returns the host (instance) type (role).
    virtual std::string getType() = 0;

    // Returns the host (instance) type description.
    virtual std::string getDescription() = 0;
};

} // namespace twilio

#endif /* HOSTTYPE_H_ */
