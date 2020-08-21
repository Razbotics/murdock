#!/usr/bin/env python

import rospy
import traceback
from lino_msgs.msg import Ultrasonic
from sensor_msgs.msg import LaserScan

class PingToScan(object):

    def __init__(self):
        rospy.init_node("PingToScan")
        self.ultrasonic_angle_deg = 38.0
        self.ultrasonic_angle_rad = self.ultrasonic_angle_deg * (3.14159274101/180)
        self.robot_radius = 0.15
        self.PingToScan_subscriber = rospy.Subscriber("ultrasonics", Ultrasonic, self.PingToScan_callback, queue_size=1)
        self.PingToScan_publisher = rospy.Publisher("ultrasonic_scan", LaserScan, queue_size=1)

        while not rospy.is_shutdown():
            rospy.spin()

    def PingToScan_callback(self, ultrasonic_data):
        scan_msg = LaserScan()
        scan_msg.header.frame_id = "ultrasonic_link"
        scan_msg.header.stamp = rospy.Time.now()
        scan_msg.angle_min = -self.ultrasonic_angle_rad
        scan_msg.angle_max = self.ultrasonic_angle_rad
        scan_msg.angle_increment = self.ultrasonic_angle_rad
        scan_msg.range_min = 0.04 + self.robot_radius
        scan_msg.range_max = 0.3 + self.robot_radius

        left_ping = ultrasonic_data.left * 0.01 + self.robot_radius
        center_ping = ultrasonic_data.center * 0.01 + self.robot_radius
        right_ping = ultrasonic_data.right * 0.01 + self.robot_radius

        if(left_ping < scan_msg.range_min or left_ping > scan_msg.range_max):
            left_ping = float('Inf')
        if(center_ping < scan_msg.range_min or center_ping > scan_msg.range_max):
            center_ping = float('Inf')
        if(right_ping < scan_msg.range_min or right_ping > scan_msg.range_max):
            right_ping = float('Inf')

        scan_msg.ranges = [right_ping, center_ping, left_ping]
        self.PingToScan_publisher.publish(scan_msg)


if __name__ == '__main__':
    try:
       PingToScan()
    except:
        rospy.logerr("Unhandled Exception in the reverse_scan"+
                     " Node:+\n"+traceback.format_exc())
