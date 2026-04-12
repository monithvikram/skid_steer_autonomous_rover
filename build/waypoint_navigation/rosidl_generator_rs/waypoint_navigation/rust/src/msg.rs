#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to waypoint_navigation__msg__Pwm

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Pwm::default())
  }
}

impl rosidl_runtime_rs::Message for Pwm {
  type RmwMsg = super::msg::rmw::Pwm;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        pwm_l: msg.pwm_l,
        pwm_r: msg.pwm_r,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      pwm_l: msg.pwm_l,
      pwm_r: msg.pwm_r,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      pwm_l: msg.pwm_l,
      pwm_r: msg.pwm_r,
    }
  }
}


// Corresponds to waypoint_navigation__msg__EstimatedTwist

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct EstimatedTwist {

    // This member is not documented.
    #[allow(missing_docs)]
    pub est_twist: geometry_msgs::msg::TwistStamped,

}



impl Default for EstimatedTwist {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::EstimatedTwist::default())
  }
}

impl rosidl_runtime_rs::Message for EstimatedTwist {
  type RmwMsg = super::msg::rmw::EstimatedTwist;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        est_twist: geometry_msgs::msg::TwistStamped::into_rmw_message(std::borrow::Cow::Owned(msg.est_twist)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        est_twist: geometry_msgs::msg::TwistStamped::into_rmw_message(std::borrow::Cow::Borrowed(&msg.est_twist)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      est_twist: geometry_msgs::msg::TwistStamped::from_rmw_message(msg.est_twist),
    }
  }
}


// Corresponds to waypoint_navigation__msg__EstimatedOdom

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct EstimatedOdom {

    // This member is not documented.
    #[allow(missing_docs)]
    pub est_odom: nav_msgs::msg::Odometry,

}



impl Default for EstimatedOdom {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::EstimatedOdom::default())
  }
}

impl rosidl_runtime_rs::Message for EstimatedOdom {
  type RmwMsg = super::msg::rmw::EstimatedOdom;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        est_odom: nav_msgs::msg::Odometry::into_rmw_message(std::borrow::Cow::Owned(msg.est_odom)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        est_odom: nav_msgs::msg::Odometry::into_rmw_message(std::borrow::Cow::Borrowed(&msg.est_odom)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      est_odom: nav_msgs::msg::Odometry::from_rmw_message(msg.est_odom),
    }
  }
}


