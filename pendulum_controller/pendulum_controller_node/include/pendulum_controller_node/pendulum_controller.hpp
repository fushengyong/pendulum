// Copyright 2019 Carlos San Vicente
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/// \file
/// \brief This file provides the inverted pendulum controller implementation interface.

#ifndef PENDULUM_CONTROLLER_NODE__PENDULUM_CONTROLLER_HPP_
#define PENDULUM_CONTROLLER_NODE__PENDULUM_CONTROLLER_HPP_

#include "sensor_msgs/msg/joint_state.hpp"
#include "pendulum_msgs_v2/msg/pendulum_command.hpp"
#include "pendulum_msgs_v2/msg/pendulum_state.hpp"

namespace pendulum
{
/// \class This class creates the interface between the controller node and the controller
///        implementation.
class PendulumController
{
public:
  /// \brief Updates the setpoint data when a setpoint message arrives.
  /// \param[in] msg Setpoint data message.
  virtual void update_setpoint_data(const pendulum_msgs_v2::msg::PendulumCommand & msg) = 0;

  /// \brief Updates the sensor data when a status message arrives.
  /// \param[in] msg Setpoint data message.
  virtual void update_status_data(const sensor_msgs::msg::JointState & msg) = 0;

  /// \brief Updates the command data from the controller before publishing.
  /// \param[in,out] msg Command data message.
  virtual void update_command_data(pendulum_msgs_v2::msg::PendulumCommand & msg) = 0;

  /// \brief Resets the controller internal status and set variables to tehir default values.
  virtual void reset() = 0;
};
}  // namespace pendulum

#endif  // PENDULUM_CONTROLLER_NODE__PENDULUM_CONTROLLER_HPP_
