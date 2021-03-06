#ifndef POSE_FACTORY_H
#define POSE_FACTORY_H

#include "visualization_msgs/Marker.h"
#include "geometry_msgs/Pose.h"
#include "amcl6d_tools/Mesh.h"

#include "amcl6d_tools/Logger.h"

#include <Eigen/Dense>
#include <Eigen/Cholesky>

namespace Eigen 
{
    typedef Eigen::Matrix<double, 6, 1> Vector6d;
    typedef Eigen::Matrix<double, 6, 6> Matrix6d;
}

class pose_factory {

public:
    pose_factory();
    ~pose_factory();

    void set_bounds(amcl6d_tools::Mesh mesh);
    
    geometry_msgs::Pose generate_random_pose();
    geometry_msgs::Pose generate_pose_near(geometry_msgs::Pose pose);

    double get_maximum_distance();

private:
    double m_min_x;
    double m_max_x;
    double m_min_y;
    double m_max_y; 
    double m_min_z;
    double m_max_z;

    std::default_random_engine m_generator;
    std::normal_distribution<double> m_distribution;

    Eigen::Matrix6d m_cholesky_decomp;
};
#endif
