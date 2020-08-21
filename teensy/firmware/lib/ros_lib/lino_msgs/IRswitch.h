#ifndef _ROS_lino_msgs_IRswitch_h
#define _ROS_lino_msgs_IRswitch_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace lino_msgs
{

  class IRswitch : public ros::Msg
  {
    public:
      typedef int8_t _S0_type;
      _S0_type S0;
      typedef int8_t _S1_type;
      _S1_type S1;
      typedef int8_t _S2_type;
      _S2_type S2;
      typedef int8_t _S3_type;
      _S3_type S3;
      typedef int8_t _S4_type;
      _S4_type S4;
      typedef int8_t _S5_type;
      _S5_type S5;

    IRswitch():
      S0(0),
      S1(0),
      S2(0),
      S3(0),
      S4(0),
      S5(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_S0;
      u_S0.real = this->S0;
      *(outbuffer + offset + 0) = (u_S0.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->S0);
      union {
        int8_t real;
        uint8_t base;
      } u_S1;
      u_S1.real = this->S1;
      *(outbuffer + offset + 0) = (u_S1.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->S1);
      union {
        int8_t real;
        uint8_t base;
      } u_S2;
      u_S2.real = this->S2;
      *(outbuffer + offset + 0) = (u_S2.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->S2);
      union {
        int8_t real;
        uint8_t base;
      } u_S3;
      u_S3.real = this->S3;
      *(outbuffer + offset + 0) = (u_S3.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->S3);
      union {
        int8_t real;
        uint8_t base;
      } u_S4;
      u_S4.real = this->S4;
      *(outbuffer + offset + 0) = (u_S4.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->S4);
      union {
        int8_t real;
        uint8_t base;
      } u_S5;
      u_S5.real = this->S5;
      *(outbuffer + offset + 0) = (u_S5.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->S5);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_S0;
      u_S0.base = 0;
      u_S0.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->S0 = u_S0.real;
      offset += sizeof(this->S0);
      union {
        int8_t real;
        uint8_t base;
      } u_S1;
      u_S1.base = 0;
      u_S1.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->S1 = u_S1.real;
      offset += sizeof(this->S1);
      union {
        int8_t real;
        uint8_t base;
      } u_S2;
      u_S2.base = 0;
      u_S2.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->S2 = u_S2.real;
      offset += sizeof(this->S2);
      union {
        int8_t real;
        uint8_t base;
      } u_S3;
      u_S3.base = 0;
      u_S3.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->S3 = u_S3.real;
      offset += sizeof(this->S3);
      union {
        int8_t real;
        uint8_t base;
      } u_S4;
      u_S4.base = 0;
      u_S4.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->S4 = u_S4.real;
      offset += sizeof(this->S4);
      union {
        int8_t real;
        uint8_t base;
      } u_S5;
      u_S5.base = 0;
      u_S5.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->S5 = u_S5.real;
      offset += sizeof(this->S5);
     return offset;
    }

    const char * getType(){ return "lino_msgs/IRswitch"; };
    const char * getMD5(){ return "5f84b7f801cb7232d2dbd9d0299613cb"; };

  };

}
#endif