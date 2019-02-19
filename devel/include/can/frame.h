// Generated by gencpp from file can/frame.msg
// DO NOT EDIT!


#ifndef CAN_MESSAGE_FRAME_H
#define CAN_MESSAGE_FRAME_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace can
{
template <class ContainerAllocator>
struct frame_
{
  typedef frame_<ContainerAllocator> Type;

  frame_()
    : id(0)
    , data()  {
      data.assign(0);
  }
  frame_(const ContainerAllocator& _alloc)
    : id(0)
    , data()  {
  (void)_alloc;
      data.assign(0);
  }



   typedef uint32_t _id_type;
  _id_type id;

   typedef boost::array<uint8_t, 8>  _data_type;
  _data_type data;





  typedef boost::shared_ptr< ::can::frame_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::can::frame_<ContainerAllocator> const> ConstPtr;

}; // struct frame_

typedef ::can::frame_<std::allocator<void> > frame;

typedef boost::shared_ptr< ::can::frame > framePtr;
typedef boost::shared_ptr< ::can::frame const> frameConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::can::frame_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::can::frame_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace can

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'can': ['/home/zj/ros_space2/src/can/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::can::frame_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::can::frame_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::can::frame_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::can::frame_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::can::frame_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::can::frame_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::can::frame_<ContainerAllocator> >
{
  static const char* value()
  {
    return "2f636bf314749eeb00e7f85696286658";
  }

  static const char* value(const ::can::frame_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x2f636bf314749eebULL;
  static const uint64_t static_value2 = 0x00e7f85696286658ULL;
};

template<class ContainerAllocator>
struct DataType< ::can::frame_<ContainerAllocator> >
{
  static const char* value()
  {
    return "can/frame";
  }

  static const char* value(const ::can::frame_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::can::frame_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uint32 id\n\
uint8[8] data\n\
";
  }

  static const char* value(const ::can::frame_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::can::frame_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.id);
      stream.next(m.data);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct frame_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::can::frame_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::can::frame_<ContainerAllocator>& v)
  {
    s << indent << "id: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.id);
    s << indent << "data[]" << std::endl;
    for (size_t i = 0; i < v.data.size(); ++i)
    {
      s << indent << "  data[" << i << "]: ";
      Printer<uint8_t>::stream(s, indent + "  ", v.data[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // CAN_MESSAGE_FRAME_H
