import pybullet as p
import time
import pybullet_data
import os
import numpy as np
from ament_index_python.packages import get_package_share_directory

def main():
    # Connect to PyBullet
    p.connect(p.GUI)  # or p.DIRECT for non-graphical version
    p.resetSimulation()
    # Set additional search path for URDF files
    p.setAdditionalSearchPath(pybullet_data.getDataPath())
    p.setGravity(0, 0, -9.81)   # everything should fall down
    p.setRealTimeSimulation(0)

    

    # Get the package path for your custom URDF
    package_share_directory = get_package_share_directory('my_pybullet_package')
    urdf_path = os.path.join(package_share_directory, 'config', 'robotic_arm.urdf')
    # Load plane and your custom robot URDF
    
    p.loadURDF("plane.urdf", [0,0,0],[0,0,0,1])
    targid = p.loadURDF(urdf_path,[0,0,0],[0,0,0,1],useFixedBase=True)
    obj_of_focus = targid

    for i in range(p.getNumJoints(targid)):
        print(p.getJointInfo(targid, i))
    
    
    for step in range(300):
        focus_position, _ = p.getBasePositionAndOrientation(targid)
        p.resetDebugVisualizerCamera(cameraDistance=1, cameraYaw=60, cameraPitch=-40, cameraTargetPosition=focus_position)
        p.stepSimulation()
        time.sleep(0.01)


    

    jointid = 4
    jtype = p.getJointInfo(targid, jointid)[2]
    jlower = p.getJointInfo(targid, jointid)[8]
    jupper = p.getJointInfo(targid, jointid)[9]
    print('jointid', jointid, 'jlower', jlower, 'jupper', jupper)


    for step in range(500):
        joint_two_targ = np.random.uniform(p.getJointInfo(targid, 2)[8], p.getJointInfo(targid, 2)[9]) # to choose the random values from the upper and lower limit of the joint
        joint_four_targ = np.random.uniform(p.getJointInfo(targid, 4)[8], p.getJointInfo(targid, 4)[9]) # to choose the random values from the upper and lower limit of the joint 
        p.setJointMotorControlArray(targid, [2,4], p.POSITION_CONTROL , targetPositions = [joint_two_targ,joint_four_targ]) # move the joint to the target position
        p.stepSimulation()
        time.sleep(0.01)
        print(p.getLinkStates(targid, [2,4])) # to get the link states
    
    
if __name__ == "__main__":
    main()
