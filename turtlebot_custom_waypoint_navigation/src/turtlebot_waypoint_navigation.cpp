#include<iostream>
#include<vector>
#include<unistd.h>

#include"ros/ros.h"
#include"move_base_msgs/MoveBaseAction.h"
#include <tf/transform_datatypes.h>
#include <actionlib/client/simple_action_client.h>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "pose_navigation_node");  //Initializing the node
    
    ros::NodeHandle waypoints_nh;      // Creating and initiating my nodehandle

    actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> waypoint_client("move_base",true);  //Creating the client for waypoint poses

    
    move_base_msgs::MoveBaseGoal waypoint_goal;     //Declaring instance of class MoveBaseGoal

    waypoint_client.waitForServer(ros::Duration(10.0));    //Waiting for the move_base server to start because sometimes server might have issues and will be slow to start

 

    //Creating a vector of waypoints
    std::vector<float> x_coor = {10.0,-10.0, -10.0, 10.0};
    std::vector<float> y_coord = {3.0, 3.0, -3.0, -3.0};
    int waypoints_count = 0;
    while (ros::ok())                 //Looping infinetely till the node is killed or shutdown request is received
    {
    waypoints_count = 0;
    while(waypoints_count<4 && ros::ok())      //setting the attributes for waypoint_goal object
    {
    waypoint_goal.target_pose.header.frame_id = "map";             // base frame
    waypoint_goal.target_pose.header.stamp = ros::Time::now();
    waypoint_goal.target_pose.pose.position.x = x_coor[waypoints_count];       //Calling the vector of poses for each destination
    waypoint_goal.target_pose.pose.position.y = y_coord[waypoints_count];
 
   //determining the Orientation from Yaw. Target angle given in assignment : 50 Degrees. So I used tf function to convert the degree to equivalent Quaternion
    tf::Quaternion rad_to_quat_based = tf::createQuaternionFromYaw(0.87);     // 50 Degress = 0.87 radians

    double angle_z = rad_to_quat_based.getZ();                 //This is the required pose of 50 degrees for robot
    ROS_INFO("The pose orientation is  %f",angle_z);


    waypoint_goal.target_pose.pose.orientation.z = angle_z;     // Converted 50 degrees to its equivalent Orientation represention in Quaternion
    waypoint_goal.target_pose.pose.orientation.w = 1.0;

    
    

    ROS_INFO("Now sending the  pose goal  [%f ,%f] to move_base server for Turtlebot navigation",x_coor[waypoints_count], y_coord[waypoints_count]);

    waypoint_client.sendGoal(waypoint_goal);           //Now I am seding the goal to move_base action server

    waypoint_client.waitForResult();                // Here the client waits for the result


    if(waypoint_client.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    {
        ROS_INFO("Reached pose [%f ,%f] successfully",x_coor[waypoints_count], y_coord[waypoints_count]); 
        waypoints_count++;
        usleep(8000000);                //Giving a delay to see the pose in Gazebo properly
    }
    else
    {
        ROS_INFO("Failed to reach pose %d",waypoints_count);
    }

    }
    }
    
}
