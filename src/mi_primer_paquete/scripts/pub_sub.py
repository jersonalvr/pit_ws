#!/usr/bin/env python3
import rospy
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose

def poseCallback(data):
    rospy.loginfo("La posición es - x: %.2f, y: %.2f, theta: %.2f, linear_velocity: %.2f, angular_velocity: %.2f", 
                  data.x, data.y, data.theta, data.linear_velocity, data.angular_velocity)

def pub_sub():
    rospy.init_node('pub_sub', anonymous=True)
    pub = rospy.Publisher('turtle1/cmd_vel', Twist, queue_size=10)
    sub = rospy.Subscriber('turtle1/pose', Pose, poseCallback)
    rate = rospy.Rate(10)
    cmd_vel_msg = Twist()
    cmd_vel_msg.linear.x = 0.5
    cmd_vel_msg.angular.z = 0.5
    while not rospy.is_shutdown():
        pub.publish(cmd_vel_msg)
        rospy.loginfo('Publicando cmd_vel_msg ...')
        rate.sleep()    

if __name__ == '__main__':
    try:
        pub_sub()
    except rospy.ROSInterruptException:
        pass