# Turtlebot_waypoint_navigation_ManojGuha
My ROS project which uses Movebase to move turtebot to different waypoint poses

To do the simulation follow the steps:

1. Git clone this repository
2. Make sure you have already installed Navigation, Gmapping, maps, geometry2, navigation_msgs packages
3. Install the turtle3 completely with simulation, navigation ,slam, etc
4. The Turtlebot navigation parameters should be downloaded this source and set in Turtlebot navigation package.
5. Run catkin_make in your workspace
6. Start gazebo and open turtlebot_empty world simulation, launch turtlebot_navigation
7. Finally run turtlebot_waypoint_navigation C++ program  which is in the package 'turtlebot_custom_waypoint_navigation' using rosrun to send the goals to turtlebot and navigate continuosly
8. Link to video explanation : https://drive.google.com/file/d/1qjBJIjKzDFkbi2WbpaD5SDrbecZjXwiF/view?usp=sharing

