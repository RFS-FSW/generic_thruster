#ifndef NOS3_GENERIC_THRUSTER_COMMAND_PROVIDER_HPP
#define NOS3_GENERIC_THRUSTER_COMMAND_PROVIDER_HPP
namespace Nos3 {
class GenericThrusterCommandProvider {
public:
    virtual ~GenericThrusterCommandProvider() {}
    virtual bool cmd_thrust(int thruster, double percent) = 0;
};
}
#endif
