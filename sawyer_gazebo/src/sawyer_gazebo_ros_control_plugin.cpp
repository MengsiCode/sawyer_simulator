/***************************************************************************
* Copyright (c) 2013-2017, Rethink Robotics Inc.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
**************************************************************************/

// Overload the default plugin
#include <sawyer_gazebo/sawyer_gazebo_ros_control_plugin.h>

namespace sawyer_gazebo {

void SawyerGazeboRosControlPlugin::Load(gazebo::physics::ModelPtr parent, sdf::ElementPtr sdf) {
  GazeboRosControlPlugin::Load(parent, sdf);
  assembly_interface_.init(model_nh_);
  arm_controller_interface_.init(model_nh_, "right", controller_manager_);
  arm_kinematics_interface_.init(model_nh_, "right");
  head_interface_.init(model_nh_, controller_manager_);
}

// register the plugin with gazebo
GZ_REGISTER_MODEL_PLUGIN(SawyerGazeboRosControlPlugin);
}
