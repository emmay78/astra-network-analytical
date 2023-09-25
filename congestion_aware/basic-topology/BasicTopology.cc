/******************************************************************************
This source code is licensed under the MIT license found in the
LICENSE file in the root directory of this source tree.
*******************************************************************************/

#include "congestion_aware/basic-topology/BasicTopology.hh"

using namespace NetworkAnalytical;
using namespace NetworkAnalyticalCongestionAware;

BasicTopology::BasicTopology(
    const int npus_count,
    const int devices_count,
    const Bandwidth bandwidth,
    const Latency latency) noexcept
    : bandwidth(bandwidth),
      latency(latency),
      basic_topology_type(TopologyBuildingBlock::Undefined),
      Topology() {
  assert(npus_count > 0);
  assert(devices_count > 0);
  assert(devices_count >= npus_count);
  assert(bandwidth > 0);
  assert(latency >= 0);

  // setup npus and devices count
  this->npus_count = npus_count;
  this->devices_count = devices_count;

  // instantiate devices
  instantiate_devices();
}

BasicTopology::~BasicTopology() noexcept = default;

TopologyBuildingBlock BasicTopology::get_basic_topology_type() const noexcept {
  assert(basic_topology_type != TopologyBuildingBlock::Undefined);

  return basic_topology_type;
}
