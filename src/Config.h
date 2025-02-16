#include <ll/api/base/StdInt.h>

namespace NatPortFixer {
struct Config {
    int    version = 1;
    ushort ipv4    = 19132;
    ushort ipv6    = 19133;
};
} // namespace NatPortFixer