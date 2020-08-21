#!/usr/bin/env python
import rospy
import time
from lino_msgs.msg import IRswitch
from geometry_msgs.msg import Twist

class safetyController(object):
    def __init__(self):
        rospy.init_node("safety_controller")
        self.escape_velocity = rospy.get_param("~escape_vel") #m/s
        self.escape_time = rospy.get_param("~escape_time") #seconds
        self.safetycontroller_subscriber = rospy.Subscriber("ir_switch", IRswitch, self.safety_command_callback, queue_size=1)
        self.safetycontroller_publisher = rospy.Publisher("safety_controller/cmd_vel",Twist,queue_size=1)
        rate = rospy.Rate(50)
        while not rospy.is_shutdown():
            rate.sleep()

    def safety_command_callback(self, data):
        cmd_msg = Twist()
        cmd_msg.linear.x = 0
        cmd_msg.linear.y = 0
        velocity = float(self.escape_velocity)
        time = float(self.escape_time)
        if(not data.S2 or not data.S3):
              cmd_msg.linear.x = -velocity
        if(not data.S0 or not data.S1):
              cmd_msg.linear.y = -velocity
        if(not data.S4 or not data.S5):
              cmd_msg.linear.y += velocity
              if(cmd_msg.linear.y == 0 and cmd_msg.linear.x == 0):
                  cmd_msg.linear.x = velocity

        if(data.S0 + data.S1 + data.S2 + data.S3 + data.S4 + data.S5 < 6):
           time_now = rospy.Time.now().to_sec()
           while(rospy.Time.now().to_sec() - time_now <= time):
               self.safetycontroller_publisher.publish(cmd_msg)

if __name__ == '__main__':
    try:
       safetyController()
    except:
        rospy.logerr("Unhandled Exception in the Joy2RCin"+
                     " Node:+\n"+traceback.format_exc())
