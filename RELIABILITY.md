# Acknowledged backend delivery

The UART success echo now requires a command provider to return a positive backend
acknowledgement. A null provider, an unsupported backend operation, a malformed
acknowledgement, an unavailable backend, or an out-of-range percentage produces
no success echo; the existing flight driver detects a timeout. Legacy 42 delivery
has no end-to-end acknowledgement and is deliberately rejected by this path.

The new GENERIC_THRUSTER_BSK_PROVIDER uses the bounded BskBackendClient from
the companion NOS3X reliability PR. It requires that updated sim_common header.
It does not implement a new propulsion model. Current NOS3X main's bridge rejects
set_thruster_percent as unsupported, so this update prevents false success and
does not claim physical thrust acceptance.

Validated in the server NOS3X integration checkout by building the real simulator
plugin with the team's NOS SDK image. The parent PR provides the command-provider
fault regression and documents the outstanding physical integration.
