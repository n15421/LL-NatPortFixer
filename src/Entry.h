#include "Config.h"
#include <ll/api/event/ListenerBase.h>
#include <ll/api/mod/NativeMod.h>
#include <optional>

namespace NatPortFixer {

class Entry {

public:
    static Entry& getInstance();

    Entry() : mSelf(*ll::mod::NativeMod::current()) {}

    [[nodiscard]] ll::mod::NativeMod& getSelf() const { return mSelf; }

    bool load();

    bool enable();

    bool disable();

    bool unload();

private:
    ll::mod::NativeMod&    mSelf;
    std::optional<Config>  mConfig;
    ll::event::ListenerPtr mListener;
};

} // namespace NatPortFixer