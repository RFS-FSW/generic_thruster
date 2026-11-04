#include <generic_thruster_bsk_data_provider.hpp>
#include <cmath>
namespace Nos3 {
REGISTER_DATA_PROVIDER(Generic_thrusterBskDataProvider, "GENERIC_THRUSTER_BSK_PROVIDER");
Generic_thrusterBskDataProvider::Generic_thrusterBskDataProvider(const boost::property_tree::ptree& config) :
    SimIDataProvider(config),
    _client(config.get("simulator.hardware-model.data-provider.hostname", "localhost"),
            config.get("simulator.hardware-model.data-provider.port", 21205),
            config.get("simulator.hardware-model.data-provider.recv-timeout-ms", 100)) {}
boost::shared_ptr<SimIDataPoint> Generic_thrusterBskDataProvider::get_data_point(void) const {
    return boost::shared_ptr<SimIDataPoint>();
}
bool Generic_thrusterBskDataProvider::cmd_thrust(int thruster, double percent) {
    if (thruster != 0 || !std::isfinite(percent) || percent < 0. || percent > 100.) return false;
    THRArrayCmdForceMsgPayload command{};
    command.thrForce[0] = 22. * percent / 100.;
    return _client.push(&command, sizeof(command));
}
}
