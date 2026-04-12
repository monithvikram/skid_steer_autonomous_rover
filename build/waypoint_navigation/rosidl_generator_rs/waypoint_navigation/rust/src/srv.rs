#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to waypoint_navigation__srv__GetWayPoints_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetWayPoints_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub get_waypoints: bool,

}



impl Default for GetWayPoints_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetWayPoints_Request::default())
  }
}

impl rosidl_runtime_rs::Message for GetWayPoints_Request {
  type RmwMsg = super::srv::rmw::GetWayPoints_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        get_waypoints: msg.get_waypoints,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      get_waypoints: msg.get_waypoints,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      get_waypoints: msg.get_waypoints,
    }
  }
}


// Corresponds to waypoint_navigation__srv__GetWayPoints_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetWayPoints_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub waypoints: geometry_msgs::msg::PoseArray,

}



impl Default for GetWayPoints_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetWayPoints_Response::default())
  }
}

impl rosidl_runtime_rs::Message for GetWayPoints_Response {
  type RmwMsg = super::srv::rmw::GetWayPoints_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        waypoints: geometry_msgs::msg::PoseArray::into_rmw_message(std::borrow::Cow::Owned(msg.waypoints)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        waypoints: geometry_msgs::msg::PoseArray::into_rmw_message(std::borrow::Cow::Borrowed(&msg.waypoints)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      waypoints: geometry_msgs::msg::PoseArray::from_rmw_message(msg.waypoints),
    }
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


