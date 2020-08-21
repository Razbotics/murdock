#! /usr/bin/env python

import rospy
import traceback
from sensor_msgs.msg import LaserScan


class scanReverse(object):
    def __init__(self):
        rospy.init_node("reverse_scan")
        self.laser_sub = rospy.Subscriber('/scan', LaserScan, self.scan_callback)
        self.laser_pub = rospy.Publisher('/reversed/scan', LaserScan, queue_size=1)

        while not rospy.is_shutdown():
            rospy.spin()

    def scan_callback(self, received_laser_msg):
        laser_msg = LaserScan()
        laser_msg.header = received_laser_msg.header
        laser_msg.angle_min = 0
        laser_msg.angle_max = 2 * 3.14159274101
        laser_msg.angle_increment = received_laser_msg.angle_increment
        laser_msg.time_increment = received_laser_msg.time_increment
        laser_msg.scan_time = received_laser_msg.scan_time
        laser_msg.range_min = received_laser_msg.range_min
        laser_msg.range_max = received_laser_msg.range_max
        laser_msg.ranges = received_laser_msg.ranges
        laser_msg.intensities = received_laser_msg.intensities

        self.laser_pub.publish(laser_msg)


if __name__ == '__main__':
    try:
       scanReverse()
    except:
        rospy.logerr("Unhandled Exception in the reverse_scan"+
                     " Node:+\n"+traceback.format_exc())
