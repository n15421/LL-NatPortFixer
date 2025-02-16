#include "Entry.h"
#include <ila/event/minecraft/server/ServerPongEvent.h>
#include <ll/api/Config.h>
#include <ll/api/event/EventBus.h>
#include <ll/api/mod/RegisterHelper.h>

namespace NatPortFixer {

Entry& Entry::getInstance() {
    static Entry instance;
    return instance;
}

bool Entry::load() {
    auto path = getSelf().getConfigDir() / "config.json";
    try {
        mConfig.emplace();
        ll::config::loadConfig(*mConfig, path);
    } catch (...) {}
    ll::config::saveConfig(*mConfig, path);
    return true;
}

bool Entry::enable() {
    mListener = ll::event::EventBus::getInstance().emplaceListener<ila::mc::ServerPongBeforeEvent>(
        [this](ila::mc::ServerPongBeforeEvent& event) -> void {
            event.getLocalPort()   = mConfig->ipv4;
            event.getLocalPortV6() = mConfig->ipv6;
        }
    );
    return true;
}

bool Entry::disable() {
    ll::event::EventBus::getInstance().removeListener(mListener);
    return true;
}

bool Entry::unload() { return true; }

} // namespace NatPortFixer

LL_REGISTER_MOD(NatPortFixer ::Entry, NatPortFixer ::Entry::getInstance());