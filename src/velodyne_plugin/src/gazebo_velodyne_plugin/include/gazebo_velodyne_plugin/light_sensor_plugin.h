#ifndef _VELODYNE_PLUGIN_HH_
#define _VELODYNE_PLUGIN_HH_
  
  #include <string>
  
  // library for processing camera data for gazebo / ros conversions
#include <thread>
#include "ros/ros.h"
#include "ros/callback_queue.h"
#include "ros/subscribe_options.h"
#include "std_msgs/Float32.h"
#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/transport/transport.hh>
#include <gazebo/msgs/msgs.hh>
    
    namespace gazebo
    {
      class GazeboRosLight : public CameraPlugin, GazeboRosCameraUtils
      {
        /// \brief Constructor
        /// \param parent The parent entity, must be a Model or a Sensor
        public: GazeboRosLight();
    
        /// \brief Destructor
        public: ~GazeboRosLight();
    
        /// \brief Load the plugin
        /// \param take in SDF root element
        public: void Load(sensors::SensorPtr _parent, sdf::ElementPtr _sdf);
    
        /// \brief Update the controller
        protected: virtual void OnNewFrame(const unsigned char *_image,
        unsigned int _width, unsigned int _height,
        unsigned int _depth, const std::string &_format);
    
        ros::NodeHandle _nh;
        ros::Publisher _sensorPublisher;
    
        double _fov;
        double _range;
      };
    }
    #endif