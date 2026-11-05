#ifndef NOS3_GENERIC_THRUSTER_BSK_PROVIDER_HPP
#define NOS3_GENERIC_THRUSTER_BSK_PROVIDER_HPP
#include <bsk_port_client.hpp>
#include <bsk_payloads/THRArrayOnTimeCmdMsgPayload.h>
#include <bsk_payloads/THRArrayCmdForceMsgPayload.h>
#include <generic_thruster_command_provider.hpp>
#include <sim_i_data_provider.hpp>
#include <boost/shared_ptr.hpp>
static_assert(sizeof(THRArrayCmdForceMsgPayload) == 288, "Native Basilisk payload ABI changed");

namespace Nos3 {
class Generic_thrusterBskDataProvider : public SimIDataProvider, public GenericThrusterCommandProvider {
public:
    Generic_thrusterBskDataProvider(const boost::property_tree::ptree& config);
    boost::shared_ptr<SimIDataPoint> get_data_point(void) const;
    bool cmd_thrust(int thruster, double percent);
private:
    BskPortClient _client;
};
}
#endif
