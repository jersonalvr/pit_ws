#!/usr/bin/env python3
import rospy
from turtlesim.msg import Pose

def poseCallback(data):
    rospy.loginfo("La posición es - x: %.2f, y: %.2f, theta: %.2f, linear_velocity: %.2f, angular_velocity: %.2f", 
                  data.x, data.y, data.theta, data.linear_velocity, data.angular_velocity)

def suscriptor():
    rospy.init_node('suscriptor', anonymous=True)
    sub = rospy.Subscriber('turtle1/pose', Pose, poseCallback)
    rospy.spin()

if __name__ == '__main__':
    try:
        suscriptor()
    except rospy.ROSInterruptException:
        pass