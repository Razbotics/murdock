#ifndef _ROS_lino_msgs_Ultrasonic_h
#define _ROS_lino_msgs_Ultrasonic_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace lino_msgs
{

  class Ultrasonic : public ros::Msg
  {
    public:
      typedef uint8_t _left_type;
      _left_type left;
      typedef uint8_t _center_type;
      _center_type center;
      typedef uint8_t _right_type;
      _right_type right;

    Ultrasonic():
      left(0),
      center(0),
      right(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->left >> (8 * 0)) & 0xFF;
      offset += sizeof(this->left);
      *(outbuffer + offset + 0) = (this->center >> (8 * 0)) & 0xFF;
      offset += sizeof(this->center);
      *(outbuffer + offset + 0) = (this->right >> (8 * 0)) & 0xFF;
      offset += sizeof(this->right);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->left =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->left);
      this->center =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->center);
      this->right =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->right);
     return offset;
    }

    const char * getType(){ return "lino_msgs/Ultrasonic"; };
    const char * getMD5(){ return "454bba72f92ee64d596bda61c76fbee8"; };

  };

}
#endif