# desafio_ws

Start frist exploration:
$ roslaunch bircimatec5_map gazebo.launch
$ roslaunch explore_lite explore.launch
$ rosrun husky_desafio ball.py

Include in "explore.launch":
- gmapping.launch (pkg husky)
- move_base.launch (pkg husky)
param name="progress_timeout" value="5.0"
<param name="min_frontier_size" value="15.0"

Start second exploration:
$ roslaunch bircimatec5_map gazebo.launch
$ roslaunch husky_desafio acml.launch (to use map.yaml)
$ roslaunch ecplore_lite explore_costmap.launch
$ rosrun husky_desafio ball.py

Include in "acml.launch":
- amcl.launch (pkg husky)
- move_base.launch (pkg husky)

