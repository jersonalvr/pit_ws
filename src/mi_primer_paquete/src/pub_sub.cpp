#include "ros/ros.h"
#include "turtlesim/Pose.h"
#include "geometry_msgs/Twist.h"
#include <iostream>
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

    // Declarar Publisher y Subscriber
    ros::Subscriber pose_sub = n.subscribe("/turtle1/pose",10, poseCallback);
    // Considera aumentar el buffer del publisher si necesitas más robustez
    ros::Publisher cmd_vel_pub = n.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1);
    // El loop_rate podría aumentarse a 50 Hz por ejemplo si necesitas mayor frecuencia de control
    ros::Rate loop_rate(10);

    geometry_msgs::Twist cmd_vel_msg;
    cmd_vel_msg.linear.x = 0.5;
    cmd_vel_msg.angular.z = 0.5;
    
    while (ros::ok())
    {
        ROS_INFO("Publicando velocidad turtle1...");
        cmd_vel_pub.publish(cmd_vel_msg);
        ros::spinOnce();
        loop_rate.sleep();
    }    
    
    //ros::spin();
    return 0;
}