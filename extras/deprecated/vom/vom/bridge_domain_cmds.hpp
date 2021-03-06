/*
 * Copyright (c) 2017 Cisco and/or its affiliates.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __VOM_BRIDGE_DOMAIN_CMDS_H__
#define __VOM_BRIDGE_DOMAIN_CMDS_H__

#include "vom/bridge_domain.hpp"
#include "vom/dump_cmd.hpp"
#include "vom/rpc_cmd.hpp"

#include <vapi/l2.api.vapi.hpp>

namespace VOM {
namespace bridge_domain_cmds {
/**
 * A command class that creates an Bridge-Domain
 */
class create_cmd
  : public rpc_cmd<HW::item<uint32_t>, vapi::Bridge_domain_add_del>
{
public:
  /**
   * Constructor
   */
  create_cmd(HW::item<uint32_t>& item,
             const bridge_domain::learning_mode_t& lmode,
             const bridge_domain::arp_term_mode_t& amode,
             const bridge_domain::arp_ufwd_mode_t& aumode,
             const bridge_domain::flood_mode_t& fmode,
             const bridge_domain::uu_flood_mode_t& uufmode,
             const bridge_domain::mac_age_mode_t& mmode);

  /**
   * Issue the command to VPP/HW
   */
  rc_t issue(connection& con);
  /**
   * convert to string format for debug purposes
   */
  std::string to_string() const;

  /**
   * Comparison operator - only used for UT
   */
  bool operator==(const create_cmd& i) const;

private:
  /**
   * the learning mode for the bridge
   */
  bridge_domain::learning_mode_t m_learning_mode;
  /**
   * the learning mode for the bridge
   */
  bridge_domain::arp_term_mode_t m_arp_term_mode;
  /**
   * the learning mode for the bridge
   */
  bridge_domain::arp_ufwd_mode_t m_arp_ufwd_mode;
  /**
   * the flood mode for the bridge
   */
  bridge_domain::flood_mode_t m_flood_mode;
  /**
   * the unknown unicast flood mode for the bridge
   */
  bridge_domain::uu_flood_mode_t m_uu_flood_mode;
  /**
   * the flood mode for the bridge
   */
  bridge_domain::mac_age_mode_t m_mac_age_mode;
};

/**
 * A cmd class that Delete an Bridge-Domain
 */
class delete_cmd
  : public rpc_cmd<HW::item<uint32_t>, vapi::Bridge_domain_add_del>
{
public:
  /**
   * Constructor
   */
  delete_cmd(HW::item<uint32_t>& item);

  /**
   * Issue the command to VPP/HW
   */
  rc_t issue(connection& con);
  /**
   * convert to string format for debug purposes
   */
  std::string to_string() const;

  /**
   * Comparison operator - only used for UT
   */
  bool operator==(const delete_cmd& i) const;
};

/**
 * A cmd class that Dumps all the bridge domains
 */
class dump_cmd : public VOM::dump_cmd<vapi::Bridge_domain_dump>
{
public:
  /**
   * Constructor
   */
  dump_cmd();
  dump_cmd(const dump_cmd& d);

  /**
   * Issue the command to VPP/HW
   */
  rc_t issue(connection& con);
  /**
   * convert to string format for debug purposes
   */
  std::string to_string() const;

  /**
   * Comparison operator - only used for UT
   */
  bool operator==(const dump_cmd& i) const;

private:
  /**
   * HW reutrn code
   */
  HW::item<bool> item;
};
};
};

/*
 * fd.io coding-style-patch-verification: OFF
 *
 * Local Variables:
 * eval: (c-set-style "mozilla")
 * End:
 */

#endif
