# Turtlebot_waypoint_navigation_ManojGuha
My ROS project which uses Movebase to move turtebot to different waypoint poses

To do the simulation follow the steps:

1. Git clone this repository
2. Make sure you have already installed Navigation, Gmapping, maps, geometry2, navigation_msgs packages
3. Install the turtle3 completely with simulation, navigation ,slam, etc
4. Run catkin_make in your workspace
5. Start gazebo and open turtlebot_empty world simulation, launch turtlebot_navigation
6. Finally run turtlebot_waypoint_navigation C++ program  which is in the package 'turtlebot_custom_waypoint_navigation' using rosrun to send the goals to turtlebot and navigate continuosly
7. Link to video explanation : https://drive.google.com/file/d/1qjBJIjKzDFkbi2WbpaD5SDrbecZjXwiF/view?usp=sharing

