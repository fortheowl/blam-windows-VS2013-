#ifndef BLAM_SLAM_H
#define BLAM_SLAM_H

//#include <measurement_synchronizer/MeasurementSynchronizer.h>
#include <point_cloud_filter/PointCloudFilter.h>
#include <point_cloud_odometry/PointCloudOdometry.h>
#include <laser_loop_closure/LaserLoopClosure.h>
#include <point_cloud_localization/PointCloudLocalization.h>
#include <point_cloud_mapper/PointCloudMapper.h>
//#include <pcl_ros/point_cloud.h>
//// PCL
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/common/transforms.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/visualization/cloud_viewer.h>
#include<string>
#include <fstream>
#include"common.h"


class BlamSlam {
 public:
	 typedef pcl::PointCloud<pcl::POINT_TYPE> PointCloud;

  BlamSlam();
  ~BlamSlam();

  bool Initialize();
  bool HandleLoopClosures(const PointCloud::ConstPtr& scan, bool* new_keyframe);
  void ProcessPointCloudMessage(const PointCloud::ConstPtr& msg);
  bool showPointCloud(int FrameCounter);
  std::string itos(int i);   // ��int ת����string 

private:

  // The node's name.
  std::string name_;
  // Update rates and callback timers.
  double estimate_update_rate_;
  double visualization_update_rate_;

  // Names of coordinate frames.
  std::string fixed_frame_id_;
  std::string base_frame_id_;
public:
  PointCloudFilter filter_;
  PointCloudOdometry odometry_;
  LaserLoopClosure loop_closure_;
  PointCloudLocalization localization_;
  PointCloudMapper mapper_;
  std::ofstream m_Log;
  std::string m_szLogPath;
  std::ofstream m_fInterMediaFilePath;
};

#endif
