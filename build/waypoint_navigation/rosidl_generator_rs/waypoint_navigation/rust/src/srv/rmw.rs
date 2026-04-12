#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "waypoint_navigation__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__waypoint_navigation__srv__GetWayPoints_Request() -> *const std::ffi::c_void;
}

#[link(name = "waypoint_navigation__rosidl_generator_c")]
extern "C" {
    fn waypoint_navigation__srv__GetWayPoints_Request__init(msg: *mut GetWayPoints_Request) -> bool;
    fn waypoint_navigation__srv__GetWayPoints_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetWayPoints_Request>, size: usize) -> bool;
    fn waypoint_navigation__srv__GetWayPoints_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetWayPoints_Request>);
    fn waypoint_navigation__srv__GetWayPoints_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetWayPoints_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<GetWayPoints_Request>) -> bool;
}

// Corresponds to waypoint_navigation__srv__GetWayPoints_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetWayPoints_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub get_waypoints: bool,

}



impl Default for GetWayPoints_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !waypoint_navigation__srv__GetWayPoints_Request__init(&mut msg as *mut _) {
        panic!("Call to waypoint_navigation__srv__GetWayPoints_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetWayPoints_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { waypoint_navigation__srv__GetWayPoints_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { waypoint_navigation__srv__GetWayPoints_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { waypoint_navigation__srv__GetWayPoints_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetWayPoints_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetWayPoints_Request where Self: Sized {
  const TYPE_NAME: &'static str = "waypoint_navigation/srv/GetWayPoints_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__waypoint_navigation__srv__GetWayPoints_Request() }
  }
}


#[link(name = "waypoint_navigation__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__waypoint_navigation__srv__GetWayPoints_Response() -> *const std::ffi::c_void;
}

#[link(name = "waypoint_navigation__rosidl_generator_c")]
extern "C" {
    fn waypoint_navigation__srv__GetWayPoints_Response__init(msg: *mut GetWayPoints_Response) -> bool;
    fn waypoint_navigation__srv__GetWayPoints_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetWayPoints_Response>, size: usize) -> bool;
    fn waypoint_navigation__srv__GetWayPoints_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetWayPoints_Response>);
    fn waypoint_navigation__srv__GetWayPoints_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetWayPoints_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<GetWayPoints_Response>) -> bool;
}

// Corresponds to waypoint_navigation__srv__GetWayPoints_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetWayPoints_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub waypoints: geometry_msgs::msg::rmw::PoseArray,

}



impl Default for GetWayPoints_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !waypoint_navigation__srv__GetWayPoints_Response__init(&mut msg as *mut _) {
        panic!("Call to waypoint_navigation__srv__GetWayPoints_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetWayPoints_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { waypoint_navigation__srv__GetWayPoints_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { waypoint_navigation__srv__GetWayPoints_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { waypoint_navigation__srv__GetWayPoints_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetWayPoints_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetWayPoints_Response where Self: Sized {
  const TYPE_NAME: &'static str = "waypoint_navigation/srv/GetWayPoints_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__waypoint_navigation__srv__GetWayPoints_Response() }
  }
}






#[link(name = "waypoint_navigation__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__waypoint_navigation__srv__GetWayPoints() -> *const std::ffi::c_void;
}

// Corresponds to waypoint_navigation__srv__GetWayPoints
#[allow(missing_docs, non_camel_case_types)]
pub struct GetWayPoints;

impl rosidl_runtime_rs::Service for GetWayPoints {
    type Request = GetWayPoints_Request;
    type Response = GetWayPoints_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__waypoint_navigation__srv__GetWayPoints() }
    }
}


