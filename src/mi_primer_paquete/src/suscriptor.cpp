#include "ros/ros.h"
#include "turtlesim/Pose.h"
#include "geometry_msgs/Twist.h"
#include <locale.h>

turtlesim::Pose pose_turtle;
void poseCallback(const turtlesim::Pose::ConstPtr& msg){
    pose_turtle.x = msg->x;
    pose_turtle.y = msg->y;
    ROS_INFO("Se recibió una pose_turtle en x = [%.3f] y = [%.3f]", pose_turtle.x, pose_turtle.y);
}

int main(int argc, char **argv){
    setlocale(LC_ALL, "es_ES.UTF-8");
    ros::init(argc, argv, "nodo_suscriptor");
    ROS_INFO("Se inicializa nodo_suscriptor");
    ros::NodeHandle n;
    ros::Subscriber pose_sub = n.subscribe("/turtle1/pose",10, poseCallback);
    ros::spin();
    return 0;
}