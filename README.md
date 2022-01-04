# Turtlebot_waypoint_navigation_ManojGuha
My ROS project which uses Movebase to move turtebot to different waypoint poses

To do the simulation follow the steps:

1. Git clone this repository
2. Make sure you have already installed Navigation, Gmapping, maps, geometry2, navigation_msgs packages
3. Run catkin_make in your workspace
4. Start gazebo and open turtlebot_empty world simulation, launch turtlebot_navigation
5. Finally run turtlebot_waypoint_navigation C++ program using rosrun to send the goals to bot and navigate continuosly

