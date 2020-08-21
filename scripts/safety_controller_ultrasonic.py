#!/usr/bin/env python
import rospy
import time
from lino_msgs.msg import Ultrasonic
from geometry_msgs.msg import Twist

class safetyController(object):
    def __init__(self):
        rospy.init_node("safety_controller")
        self.escape_velocity = rospy.get_param("~escape_vel") #m/s
        self.threshold_val = rospy.get_param("~threshold_val") #cm
        self.danger_val = rospy.get_param("~danger_val") #cm
        self.danger_flag = False
        self.safetycontroller_subscriber = rospy.Subscriber("ultrasonics", Ultrasonic, self.safety_command_callback, queue_size=1)
        self.safetycontroller_publisher = rospy.Publisher("safety_controller/cmd_vel",Twist,queue_size=1)
        while not rospy.is_shutdown():
          rospy.spin()


    def safety_command_callback(self, data):
        cmd_msg = Twist()

        left_ping = data.left
        center_ping = data.center
        right_ping = data.right

        if(data.left == 0):
            left_ping = 100
        if(data.center == 0):
            center_ping = 100
        if(data.right == 0):
            right_ping = 100
        #print left_ping, center_ping, right_ping

        if((left_ping < self.danger_val) or (center_ping < self.danger_val) or (right_ping < self.danger_val)):
            cmd_msg.linear.x = -self.escape_velocity
            self.danger_flag = True

        if(self.danger_flag and ((left_ping < self.threshold_val) or (center_ping < self.threshold_val) or (right_ping < self.threshold_val))):
            cmd_msg.linear.x = -self.escape_velocity
            self.danger_flag = True

        if((left_ping > self.threshold_val) and (center_ping > self.threshold_val) and (right_ping > self.threshold_val)):
            self.danger_flag = False
            
        if(self.danger_flag):
            self.safetycontroller_publisher.publish(cmd_msg)
       

if __name__ == '__main__':
    try:
       safetyController()
 
    except:
        rospy.logerr("Unhandled Exception in the Joy2RCin"+
                     " Node:+\n"+traceback.format_exc())
