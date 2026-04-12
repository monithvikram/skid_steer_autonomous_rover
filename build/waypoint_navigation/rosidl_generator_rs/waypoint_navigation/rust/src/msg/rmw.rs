#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "waypoint_navigation__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__waypoint_navigation__msg__Pwm() -> *const std::ffi::c_void;
}

#[link(name = "waypoint_navigation__rosidl_generator_c")]
extern "C" {
    fn waypoint_navigation__msg__Pwm__init(msg: *mut Pwm) -> bool;
    fn waypoint_navigation__msg__Pwm__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Pwm>, size: usize) -> bool;
    fn waypoint_navigation__msg__Pwm__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Pwm>);
    fn waypoint_navigation__msg__Pwm__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Pwm>, out_seq: *mut rosidl_runtime_rs::Sequence<Pwm>) -> bool;
}

// Corresponds to waypoint_navigation__msg__Pwm
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Pwm {

    // This member is not documented.
    #[allow(missing_docs)]
    pub pwm_l: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub pwm_r: i32,

}



impl Default for Pwm {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !waypoint_navigation__msg__Pwm__init(&mut msg as *mut _) {
        panic!("Call to waypoint_navigation__msg__Pwm__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Pwm {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { waypoint_navigation__msg__Pwm__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { waypoint_navigation__msg__Pwm__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { waypoint_navigation__msg__Pwm__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Pwm {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Pwm where Self: Sized {
  const TYPE_NAME: &'static str = "waypoint_navigation/msg/Pwm";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__waypoint_navigation__msg__Pwm() }
  }
}


#[link(name = "waypoint_navigation__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__waypoint_navigation__msg__EstimatedTwist() -> *const std::ffi::c_void;
}

#[link(name = "waypoint_navigation__rosidl_generator_c")]
extern "C" {
    fn waypoint_navigation__msg__EstimatedTwist__init(msg: *mut EstimatedTwist) -> bool;
    fn waypoint_navigation__msg__EstimatedTwist__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<EstimatedTwist>, size: usize) -> bool;
    fn waypoint_navigation__msg__EstimatedTwist__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<EstimatedTwist>);
    fn waypoint_navigation__msg__EstimatedTwist__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<EstimatedTwist>, out_seq: *mut rosidl_runtime_rs::Sequence<EstimatedTwist>) -> bool;
}

// Corresponds to waypoint_navigation__msg__EstimatedTwist
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct EstimatedTwist {

    // This member is not documented.
    #[allow(missing_docs)]
    pub est_twist: geometry_msgs::msg::rmw::TwistStamped,

}



impl Default for EstimatedTwist {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !waypoint_navigation__msg__EstimatedTwist__init(&mut msg as *mut _) {
        panic!("Call to waypoint_navigation__msg__EstimatedTwist__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for EstimatedTwist {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { waypoint_navigation__msg__EstimatedTwist__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { waypoint_navigation__msg__EstimatedTwist__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { waypoint_navigation__msg__EstimatedTwist__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for EstimatedTwist {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for EstimatedTwist where Self: Sized {
  const TYPE_NAME: &'static str = "waypoint_navigation/msg/EstimatedTwist";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__waypoint_navigation__msg__EstimatedTwist() }
  }
}


#[link(name = "waypoint_navigation__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__waypoint_navigation__msg__EstimatedOdom() -> *const std::ffi::c_void;
}

#[link(name = "waypoint_navigation__rosidl_generator_c")]
extern "C" {
    fn waypoint_navigation__msg__EstimatedOdom__init(msg: *mut EstimatedOdom) -> bool;
    fn waypoint_navigation__msg__EstimatedOdom__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<EstimatedOdom>, size: usize) -> bool;
    fn waypoint_navigation__msg__EstimatedOdom__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<EstimatedOdom>);
    fn waypoint_navigation__msg__EstimatedOdom__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<EstimatedOdom>, out_seq: *mut rosidl_runtime_rs::Sequence<EstimatedOdom>) -> bool;
}

// Corresponds to waypoint_navigation__msg__EstimatedOdom
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct EstimatedOdom {

    // This member is not documented.
    #[allow(missing_docs)]
    pub est_odom: nav_msgs::msg::rmw::Odometry,

}



impl Default for EstimatedOdom {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !waypoint_navigation__msg__EstimatedOdom__init(&mut msg as *mut _) {
        panic!("Call to waypoint_navigation__msg__EstimatedOdom__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for EstimatedOdom {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { waypoint_navigation__msg__EstimatedOdom__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { waypoint_navigation__msg__EstimatedOdom__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { waypoint_navigation__msg__EstimatedOdom__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for EstimatedOdom {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for EstimatedOdom where Self: Sized {
  const TYPE_NAME: &'static str = "waypoint_navigation/msg/EstimatedOdom";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__waypoint_navigation__msg__EstimatedOdom() }
  }
}


