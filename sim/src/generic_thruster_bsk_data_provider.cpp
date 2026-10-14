#include <generic_thruster_bsk_data_provider.hpp>
namespace Nos3 {
REGISTER_DATA_PROVIDER(Generic_thrusterBskDataProvider, "GENERIC_THRUSTER_BSK_PROVIDER");
Generic_thrusterBskDataProvider::Generic_thrusterBskDataProvider(const boost::property_tree::ptree& config) :
    SimIDataProvider(config),
    _client(config.get("simulator.hardware-model.data-provider.hostname", "localhost"),
            config.get("simulator.hardware-model.data-provider.port", 11000), 0, 0) {}
boost::shared_ptr<SimIDataPoint> Generic_thrusterBskDataProvider::get_data_point(void) const {
    return boost::shared_ptr<SimIDataPoint>();
}
bool Generic_thrusterBskDataProvider::cmd_thrust(int thruster, double percent) {
    return _client.set_thruster_percent(thruster, percent);
}
}
